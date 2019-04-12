#include "rock.hpp"

void Rock::rockCollision(Sprite sRock, Car car[], Sprite& sCar, carSpeed& currentSpeed,const int N, Car playerCar)
{
	if(sRock.getGlobalBounds().intersects(sCar.getGlobalBounds()))
	{
		currentSpeed.speed =0;

		for(int i =1; i <N; ++i)
		{
			car[i].x = car[i].x -1;
			car[i].y = car[i].y- 1;
		}
	}
}
