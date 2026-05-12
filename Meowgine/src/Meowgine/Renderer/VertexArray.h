#pragma once

#include <memory>
#include "Meowgine/Renderer/Buffer.h"

namespace Meowgine {
	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
		virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		static VertexArray* Create();
	};
}