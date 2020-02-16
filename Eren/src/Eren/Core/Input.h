#pragma once

#include "Core.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Eren {

	class Input	{
	protected:
		Input() = default;
	public:
		Input(const Input&) = delete;
		Input& operator=(const Input&) = delete;

		inline static bool isKeyPressed(KeyCode key) { return smInstance->isKeyPressedImpl(key); }

		inline static bool isMouseButtonPressed(MouseCode button) { return smInstance->isMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return smInstance->getMousePositionImpl(); }
		inline static float getMouseX() { return smInstance->getMouseXImpl(); }
		inline static float getMouseY() { return smInstance->getMouseYImpl(); }

		static Scope<Input> create();
	protected:
		virtual bool isKeyPressedImpl(KeyCode key) = 0;

		virtual bool isMouseButtonPressedImpl(MouseCode button) = 0;
		virtual std::pair<float, float> getMousePositionImpl() = 0;
		virtual float getMouseXImpl() = 0;
		virtual float getMouseYImpl() = 0;
	private:
		static Scope<Input> smInstance;
	};
}
