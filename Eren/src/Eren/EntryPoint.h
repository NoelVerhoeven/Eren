#pragma once
#include "Application.h"

#ifdef ERN_PLATFORM_WINDOWS

extern Eren::Application* Eren::createApplication();
	
int main(int argc, char** argv) {
	printf("Eren Engine\n");
	auto app = Eren::createApplication();
	app->run();
	delete app;
}

#else
#error Eren only supports windows!
#endif