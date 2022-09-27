#pragma once
#include "Core.h"
namespace Black {
	class BLACKAPI Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};


	Black::Application* CreateApplication();
}

