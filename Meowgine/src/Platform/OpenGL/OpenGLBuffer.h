#pragma once

#include "Meowgine/Renderer/Buffer.h"

namespace Meowgine
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* verticies, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void SetLayout(const BufferLayout& layout) override
		{
			m_Layout = layout;
		}
		virtual const BufferLayout& GetLayout() const override
		{
			return m_Layout;
		}

		virtual void Bind() const override;
		virtual void Unbind() const override;
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
		virtual uint32_t GetCount() const { return m_Count; }
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}