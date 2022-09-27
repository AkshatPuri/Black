#pragma once
#include "Event.h"




namespace Black
{
	class BLACKAPI WindowResizeEvent :public Event
	{
	public:
		WindowResizeEvent(unsigned int width,unsigned int height)
			:m_Width(width), m_Height(height){}

		inline unsigned int GetWidth() const { return m_Width; };
		inline unsigned int GetHeight() const { return m_Height; };

		EVENT_CLASS_TYPE(WindowResize)
	    EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int m_Width, m_Height;
	};


	class BLACKAPI WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLACKAPI AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLACKAPI AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	};

	class BLACKAPI AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}