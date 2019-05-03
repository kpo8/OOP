#include "car.hpp"
void Car::move()
{
                x += std::sin(angle) * speed;
                y -= std::cos(angle) * speed;
}

void Car::findTarget()
{
	float tx = points[n][0];
	float ty = points[n][1];
	float beta = angle - std::atan2(tx - x, -ty + y);
	if (std::sin(beta) < 0)
	{
		angle += 0.005 * speed;
	}
	else
	{
		angle -= 0.005 * speed;
	}
	if ((x - tx) * (x - tx) + (y - ty) * (y - ty) < 25 * 25)
	{
		n = (n + 1) % num;
	}
}

void aiCollision(Car car[],Car pCar, const int& N, float& R)
{
	for(int i = 0; i < N; i++)
	{
        	for (int j = 0; j < N; j++)
       		{
                	int dx = 0, dy = 0;
                        while (dx * dx + dy * dy < 4 * R * R)
                        {
                        	car[i].x += dx / 4.0;
                        	car[i].x += dy / 4.0;
                        	car[j].x -= dx / 4.0;
                        	car[j].y -= dy / 4.0;
                       		dx = car[i].x - car[j].x;
                                dy = car[i].y - car[j].y;
                                if (!dx && !dy)
                                {
                                	break;
                                }
                       }
               }
	}	
}
//player collisions
void pCollision(Car car[],Car pCar, const int& N, float& R)
{
	for(int i = 0; i < N; i++)
	{	
		int dx = 0, dy = 0;
		while (dx * dx + dy * dy < 4 * R * R)
		{
			pCar.x += dx/4.0;
			pCar.y += dy/4.0;
			car[i].x -= dx / 4.0;
			car[i].x -= dy / 4.0;
			dx = pCar.x - car[i].x;
			dy = pCar.y - car[i].y;
			
			if (!dx && !dy)
			{
				break;
			}
	       }
		dx = 0, dy = 0;
		while (dx * dx + dy * dy < 4 * R * R)
		{
			pCar.x -= dx/4.0;
			pCar.y -= dy/4.0;
			car[i].x += dx / 4.0;
			car[i].x += dy / 4.0;
			dx = car[i].x - pCar.x;
			dy = car[i].y - pCar.y;
			
			if (!dx && !dy)
			{
				break;
			}
	       }       
	}	
}
