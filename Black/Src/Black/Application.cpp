#include "bpch.h"
#include "Application.h"

#include"Log.h"
#include<glad/glad.h>
#include <glfw/glfw3.h>
namespace Black
{

#define BIND_EVENT_FN(x) std::bind(&Application::x,this,std::placeholders::_1)
	
	 Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BLACK_CORE_ASSERT(!s_Instance, "Application already excists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());	
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		m_ImguiLayer = new ImGuiLayer();
		PushOverlay(m_ImguiLayer);
	}


	

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowShouldClose));

		BLACK_CORE_TRACE("{0}", e);

		for (auto it = m_LayerStack.end(); it !=m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);

			if (e.Handled)
				break;
		}

	}
	

	void Application::Run()
	{

		
		while (m_Running)
		{
			glClearColor(0.0f, 0.8f, 0.9f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			float time = (float)glfwGetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate(timestep);

			m_ImguiLayer->Begin();
			for (Layer* layer : m_LayerStack)
				layer->OnImGuiRender();
			m_ImguiLayer->End();

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowShouldClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return false;
	}
}