#pragma once

#include "Meowgine/Layer.h"
#include "Meowgine/Events/KeyEvent.h"
#include "Meowgine/Events/MouseEvent.h"
#include "Meowgine/Events/ApplicationEvent.h"

namespace Meowgine
{
	class MG_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();


		virtual void OnAttach() override ;
		virtual void OnDetach() override ;
		virtual void OnImGuiRender();

		void Begin();
		void End();
	private:

		float m_Time = 0.0f;
	};
}
namespace ImGui
{
	void GLVen();
}