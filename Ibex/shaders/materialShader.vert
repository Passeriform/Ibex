#version 330 core
layout (location = 0) in vec3 mPos;
layout (location = 1) in vec3 mNormal;
layout (location = 2) in vec3 mColor;
layout (location = 3) in vec3 mTexture;

out vec3 fragPos;
out vec3 objColor;
out vec3 objNormal;
out vec3 textureCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

// uniform modelInverse; // Set when CPU-precompute implemented

void main()
{
	fragPos = vec3(model * vec4(mPos, 1.0));
	objColor = mColor;
	objNormal = mat3(transpose(inverse(model))) * mNormal; // TODO: Precompute transposed inverse on CPU instead
	textureCoords = mTexture;

	gl_Position = projection * ( view * ( model * vec4(fragPos, 1.0f) ) ); // TODO: Precompute MVP matrix on CPU instead
}
