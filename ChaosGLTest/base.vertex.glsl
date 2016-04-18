#version 330

uniform mat4 ModelViewMatrix;
uniform mat4 CameraViewMatrix;
uniform mat4 ProjectionViewMatrix;

in vec3 in_Position;
in vec4 in_Color;

out vec4 var_Color;

void main ()
{
	gl_Position = ProjectionViewMatrix * CameraViewMatrix * ModelViewMatrix * vec4(in_Position, 1.0);
	var_Color = in_Color;
}