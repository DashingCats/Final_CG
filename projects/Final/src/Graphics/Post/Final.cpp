#include "Final.h"

void Final::Init(unsigned width, unsigned height)
{
    int index = int(_buffers.size());
    _buffers.push_back(new Framebuffer());
    _buffers[index]->AddColorTarget(GL_RGBA8);
    _buffers[index]->AddDepthTarget();
    _buffers[index]->Init(width, height);

    //Loads the shaders
    index = int(_shaders.size());
    _shaders.push_back(Shader::Create());
    _shaders[index]->LoadShaderPartFromFile("shaders/final_vert.glsl", GL_VERTEX_SHADER);
    _shaders[index]->LoadShaderPartFromFile("shaders/Post/final.glsl", GL_FRAGMENT_SHADER);
    _shaders[index]->Link();
}

void Final::ApplyEffect(PostEffect* buffer)
{
    BindShader(0);
    _shaders[0]->SetUniform("u_focalLength", _focalLength);
    //BindShader(1);
    //_shaders[1]->SetUniform("u_aparture", _aparture);
    //BindShader(2);
    //_shaders[2]->SetUniform("u_planeinfocus", _planeinfocus);

    buffer->BindColorAsTexture(0, 0, 0);

    _buffers[0]->RenderToFSQ();
    //_buffers[1]->RenderToFSQ();
    //_buffers[2]->RenderToFSQ();

    buffer->UnbindTexture(0);
    //buffer->UnbindTexture(1);
    //buffer->UnbindTexture(2);

    UnbindShader();
}

float Final::GetFocalLength() const
{
    return _focalLength;
}
float Final::GetAparture() const
{
    return _aparture;
}
float Final::GetPlaneInFocus() const
{
    return _planeinfocus;
}


void Final::SetFocalLength(float focalLength)
{
    _focalLength = focalLength;
}
void Final::SetAparture(float aparture)
{
    _aparture = aparture;
}
void Final::SetPlaneInFocus(float planeinfocus)
{
    _planeinfocus = planeinfocus;
}




