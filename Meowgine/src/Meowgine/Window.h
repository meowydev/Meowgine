#pragma once

#include "mgpch.h"
#include "Meowgine/Core.h"
#include "Meowgine/Events/Event.h"

namespace Meowgine
{
	struct WindowInst
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowInst(const std::string& title = "Meowgine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title),Width(width),Height(height)
		{ }
	};

	class MG_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowInst& props = WindowInst());
	};
}