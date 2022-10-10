#pragma once
#include "Black/Core.h"
#include"Black/Events/Event.h"

namespace Black
{
	class BLACKAPI Layer
	{

	public:
		Layer(const std::string& name = "Layer");

		virtual ~Layer();
		virtual void OnDetach() {};
		virtual void OnAttach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event){}
		virtual void OnImGuiRender() {}


		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;


	};

}