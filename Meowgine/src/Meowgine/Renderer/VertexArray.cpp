#include "mgpch.h"
#include "VertexArray.h"
#include "Renderer.h"

namespace Meowgine {

	void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{

	}

	void VertexArray::AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{

	}

	void VertexArray::Bind() const
	{

	}

	void VertexArray::Unbind() const
	{

	}

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::None: MG_CORE_ASSERT(false, "RendererAPI::None is not allowed"); return nullptr;
		case RendererAPI::OpenGL: return new OpenGLVertexArray();
		}

		MG_CORE_ASSERT(false, "Unknown RendererAPI");

		return nullptr;
	}

}