#include "keyControls.hpp"

void keyControls::getDirection()
{
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		up = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		right = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		down = 1;
	}
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		left = 1;
	}
	if(Keyboard::isKeyPressed(Keyboard::A))
	{
		boost = 1;
	}
}
