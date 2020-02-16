#pragma once

namespace Eren
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0 = 0,
		Button1 = 1,
		Button2 = 2,
		Button3 = 3,
		Button4 = 4,
		Button5 = 5,
		Button6 = 6,
		Button7 = 7,

		ButtonLast = Button7,
		ButtonLeft = Button0,
		ButtonRight = Button1,
		ButtonMiddle = Button2
	} Mouse;

	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define EREN_MOUSE_BUTTON_0      ::Eren::Mouse::Button0
#define EREN_MOUSE_BUTTON_1      ::Eren::Mouse::Button1
#define EREN_MOUSE_BUTTON_2      ::Eren::Mouse::Button2
#define EREN_MOUSE_BUTTON_3      ::Eren::Mouse::Button3
#define EREN_MOUSE_BUTTON_4      ::Eren::Mouse::Button4
#define EREN_MOUSE_BUTTON_5      ::Eren::Mouse::Button5
#define EREN_MOUSE_BUTTON_6      ::Eren::Mouse::Button6
#define EREN_MOUSE_BUTTON_7      ::Eren::Mouse::Button7
#define EREN_MOUSE_BUTTON_LAST   ::Eren::Mouse::ButtonLast
#define EREN_MOUSE_BUTTON_LEFT   ::Eren::Mouse::ButtonLeft
#define EREN_MOUSE_BUTTON_RIGHT  ::Eren::Mouse::ButtonRight
#define EREN_MOUSE_BUTTON_MIDDLE ::Eren::Mouse::ButtonMiddle
