#pragma once

#include <Black.h>
#include "imgui/imgui.h"

class ExampleLayer : public Black::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Black::Input::IsKeyPressed(BLACK_KEY_TAB))
			BLACK_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Black::Event& event) override
	{
		if (event.GetEventType() == Black::EventType::KeyPressed)
		{
			Black::KeyPressedEvent& e = (Black::KeyPressedEvent&)event;
			if (e.GetKeyCode() == BLACK_KEY_TAB)
				BLACK_TRACE("Tab key is pressed (event)!");
			BLACK_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Black::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Black::Application* Black::CreateApplication()
{
	return new Sandbox();
}