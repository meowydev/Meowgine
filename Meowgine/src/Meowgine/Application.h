#pragma once
#include "mgpch.h"
#include "Meowgine/Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Meowgine/LayerStack.h"
#include "Meowgine/ImGui/ImGuiLayer.h"

#include "Meowgine/Renderer/Shader.h"
#include "Meowgine/Renderer/Buffer.h"
#include "Meowgine/Renderer/VertexArray.h"

namespace Meowgine {
	class MG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_Instance; };
		inline Window& GetWindow() { return *m_Window; };
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;

/*		unsigned int m_VertexArray;*/
		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexBuffer> m_VertexBuffer;
		std::shared_ptr<IndexBuffer> m_IndexBuffer;
		std::shared_ptr<VertexArray> m_VertexArray;
	};

	//Client should define this
	Application* CreateApplication();
}