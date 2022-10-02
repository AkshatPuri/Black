#include "bpch.h"
#include "Application.h"


#include"Log.h"

#include<GLFW/glfw3.h>

namespace Black
{

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowShouldClose));

		BLACK_CORE_TRACE("{0}", e);
	
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		
		while (m_Running)
		{
			glClearColor(0, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowShouldClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}
}