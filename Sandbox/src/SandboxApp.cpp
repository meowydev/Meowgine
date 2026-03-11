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
		ImGui::Text("hi");
		ImGui::GLVen();
		ImGui::End();

		ImGui::Begin("Another testing window");
		if (ImGui::Button("Click Me")) {
			ImGui::OpenPopup("helo");
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