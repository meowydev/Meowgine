#include "mgpch.h"
#include "OpenGLContext.h"
#include "GLFW/glfw3.h"
#include "glad/glad.h"
#include "GL/GL.h"

namespace Meowgine
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle) :
		m_windowHandle(windowHandle)
	{
		MG_CORE_ASSERT(windowHandle, "WindowHandle is null")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_windowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		MG_CORE_ASSERT(status, "Failed to load GLAD");

		MG_CORE_INFO("GPU Found:");
		MG_CORE_INFO("OpenGL Renderer: {0}", glGetString(GL_RENDERER));
		MG_CORE_INFO("OpenGL Vendor: {0}", glGetString(GL_VENDOR));
		MG_CORE_INFO("OpenGL Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_windowHandle);
	}

}