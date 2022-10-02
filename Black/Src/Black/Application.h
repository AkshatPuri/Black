#pragma once
#include "Core.h"
#include"Window.h"
#include"Events/Event.h"
#include"Events/ApplicationEvent.h"
namespace Black 
{
	class BLACKAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowShouldClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;


	};


	Application* CreateApplication();
}

