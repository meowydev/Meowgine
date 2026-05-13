#include "mgpch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Input.h" 
#include "Meowgine/Renderer/Renderer.h"

namespace Meowgine {
#define BIND_EVENT_FUNC(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application* Application::s_Instance = nullptr;
	Application::Application() {
		MG_CORE_ASSERT(!s_Instance, "Application already exists");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FUNC(OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer); 

		m_VertexArray.reset(VertexArray::Create());

		float verticies[3 * 7] = {
			//X     Y     Z     R     G     B     A
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Bottom left
			 0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, // Bottom right
			 0.0f,	0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f  // Top
		};


		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(verticies, sizeof(verticies)));
		BufferLayout layout = {
			{ ShaderDataType::Float3, "a_Position"},
			{ ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		unsigned int indices[3] = {
			0,1,2
		};
		std::shared_ptr<IndexBuffer> indexBuffer;

		indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(VertexArray::Create());

		float squareVerticies[3 * 4] = {
			//X     Y     Z    
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.5f,	0.5f, 0.0f,
			 -0.5f,	0.5f, 0.0f
		};

		std::shared_ptr<VertexBuffer> m_SquareVB;
		m_SquareVB.reset(VertexBuffer::Create(squareVerticies, sizeof(squareVerticies)));

		m_SquareVB->SetLayout({
			{ ShaderDataType::Float3, "a_Position"}
		});
		m_SquareVA->AddVertexBuffer(m_SquareVB);


		unsigned int SquareIndices[6] = {
			0,1,2,2,3,0
		};
		std::shared_ptr<IndexBuffer> m_SquareIB;
		m_SquareIB.reset(IndexBuffer::Create(SquareIndices, sizeof(SquareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(m_SquareIB);

		std::string vertexSrc = R"(
		#version 330 core
		
		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;
		
		
		out vec3 v_Position;
		out vec4 v_Color;
		
		void main()
		{
			v_Position = a_Position;
			v_Color = a_Color;
			gl_Position = vec4(a_Position,1.0);
		}
		
		)";

		std::string fragmentSrc = R"(
		#version 330 core
		
		layout(location = 0) out vec4 color;
		
		in vec3 v_Position;
		in vec4 v_Color;
		
		void main()
		{
			color = vec4(v_Position * 0.5 + 0.5,1.0);
			color = v_Color;
		}
		
		)";

		m_Shader.reset(new Shader(vertexSrc,fragmentSrc));

		std::string BlueShaderVertexSrc = R"(
		#version 330 core
		
		layout(location = 0) in vec3 a_Position;
		
		
		out vec3 v_Position;
		
		void main()
		{
			v_Position = a_Position;
			gl_Position = vec4(a_Position,1.0);
		}
		
		)";

		std::string BlueShaderFragmentSrc = R"(
		#version 330 core
		
		layout(location = 0) out vec4 color;
		
		in vec3 v_Position;
		
		void main()
		{
			color = vec4(0.2,0.3,0.8,1.0);
		}
		
		)";

		m_BlueShader.reset(new Shader(BlueShaderVertexSrc, BlueShaderFragmentSrc));
	}

	Application::~Application() {

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNC(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	
	void Application::Run() {
		while (m_Running)
		{
			RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			RenderCommand::Clear();

			Renderer::BeginScene();
			
			m_BlueShader->Bind();
			Renderer::Submit(m_SquareVA);

			m_Shader->Bind();
			Renderer::Submit(m_VertexArray);

			Renderer::EndScene();

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_ImGuiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImGuiLayer->End();

			m_Window->OnUpdate();
		}
	}

	// Important event!
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	
}