#include "erenpch.h"
#include "Platform/Windows/WindowsWindow.h"

#include "Eren/Core/Input.h"

#include "Eren/Events/ApplicationEvent.h"
#include "Eren/Events/MouseEvent.h"
#include "Eren/Events/KeyEvent.h"

#include "GLFW/glfw3.h"
//#include "Eren/Renderer/Renderer.h"

//#include "Platform/OpenGL/OpenGLContext.h"

namespace Eren {

	static uint8_t smGLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description) {
		EREN_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		//EREN_PROFILE_FUNCTION();

		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		//EREN_PROFILE_FUNCTION();

		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props) {
		//EREN_PROFILE_FUNCTION();

		mData.title = props.Title;
		mData.width = props.Width;
		mData.height = props.Height;

		EREN_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (smGLFWWindowCount == 0)	{
			//EREN_PROFILE_SCOPE("glfwinit");
			int success = glfwInit();
			EREN_CORE_ASSERT(success, "Could not intialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		{
			//EREN_PROFILE_SCOPE("glfwCreateWindow");
#if defined(EREN_DEBUG)
			//if (Renderer::GetAPI() == RendererAPI::API::OpenGL)
				//glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
			mWindow = glfwCreateWindow((int)props.Width, (int)props.Height, mData.title.c_str(), nullptr, nullptr);
			++smGLFWWindowCount;
		}

		//mContext = GraphicsContext::create(mWindow);
		//mContext->init();

		glfwSetWindowUserPointer(mWindow, &mData);
		setVSync(true);

		// Set GLFW callbacks
		glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.width = width;
				data.height = height;

				WindowResizeEvent event(width, height);
				data.eventCallback(event);
			});

		glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.eventCallback(event);
			});

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)	{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(static_cast<KeyCode>(key), 0);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(static_cast<KeyCode>(key));
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(static_cast<KeyCode>(key), 1);
					data.eventCallback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(mWindow, [](GLFWwindow* window, unsigned int keycode) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(static_cast<KeyCode>(keycode));
				data.eventCallback(event);
			});

		glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)	{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(static_cast<MouseCode>(button));
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
					data.eventCallback(event);
				}
				}
			});

		glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xOffset, double yOffset) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.eventCallback(event);
			});

		glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xPos, double yPos) {
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.eventCallback(event);
			});
	}

	void WindowsWindow::shutdown() {
		//EREN_PROFILE_FUNCTION();

		glfwDestroyWindow(mWindow);
		--smGLFWWindowCount;

		if (smGLFWWindowCount == 0) {
			glfwTerminate();
		}
	}

	void WindowsWindow::onUpdate() {
		//EREN_PROFILE_FUNCTION();

		glfwPollEvents();
		//mContext->SwapBuffers();
	}

	void WindowsWindow::setVSync(bool enabled) {
		//EREN_PROFILE_FUNCTION();

		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		mData.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return mData.vSync;
	}

}
