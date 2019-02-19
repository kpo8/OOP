#ifndef CARSPEED_HPP
#define CARSPEED_HPP

struct carSpeed
{
        float speed;
        float angle;
        float maxSpeed;
        float acc;
        float dec;
        float turnSpeed;
        int offsetX;
        int offsetY;

        carSpeed()
        {
                speed = 0;
                angle = 0;
                maxSpeed = 12.0;
                acc = 0.2;
                dec = 0.3;
                turnSpeed = 0.08;
                offsetX = 0;
                offsetY = 0;
        }

	void getSpeed(keyControls& direction,Car car[],float& R, const int& N);
};

#endif
