#pragma once

#ifdef EREN_PLATFORM_WINDOWS
	#ifdef EREN_BUILD_DLL
		#define EREN_API __declspec(dllexport)
	#else
		#define EREN_API __declspec(dllimport)
	#endif
#else
	#error Eren only supports windows!
#endif