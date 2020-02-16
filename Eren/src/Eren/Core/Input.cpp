#include "erenpch.h"
#include "Input.h"

#ifdef EREN_PLATFORM_WINDOWS
//#include "Platform/Windows/WindowsInput.h"
#endif

namespace Eren {

	Scope<Input> Input::smInstance = Input::create();

	Scope<Input> Input::create() {
#ifdef EREN_PLATFORM_WINDOWS
		// return createScope<WindowsInput>();
#else
		EREN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
		return nullptr;
	}
}