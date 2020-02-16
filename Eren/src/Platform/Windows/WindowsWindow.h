#pragma once

#include "Eren/Core/Window.h"
//#include "Eren/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Eren {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return mData.width; }
		inline unsigned int getHeight() const override { return mData.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { mData.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const { return mWindow; }
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();

		GLFWwindow* mWindow;
		//Scope<GraphicsContext> mContext;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData mData;
	};

}