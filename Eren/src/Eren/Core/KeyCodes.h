#pragma once

namespace Eren
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space = 32,
		Apostrophe = 39, /* ' */
		Comma = 44, /* , */
		Minus = 45, /* - */
		Period = 46, /* . */
		Slash = 47, /* / */

		D0 = 48, /* 0 */
		D1 = 49, /* 1 */
		D2 = 50, /* 2 */
		D3 = 51, /* 3 */
		D4 = 52, /* 4 */
		D5 = 53, /* 5 */
		D6 = 54, /* 6 */
		D7 = 55, /* 7 */
		D8 = 56, /* 8 */
		D9 = 57, /* 9 */

		Semicolon = 59, /* ; */
		Equal = 61, /* = */

		A = 65,
		B = 66,
		C = 67,
		D = 68,
		E = 69,
		F = 70,
		G = 71,
		H = 72,
		I = 73,
		J = 74,
		K = 75,
		L = 76,
		M = 77,
		N = 78,
		O = 79,
		P = 80,
		Q = 81,
		R = 82,
		S = 83,
		T = 84,
		U = 85,
		V = 86,
		W = 87,
		X = 88,
		Y = 89,
		Z = 90,

		LeftBracket = 91,  /* [ */
		Backslash = 92,  /* \ */
		RightBracket = 93,  /* ] */
		GraveAccent = 96,  /* ` */

		World1 = 161, /* non-US #1 */
		World2 = 162, /* non-US #2 */

		/* Function keys */
		Escape = 256,
		Enter = 257,
		Tab = 258,
		Backspace = 259,
		Insert = 260,
		Delete = 261,
		Right = 262,
		Left = 263,
		Down = 264,
		Up = 265,
		PageUp = 266,
		PageDown = 267,
		Home = 268,
		End = 269,
		CapsLock = 280,
		ScrollLock = 281,
		NumLock = 282,
		PrintScreen = 283,
		Pause = 284,
		F1 = 290,
		F2 = 291,
		F3 = 292,
		F4 = 293,
		F5 = 294,
		F6 = 295,
		F7 = 296,
		F8 = 297,
		F9 = 298,
		F10 = 299,
		F11 = 300,
		F12 = 301,
		F13 = 302,
		F14 = 303,
		F15 = 304,
		F16 = 305,
		F17 = 306,
		F18 = 307,
		F19 = 308,
		F20 = 309,
		F21 = 310,
		F22 = 311,
		F23 = 312,
		F24 = 313,
		F25 = 314,

		/* Keypad */
		KP0 = 320,
		KP1 = 321,
		KP2 = 322,
		KP3 = 323,
		KP4 = 324,
		KP5 = 325,
		KP6 = 326,
		KP7 = 327,
		KP8 = 328,
		KP9 = 329,
		KPDecimal = 330,
		KPDivide = 331,
		KPMultiply = 332,
		KPSubtract = 333,
		KPAdd = 334,
		KPEnter = 335,
		KPEqual = 336,

		LeftShift = 340,
		LeftControl = 341,
		LeftAlt = 342,
		LeftSuper = 343,
		RightShift = 344,
		RightControl = 345,
		RightAlt = 346,
		RightSuper = 347,
		Menu = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define EREN_KEY_SPACE           ::Eren::Key::Space
