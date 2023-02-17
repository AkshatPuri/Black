#include "bpch.h"
#include "OpenGLVertexArray.h"
#include <glad/glad.h>
namespace Black
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
        case Black::ShaderDataType::Float:    return GL_FLOAT;
        case Black::ShaderDataType::Float2:   return GL_FLOAT;
        case Black::ShaderDataType::Float3:   return GL_FLOAT;
        case Black::ShaderDataType::Float4:   return GL_FLOAT;
        case Black::ShaderDataType::Mat3:     return GL_FLOAT;
        case Black::ShaderDataType::Mat4:     return GL_FLOAT;
        case Black::ShaderDataType::Int:      return GL_INT;
        case Black::ShaderDataType::Int2:     return GL_INT;
        case Black::ShaderDataType::Int3:     return GL_INT;
        case Black::ShaderDataType::Int4:     return GL_INT;
        case Black::ShaderDataType::Bool:     return GL_BOOL;
        }

        BLACK_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }


    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        BLACK_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "Vertex Buffer has no layout!");

        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();

        uint32_t index = 0;
        const auto& layout = vertexBuffer->GetLayout();

        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index, element.GetComponentCount(), ShaderDataTypeToOpenGLBaseType(element.Type),
                element.Normalized ? GL_TRUE : GL_FALSE, layout.GetStride(), (const void*)element.Offset);
            index++;
        }
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }

}