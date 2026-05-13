#include "mgpch.h"
#include "OpenGLVertexArray.h"
#include "glad/glad.h"

namespace Meowgine
{

	static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
	{
		switch (type)
		{
			case Meowgine::ShaderDataType::Float:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Float2:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Float3:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Float4:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Mat3:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Mat4:	return GL_FLOAT;
			case Meowgine::ShaderDataType::Int:		return GL_INT;
			case Meowgine::ShaderDataType::Int2:	return GL_INT;
			case Meowgine::ShaderDataType::Int3:	return GL_INT;
			case Meowgine::ShaderDataType::Int4:	return GL_INT;
			case Meowgine::ShaderDataType::Bool:	return GL_BOOL;
		}
		// crash the shit out of it if it was used wrong
		MG_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;

	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}


	OpenGLVertexArray::~OpenGLVertexArray() {
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{
		MG_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex buffer doesnt have a layout");

		glBindVertexArray(m_RendererID);
		vertexBuffer->Bind();
		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.GetComponentCount(),
				ShaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)element.Offset);
			index++;
		}
		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->Bind();
		m_IndexBuffer = indexBuffer;
	}

	void OpenGLVertexArray::Bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

}