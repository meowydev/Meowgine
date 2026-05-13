#include <mgpch.h>
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"
namespace Meowgine {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}