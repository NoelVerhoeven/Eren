#pragma once

#include "Application.h"


#ifdef EREN_PLATFORM_WINDOWS

extern Eren::Application* Eren::createApplication();
	
int main(int argc, char** argv) {
	
	Eren::Log::init();
	EREN_CORE_WARN("Initialized Log.");
	EREN_INFO("Initialized Log.");

	auto app = Eren::createApplication();
	app->run();
	delete app;
}

#else
#error Eren only supports windows!
#endif