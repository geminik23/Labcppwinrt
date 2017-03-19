#include "pch.h"

#include "InheritedPage.h"
#include <wrl/wrappers/corewrappers.h>

using namespace winrt;
using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::Storage;

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ::ABI::Windows;
using namespace ::ABI::Windows::Foundation;


winrt::Windows::Foundation::IInspectable Convert(::IInspectable * raw)
{
	winrt::Windows::Foundation::IInspectable value;
	winrt::copy_from_abi(value, reinterpret_cast<winrt::ABI::Windows::Foundation::IInspectable *>(raw));
	return value;
}

class App : public ApplicationT<App>
{
	ApplicationDataContainer m_localsettings{ nullptr };
	CoreDispatcher m_dispatcher{ nullptr };

public:

	void OnSuspending(winrt::Windows::Foundation::IInspectable const& sender,
					  winrt::Windows::ApplicationModel::SuspendingEventArgs const& e)
	{
		auto deferral = e.SuspendingOperation().GetDeferral();

		/* TODO store states  with m_localsettings */

		deferral.Complete();
	}
	void OnResuming(winrt::Windows::Foundation::IInspectable const& sender,
					winrt::Windows::Foundation::IInspectable const& args)
	{
		/* TODO restore states */
	}

	void OnLaunched(LaunchActivatedEventArgs const& arg)
	{
		auto window = Window::Current();

		m_localsettings = ApplicationData::Current().LocalSettings();
		m_dispatcher = window.Dispatcher();

		this->Suspending(SuspendingEventHandler(this, &App::OnSuspending));
		this->Resuming(winrt::Windows::Foundation::EventHandler<winrt::Windows::Foundation::IInspectable>(this, &App::OnResuming));



		Frame rootFrame = (Window::Current().Content()) ?
			Window::Current().Content().try_as<Frame>() : nullptr;

		if(rootFrame == nullptr)
		{
			rootFrame = Frame();

			/* check prev state */
			if(arg.PreviousExecutionState() == ApplicationExecutionState::NotRunning ||
			   arg.PreviousExecutionState() == ApplicationExecutionState::Terminated)
			{
				// TODO Load state from previously suspended application
			} else if(arg.PreviousExecutionState() == ApplicationExecutionState::ClosedByUser)
			{
				// TODO delete state
			}
			ComPtr<::ABI::Testing::IInheritedPage> ipage;
			::ABI::Testing::InheritedFactory factory;
			HRESULT result = factory.ActivateInstance(&ipage);

			ThrowIfFailed(result);

			auto iipage = Convert(ipage.Get());
			auto page = iipage.as<Page>();
			TextBlock txt;
			txt.Text(L"Hello");
			page.Content(txt);


			rootFrame.Content(page);

			window.Content(rootFrame);
		}

		if(rootFrame.Content() == nullptr)
		{
			//if(!rootFrame.Navigate())
		}

		window.Activate();
	}
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	Application::Start([](auto&&) {make<App>(); });
}