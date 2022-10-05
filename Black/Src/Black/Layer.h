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
		virtual void OnDetach()=0;
		virtual void OnAttach()=0;
		virtual void OnUpdate()=0;
		virtual void OnEvent(Event& event){}

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;


	};

}