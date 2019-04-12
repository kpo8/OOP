#include "rock.hpp"

void Rock::rockCollision(Sprite sRock, Car car[],Sprite& playerSprite, Sprite& sCar, carSpeed& currentSpeed,const int N, Car playerCar)
{
	if(sRock.getGlobalBounds().intersects(sCar.getGlobalBounds()))
	{
		for(int i =1; i <N; ++i)
		{
			car[i].x = car[i].x -1;
			car[i].y = car[i].y- 1;
		}
	}
	if(sRock.getGlobalBounds().intersects(playerSprite.getGlobalBounds()))
	{
		currentSpeed.speed = 0;	
		playerCar.x = playerCar.x -1;
		playerCar.y = playerCar.y -1;	
	}
}
