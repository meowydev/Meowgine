#pragma once
//ignore those errors its just visual studio being stupid
extern Meowgine::Application* Meowgine::CreateApplication();

#ifdef MG_WINDOWS
	int main(int argc, char** argv) {
		Meowgine::Log::Init();
		MG_CORE_WARN("Welcome to Meowgine!");
		auto app = Meowgine::CreateApplication();
		app->Run();
		delete app;
	}
#endif