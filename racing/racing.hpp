//racing.hpp
#ifndef RACING_HPP
#define RACING_HPP

//Class Car
//variables x,y,speed,angle
//methods move and findTarget
struct Car
{
        float x, y, speed, angle;
        int n;

        Car()
        {
                speed = 2;
                angle = 0;
                n = 0;
        }

        void move()
        {
                x += std::sin(angle) * speed;
                y -= std::cos(angle) * speed;
        }

        void findTarget()
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
};

#endif /*RACING_H*/
