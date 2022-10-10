#pragma once
#include"Black/Core.h"


struct GLFWwindow;
namespace Black
{
	class BLACKAPI GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

	};
}