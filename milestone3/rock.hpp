//racing.hpp
#ifndef ROCK_HPP
#define ROCK_HPP

//Class Car
//variables x,y,speed,angle
//methods move and findTarget
struct Rock
{
	int x;
	int y;
      
	void rockCollision(Sprite sRock, Car car[],Sprite& playerSprite, Sprite& sCar, carSpeed& currentSpeed, const int N, Car playerCar);

};

#endif /*ROCK_H*/
