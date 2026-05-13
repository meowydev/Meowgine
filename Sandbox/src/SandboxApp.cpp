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
		ImGui::GLVen();
		if (ImGui::Button("Click me!")) {
			MG_INFO("Click me was clicked");
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