#include "bpch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"
namespace Black
{
	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{

		case RendererAPI::API::None: BLACK_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL: return new OpenGLVertexArray();
		}

		BLACK_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}