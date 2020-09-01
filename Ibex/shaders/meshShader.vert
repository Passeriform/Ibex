#version 330 core
layout (location = 0) in vec3 mPos;
layout (location = 1) in vec3 mColor;

out vec3 objColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * ( view * ( model * vec4(mPos, 1.0f) ) );
	objColor = mColor;
}
