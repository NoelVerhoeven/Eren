#pragma once

#include "Event.h"

namespace Eren {

	class KeyEvent : public Event {
	
	public:
		inline int getKeyCode() const { return mKeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		KeyEvent(int keyCode) : mKeyCode(keyCode) {}

		int mKeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(KeyCode keycode, int repeatCount)
			: KeyEvent(keycode), mRepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return mRepeatCount; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeyCode << " (" << mRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int mRepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(KeyCode keycode) : KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};


}