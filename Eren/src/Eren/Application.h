#pragma once

#include "Core.h"

namespace Eren {

	class ERN_API Application
	{
	public:
		Application();
		virtual ~Application();
		void run();

	};

	// needs to be implemented in the client
	Application* createApplication();
}

