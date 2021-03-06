#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;

layout (binding = 0) uniform sampler2D s_screenTex;

//Intensity of the sepia effect
//Lower the number, closer to regular color

void main() 
{
	vec4 source = texture(s_screenTex, inUV);

	frag_color = source;
}