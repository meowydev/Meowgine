#include "mgpch.h"
#include "Buffer.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Meowgine
{

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: MG_CORE_ASSERT(false, "RendererAPI::None is not allowed"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexBuffer(vertices, size);
		}

		MG_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: MG_CORE_ASSERT(false, "RendererAPI::None is not allowed"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLIndexBuffer(indices, count);
		}

		MG_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}

}