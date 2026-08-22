#include <Meowgine.h>
#include <imgui/imgui.h>

class MainLayer : public Meowgine::Layer
{
public:
	MainLayer()
		: Layer("Example")
	{
		
	}

	void OnUpdate() override
	{
		//MG_INFO("ExampleLayer::Update");
	}

	void OnImGuiRender() override
	{
		ImGui::Begin("Test");

		ImGui::Text("GPU info:");
		ImGui::GLVen(); // Display vendor info

		if (ImGui::Button("Click")) {
			ImGui::OpenPopup("sample text");
		}
			
			

		if (ImGui::BeginPopup("sample text"))
		{
			ImGui::Text("Hello world");

			if (ImGui::Button("Close"))
				ImGui::CloseCurrentPopup();

			ImGui::EndPopup();
		}

		ImGui::End();
	}

	void OnEvent(Meowgine::Event& event) override
	{
		Meowgine::EventDispatcher dispatcher(event);

		dispatcher.Dispatch<Meowgine::MouseButtonPressedEvent>(MG_BIND_EVENT(MainLayer::LogMouse));
	}

	bool LogMouse(Meowgine::MouseButtonPressedEvent& event) {

		int button = event.GetMouseButton();

		if (button == 1) {
			MG_TRACE("Right mouse button pressed");
		}
		else {
			MG_TRACE("Left mouse button pressed");
		}

		return true;
	}
};

class Sandbox : public Meowgine::Application {
public:
	Sandbox() {
		PushLayer(new MainLayer());
	}
	
	~Sandbox() {

	}
};

Meowgine::Application* Meowgine::CreateApplication() {
	return new Sandbox();
}