#include "bpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"
namespace Black
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}