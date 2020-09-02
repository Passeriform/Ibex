#version 330 core
layout (location = 0) in vec3 mPos;
layout (location = 1) in vec3 mColor;

out vec3 objColor;

uniform mat4 model, view, projection;
uniform float delta;
uniform float pointsize;
uniform vec3 cameraeye;

void main()
{
	gl_Position = projection * ( view * ( model * vec4(mPos, 1.0f) ) );
	objColor = mColor;
	gl_PointSize = max(pointsize - (delta * distance(cameraeye, mPos) / pointsize), 5.0f);
}
