#include "pch.h"
#include <wrl.h>
#include "../Component/Component.h"

using namespace winrt;
using namespace winrt::Windows::ApplicationModel::Activation;
using namespace winrt::Windows::UI::Core;
using namespace winrt::Windows::UI::Xaml;
using namespace winrt::Windows::UI::Xaml::Controls;
using namespace winrt::Windows::Storage;
//using namespace winrt::Windows::Foundation;


using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

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


			ComPtr<::ABI::Component::IComponent> pIComponent;
			auto result = ::Windows::Foundation::ActivateInstance(HStringReference(RuntimeClass_Component_Component).Get(),
													&pIComponent);

			if(SUCCEEDED(result))
			{
				pIComponent->SayHello(HStringReference(L"Hello").Get());
			}


			rootFrame.Content(/* TODO page */);

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