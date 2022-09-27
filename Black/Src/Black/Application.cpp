#include "bpch.h"
#include "Application.h"
#include "Black/Events/ApplicationEvent.h"
#include"Log.h"

namespace Black
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{

		WindowResizeEvent e(1280, 720);
		BLACK_TRACE(e);
		while (true);
	}
}