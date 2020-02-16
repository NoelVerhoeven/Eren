#include "erenpch.h"
#include "Application.h"
#include "Eren/Events/ApplicationEvent.h"
#include "Eren/Core/Log.h"

namespace Eren {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::run() {
		WindowResizeEvent e(1200, 720);
		EREN_TRACE(e);
		while (true);
	}
}
