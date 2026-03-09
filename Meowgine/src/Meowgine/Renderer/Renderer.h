#pragma once

namespace Meowgine
{
	enum class RendererAPI  // No vulkan!
	{
		None = 0, 
		OpenGL = 1
	};

	class Renderer
	{
	public:
		inline static RendererAPI GetAPI() { return s_RendererAPI; }
	private:
		static RendererAPI s_RendererAPI;
	};

}
