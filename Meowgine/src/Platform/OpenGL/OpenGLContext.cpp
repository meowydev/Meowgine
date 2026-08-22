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

		bool forceCrashOldGL = false;

		if (forceCrashOldGL || !GLAD_GL_VERSION_4_1) {
			MG_CORE_ERROR("OpenGL 4.1 isn't supported");
			std::exit(MG_EXIT_OPENGLNOT41);
		}

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