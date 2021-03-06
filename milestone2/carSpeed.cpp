#include "carSpeed.hpp"

void carSpeed::getSpeed(keyControls& direction,Car car[],float& R, const int& N)
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

                car[0].speed = speed;
		car[0].angle = angle;

                for (int i = 0; i < N; i++)
                {
                        car[i].move();
                }
                for (int i = 1; i < N; i++)
                {
                        car[i].findTarget();
                }
}
