#include "pch.h"


using namespace winrt;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::Storage;
using namespace Windows::Foundation;


class App : public ApplicationT<App>
{
	ApplicationDataContainer m_localsettings{nullptr};
	CoreDispatcher m_dispatcher{nullptr};

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


			rootFrame.Content(/* TODO page */);

			window.Content(rootFrame);
		}

		if (rootFrame.Content() == nullptr)
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