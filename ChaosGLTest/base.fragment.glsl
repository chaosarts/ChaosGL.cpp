#version 330

in vec4 var_Color;
out vec4 glFragmentColor;

void main ()
{
	glFragmentColor = var_Color;
}