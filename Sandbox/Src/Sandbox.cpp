#pragma once

#include <Black.h>

class Sandbox : public Black::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Black::ImGuiLayer());
	}

	~Sandbox()
	{

	}



};

Black::Application* Black:: CreateApplication()
{
	return new Sandbox();
}