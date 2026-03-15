#pragma once

namespace Meowgine
{
	struct BufferElements
	{
		std::string name;

		ShaderDataType type;

		uint32_t offset;
		uint32_t size;
	};

	class BufferLayout
	{
	public:
		inline const std::vector<BufferElements>& GetElements() const { return m_Elements; }
	private:
		std::vector<BufferElements> m_Elements;
	};

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		static VertexBuffer* Create(float* vertices, uint32_t size);

	};

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual uint32_t GetCount() const = 0;
		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}