#define EREN_KEY_APOSTROPHE      ::Eren::Key::Apostrophe    /* ' */
#define EREN_KEY_COMMA           ::Eren::Key::Comma         /* , */
#define EREN_KEY_MINUS           ::Eren::Key::Minus         /* - */
#define EREN_KEY_PERIOD          ::Eren::Key::Period        /* . */
#define EREN_KEY_SLASH           ::Eren::Key::Slash         /* / */
#define EREN_KEY_0               ::Eren::Key::D0
#define EREN_KEY_1               ::Eren::Key::D1
#define EREN_KEY_2               ::Eren::Key::D2
#define EREN_KEY_3               ::Eren::Key::D3
#define EREN_KEY_4               ::Eren::Key::D4
#define EREN_KEY_5               ::Eren::Key::D5
#define EREN_KEY_6               ::Eren::Key::D6
#define EREN_KEY_7               ::Eren::Key::D7
#define EREN_KEY_8               ::Eren::Key::D8
#define EREN_KEY_9               ::Eren::Key::D9
#define EREN_KEY_SEMICOLON       ::Eren::Key::Semicolon     /* ; */
#define EREN_KEY_EQUAL           ::Eren::Key::Equal         /* = */
#define EREN_KEY_A               ::Eren::Key::A
#define EREN_KEY_B               ::Eren::Key::B
#define EREN_KEY_C               ::Eren::Key::C
#define EREN_KEY_D               ::Eren::Key::D
#define EREN_KEY_E               ::Eren::Key::E
#define EREN_KEY_F               ::Eren::Key::F
#define EREN_KEY_G               ::Eren::Key::G
#define EREN_KEY_H               ::Eren::Key::H
#define EREN_KEY_I               ::Eren::Key::I
#define EREN_KEY_J               ::Eren::Key::J
#define EREN_KEY_K               ::Eren::Key::K
#define EREN_KEY_L               ::Eren::Key::L
#define EREN_KEY_M               ::Eren::Key::M
#define EREN_KEY_N               ::Eren::Key::N
#define EREN_KEY_O               ::Eren::Key::O
#define EREN_KEY_P               ::Eren::Key::P
#define EREN_KEY_Q               ::Eren::Key::Q
#define EREN_KEY_R               ::Eren::Key::R
#define EREN_KEY_S               ::Eren::Key::S
#define EREN_KEY_T               ::Eren::Key::T
#define EREN_KEY_U               ::Eren::Key::U
#define EREN_KEY_V               ::Eren::Key::V
#define EREN_KEY_W               ::Eren::Key::W
#define EREN_KEY_X               ::Eren::Key::X
#define EREN_KEY_Y               ::Eren::Key::Y
#define EREN_KEY_Z               ::Eren::Key::Z
#define EREN_KEY_LEFT_BRACKET    ::Eren::Key::LeftBracket   /* [ */
#define EREN_KEY_BACKSLASH       ::Eren::Key::Backslash     /* \ */
#define EREN_KEY_RIGHT_BRACKET   ::Eren::Key::RightBracket  /* ] */
#define EREN_KEY_GRAVE_ACCENT    ::Eren::Key::GraveAccent   /* ` */
#define EREN_KEY_WORLD_1         ::Eren::Key::World1        /* non-US #1 */
#define EREN_KEY_WORLD_2         ::Eren::Key::World2        /* non-US #2 */

