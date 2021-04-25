#version 420

layout(location = 0) in vec2 inUV;

out vec4 frag_color;



layout (binding = 0) uniform sampler2D s_screenTex;

uniform bool horizontal;
uniform float weight[5] = float[] (0.227027, 0.1945946, 0.1216216, 0.054054, 0.016216);

uniform float u_resolution;

uniform float u_focalLength = 1.0;
uniform float u_aparture = 248.0;
uniform float u_planeinfocus = 0.4;


float near = 0.01;
float far = 10.0;



void main() 
{

	//float objectDistance = far * near / (gl_FragCoord.z * (far - near) - far);

	//float coc = abs(u_aparture * (u_focalLength * (objectDistance -
	//				u_planeinfocus)) / (objectDistance * (u_planeinfocus - u_focalLength)));

	// vec2 tex_offset = coc / textureSize(s_screenTex, 0);


	vec4 source = texture(s_screenTex, inUV);
	float brightness = (source.r * 0.2126) + (source.g * 0.7152) + (source.b * 0.0722);
	
					
	vec2 tex_offset = 1.0 /textureSize(s_screenTex, 0);
	vec3 result = texture(s_screenTex, inUV).rgb * weight[0];

		for (int i = 1; i <5; i++)
		{
			result += texture(s_screenTex, inUV + vec2(0.0, tex_offset.y * i)).rgb * weight[i];
			result += texture(s_screenTex, inUV - vec2(0.0, tex_offset.y * i)).rgb * weight[i];
		}
	
	frag_color = vec4(result,1.0);
	
	
}
