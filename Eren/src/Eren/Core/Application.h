#pragma once

#include "Core.h"
#include "Eren/Events/Event.h"
#include "Eren/Events/ApplicationEvent.h"

#include "Window.h"

namespace Eren {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		void run();
		void onEvent(Event& e);

	private:
		bool onWindowClose(WindowCloseEvent e);
		Scope<Window> mWindow;
		bool mRunning = true;
	};

	// needs to be implemented in the client
	Application* createApplication();
}