/* Function keys */
#define EREN_KEY_ESCAPE          ::Eren::Key::Escape
#define EREN_KEY_ENTER           ::Eren::Key::Enter
#define EREN_KEY_TAB             ::Eren::Key::Tab
#define EREN_KEY_BACKSPACE       ::Eren::Key::Backspace
#define EREN_KEY_INSERT          ::Eren::Key::Insert
#define EREN_KEY_DELETE          ::Eren::Key::Delete
#define EREN_KEY_RIGHT           ::Eren::Key::Right
#define EREN_KEY_LEFT            ::Eren::Key::Left
#define EREN_KEY_DOWN            ::Eren::Key::Down
#define EREN_KEY_UP              ::Eren::Key::Up
#define EREN_KEY_PAGE_UP         ::Eren::Key::PageUp
#define EREN_KEY_PAGE_DOWN       ::Eren::Key::PageDown
#define EREN_KEY_HOME            ::Eren::Key::Home
#define EREN_KEY_END             ::Eren::Key::End
#define EREN_KEY_CAPS_LOCK       ::Eren::Key::CapsLock
#define EREN_KEY_SCROLL_LOCK     ::Eren::Key::ScrollLock
#define EREN_KEY_NUM_LOCK        ::Eren::Key::NumLock
#define EREN_KEY_PRINT_SCREEN    ::Eren::Key::PrintScreen
#define EREN_KEY_PAUSE           ::Eren::Key::Pause
#define EREN_KEY_F1              ::Eren::Key::F1
#define EREN_KEY_F2              ::Eren::Key::F2
#define EREN_KEY_F3              ::Eren::Key::F3
#define EREN_KEY_F4              ::Eren::Key::F4
#define EREN_KEY_F5              ::Eren::Key::F5
#define EREN_KEY_F6              ::Eren::Key::F6
#define EREN_KEY_F7              ::Eren::Key::F7
#define EREN_KEY_F8              ::Eren::Key::F8
#define EREN_KEY_F9              ::Eren::Key::F9
#define EREN_KEY_F10             ::Eren::Key::F10
#define EREN_KEY_F11             ::Eren::Key::F11
#define EREN_KEY_F12             ::Eren::Key::F12
#define EREN_KEY_F13             ::Eren::Key::F13
#define EREN_KEY_F14             ::Eren::Key::F14
#define EREN_KEY_F15             ::Eren::Key::F15
#define EREN_KEY_F16             ::Eren::Key::F16
#define EREN_KEY_F17             ::Eren::Key::F17
#define EREN_KEY_F18             ::Eren::Key::F18
#define EREN_KEY_F19             ::Eren::Key::F19
#define EREN_KEY_F20             ::Eren::Key::F20
#define EREN_KEY_F21             ::Eren::Key::F21
#define EREN_KEY_F22             ::Eren::Key::F22
#define EREN_KEY_F23             ::Eren::Key::F23
#define EREN_KEY_F24             ::Eren::Key::F24
#define EREN_KEY_F25             ::Eren::Key::F25

/* Keypad */
#define EREN_KEY_KP_0            ::Eren::Key::KP0
#define EREN_KEY_KP_1            ::Eren::Key::KP1
#define EREN_KEY_KP_2            ::Eren::Key::KP2
#define EREN_KEY_KP_3            ::Eren::Key::KP3
#define EREN_KEY_KP_4            ::Eren::Key::KP4
#define EREN_KEY_KP_5            ::Eren::Key::KP5
#define EREN_KEY_KP_6            ::Eren::Key::KP6
#define EREN_KEY_KP_7            ::Eren::Key::KP7
#define EREN_KEY_KP_8            ::Eren::Key::KP8
#define EREN_KEY_KP_9            ::Eren::Key::KP9
#define EREN_KEY_KP_DECIMAL      ::Eren::Key::KPDecimal
#define EREN_KEY_KP_DIVIDE       ::Eren::Key::KPDivide
#define EREN_KEY_KP_MULTIPLY     ::Eren::Key::KPMultiply
#define EREN_KEY_KP_SUBTRACT     ::Eren::Key::KPSubtract
#define EREN_KEY_KP_ADD          ::Eren::Key::KPAdd
#define EREN_KEY_KP_ENTER        ::Eren::Key::KPEnter
#define EREN_KEY_KP_EQUAL        ::Eren::Key::KPEqual

#define EREN_KEY_LEFT_SHIFT      ::Eren::Key::LeftShift
#define EREN_KEY_LEFT_CONTROL    ::Eren::Key::LeftControl
#define EREN_KEY_LEFT_ALT        ::Eren::Key::LeftAlt
#define EREN_KEY_LEFT_SUPER      ::Eren::Key::LeftSuper
#define EREN_KEY_RIGHT_SHIFT     ::Eren::Key::RightShift
#define EREN_KEY_RIGHT_CONTROL   ::Eren::Key::RightControl
#define EREN_KEY_RIGHT_ALT       ::Eren::Key::RightAlt
#define EREN_KEY_RIGHT_SUPER     ::Eren::Key::RightSuper
#define EREN_KEY_MENU            ::Eren::Key::Menu
