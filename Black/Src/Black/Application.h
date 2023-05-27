#pragma once
#include "Core.h"
#include "Window.h"
#include "Black/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Black/ImGui/ImGuiLayer.h"

namespace Black
{
	class BLACKAPI Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void Run();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static inline Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowShouldClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImguiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();
}

