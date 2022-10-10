#pragma once
#include "Black/Renderer/GraphicsContext.h"

namespace Black
{
    class OpenGLContext : public GraphicsContext
    {

    public:
         OpenGLContext(GLFWwindow* window);

        // Inherited via GraphicsContext
        virtual void Init() override;
        virtual void SwapBuffers() override;


    private:

        GLFWwindow* m_WindowHandle;
    };
}

