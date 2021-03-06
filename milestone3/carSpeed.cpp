#include "carSpeed.hpp"

void carSpeed::getSpeed(keyControls& direction,Car car[],float& R, const int& N,Car& playerCar)
{
	if (direction.up && speed < maxSpeed)
	{
		if (speed < 0)
		{
			speed += dec;
		}
		else
		{
			speed += acc;
		}
	}

	if (direction.down && speed > -maxSpeed)
	{
		if (speed > 0)
		{
			speed -= dec;
		}
		else
		{
			speed -= acc;
		}
	}

	if (!direction.up && !direction.down)
	{
		if (speed - dec > 0)
		{
			speed -= dec;
		}
		else if (speed + dec < 0)
		{
			speed += dec;
		}
		else
		{
			speed = 0;
		}
	}
	
	if (direction.right && speed != 0)
	{
		angle += turnSpeed * speed / maxSpeed;
	}
	if (direction.left && speed != 0)
	{
		angle -= turnSpeed * speed / maxSpeed;
	}

	if(direction.boost)
	{
		maxSpeed = 15;
		acc = .5;
		while(speed < maxSpeed)
		{
			speed += acc;
		}
	}
	if(!direction.boost && speed > 12)
	{
		maxSpeed = 12;
		acc = .2;
		speed -= dec;
	
	}

	playerCar.speed = speed;
	playerCar.angle = angle;

	playerCar.move();

	for (int i = 0; i < N; i++)
	{
		car[i].move();
	}
	for (int i = 0; i < N; i++)
	{
		car[i].findTarget();
	}
}
