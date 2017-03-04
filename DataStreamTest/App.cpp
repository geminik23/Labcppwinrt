#include "pch.h"
#include <string>
#include <memory>


using namespace winrt;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;

using namespace Windows::Foundation;

using namespace Windows::Networking;
using namespace Windows::Networking::Sockets;

using SocketMSGReceivedHandler = winrt::Windows::Foundation::TypedEventHandler<
	DatagramSocket, DatagramSocketMessageReceivedEventArgs>;




class Sockets
{
	DatagramSocket listener;
	DatagramSocket sender;
	bool localHost{false};
	std::wstring port;
	HostName hostname{L"127.0.0.1"};



public:
	Sockets(std::wstring const& port) :port{port}, localHost{true} {}

	Sockets(HostName host, std::wstring const& port) :hostname{host}, port{port}, localHost{false} {}

	


	~Sockets()
	{
		listener.Close();
		sender.Close();
	}

	DataWriter GetWriter() { return DataWriter(sender.OutputStream()); }

	IAsyncAction Initialize(SocketMSGReceivedHandler const& msgHandler)
	{
		listener.MessageReceived(msgHandler);

		if (localHost)
			co_await listener.BindServiceNameAsync(port);
		else
			co_await listener.BindEndpointAsync(hostname, port);
		
		//if (localHost)
		//{
		//	winrt::ppl::create_task(listener.BindServiceNameAsync(port)).then(
		//		[this](concurrency::task<void> prev) {
		//		try
		//		{
		//			prev.get();
		//			/* succeeded */
		//		} catch (winrt::hresult_error const& e)
		//		{
		//			/* error handle */
		//		}
		//	});
		//} else
		//{
		//	winrt::ppl::create_task(listener.BindEndpointAsync(hostname, port)).then(
		//		[this](concurrency::task<void> prev) {
		//		try
		//		{
		//			prev.get();
		//			/* succeeded */
		//		} catch (winrt::hresult_error const& e)
		//		{
		//			/* error handle */
		//		}
		//	});
		//}

		sender.ConnectAsync(hostname, port);
	}

};

class App : public ApplicationT<App>
{
	ApplicationDataContainer m_localsettings{nullptr};
	CoreDispatcher m_dispatcher{nullptr};

	TextBlock m_txtState;
	Page m_page;

	std::unique_ptr<::Sockets> m_socket;

public:

	void OnSuspending(Windows::Foundation::IInspectable const& sender,
					  Windows::ApplicationModel::SuspendingEventArgs const& e)
	{
		auto deferral = e.SuspendingOperation().GetDeferral();

		/* TODO store states  with m_localsettings */

		deferral.Complete();
	}
	void OnResuming(Windows::Foundation::IInspectable const& sender,
					Windows::Foundation::IInspectable const& args)
	{
		/* TODO restore states */
	}

	void OnLaunched(LaunchActivatedEventArgs const& arg)
	{
		auto window = Window::Current();

		m_localsettings = ApplicationData::Current().LocalSettings();
		m_dispatcher = window.Dispatcher();

		this->Suspending(SuspendingEventHandler(this, &App::OnSuspending));
		this->Resuming(Windows::Foundation::EventHandler<Windows::Foundation::IInspectable>(this, &App::OnResuming));



		Frame rootFrame = (Window::Current().Content()) ?
			Window::Current().Content().try_as<Frame>() : nullptr;

		if (rootFrame == nullptr)
		{
			rootFrame = Frame();

			/* check prev state */
			if (arg.PreviousExecutionState() == ApplicationExecutionState::NotRunning ||
				arg.PreviousExecutionState() == ApplicationExecutionState::Terminated)
			{
				// TODO Load state from previously suspended application
			} else if (arg.PreviousExecutionState() == ApplicationExecutionState::ClosedByUser)
			{
				// TODO delete state
			}


			m_socket = std::make_unique<::Sockets>(L"3000");
			
			

			StackPanel panel;
			Button send;
			Button conn;

			m_txtState.Text(L"None");
			conn.Content(PropertyValue::CreateString(L"Connect"));
			send.Content(PropertyValue::CreateString(L"send 'Hello'"));

			conn.Click(RoutedEventHandler([this](auto&&, auto&&) {
				this->Connect();
			}));

			send.Click(RoutedEventHandler([this](IInspectable const& sender,
												 RoutedEventArgs const& arg)
			{
				this->SendMessage();
			}));
			panel.Children().Append(m_txtState);
			panel.Children().Append(conn);
			panel.Children().Append(send);



			m_page.Content(panel);




			rootFrame.Content(m_page);

			window.Content(rootFrame);
		}

		if (rootFrame.Content() == nullptr)
		{
			//if(!rootFrame.Navigate())
		}

		window.Activate();

	}

	void Connect()
	{
		ppl::create_task(m_socket->Initialize(SocketMSGReceivedHandler(this, &App::OnMessage))).then(
			[this]() {
			this->UpdateText2State(L"Connected");
		});
	}


	void UpdateText2State(hstring msg)
	{
		auto txtState = m_txtState;
		winrt::ppl::create_task(this->m_dispatcher.RunAsync(CoreDispatcherPriority::Normal,
															DispatchedHandler([txtState, this, msg]()
		{
			txtState.Text(msg);
		})));
	}


	void OnMessage(DatagramSocket const& sender, DatagramSocketMessageReceivedEventArgs const& arg)
	{

		try{
			auto stringLength = arg.GetDataReader().ReadUInt32();
			auto receivedMsg = arg.GetDataReader().ReadString(stringLength);
			UpdateText2State(receivedMsg.c_str());

		} catch (winrt::hresult_error e)
		{
			SocketErrorStatus socketError = SocketError::GetStatus(e.code());

			if (socketError == SocketErrorStatus::ConnectionResetByPeer)
			{
			} else if (socketError != SocketErrorStatus::Unknown)
			{
			} else
			{
				throw;
			}
		}
	}


	void SendMessage()
	{
		auto msg = hstring(L"Hello");
		auto writer = this->m_socket->GetWriter();
		try
		{
			writer.WriteUInt32(msg.size());
			writer.WriteString(msg);
		} catch (hresult_error const& e) {}

		winrt::ppl::create_task(writer.StoreAsync()).then(
			[](concurrency::task<unsigned int> result) {
			try
			{
				result.get();
				OutputDebugString(L"Sending Succeeded\n");
			} catch (hresult_error const& e) {}
		});
	}
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	Application::Start([](auto&&) {make<App>(); });
}