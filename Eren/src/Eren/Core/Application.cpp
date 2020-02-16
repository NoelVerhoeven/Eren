#include "erenpch.h"
#include "Application.h"

#include "Eren/Core/Log.h"

namespace Eren {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

	Application::Application() {
		mWindow = Scope<Window>(Window::create());
		mWindow->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application() {

	}

	void Application::run() {
		while (mRunning) {
			mWindow->onUpdate();
		}
	}

	void Application::onEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
		EREN_CORE_TRACE("{0}",e);
	}

	bool Application::onWindowClose(WindowCloseEvent e) {
		mRunning = false;
		return true;
	}

}
