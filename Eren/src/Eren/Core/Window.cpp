#include "erenpch.h"
#include "Eren/Core/Window.h"

#ifdef EREN_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Eren {

	Scope<Window> Window::create(const WindowProps& props) {
#ifdef EREN_PLATFORM_WINDOWS
		return createScope<WindowsWindow>(props);
#else
		EREN_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}