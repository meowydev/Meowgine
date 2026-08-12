#include <Meowgine.h>
#include <imgui/imgui.h>

class ExampleLayer : public Meowgine::Layer
{
public:
	ExampleLayer()
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
		

	}
};

class Sandbox : public Meowgine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	
	~Sandbox() {

	}
};

Meowgine::Application* Meowgine::CreateApplication() {
	return new Sandbox();
}