#include "game.hpp"

void gameStart::game()
{
	RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
        app.setFramerateLimit(60);

        Texture t1, t2, t3;
        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/car.png");
        t1.setSmooth(true);
        t2.setSmooth(true);

        Sprite sBackground(t1), sCar(t2);
        sBackground.scale(2, 2);

        sCar.setOrigin(22, 22);
        float R = 22;

        const int N = 7;
        Car car[N];

        for (int i = 0; i < N; i++)
        {
                car[i].x = 300 + i * 50;
                car[i].y = 1700 + i * 80;
                car[i].speed = 7 + i;
        }
        carSpeed currentSpeed;

        while (app.isOpen())
        {
                Event e;
                while (app.pollEvent(e))
                {
                        if (e.type == Event::Closed)
                        {
                                app.close();
                        }
                }

                //Get key input 
                keyControls direction;
                direction.getDirection();

                // car movement
                currentSpeed.getSpeed(direction,car,R,N);
                // collision
                collision(car,N,R);

                app.clear(Color::White);

                if (car[0].x > 320)
                {
			    currentSpeed.offsetX = car[0].x - 320;
                }
                if (car[0].y > 240)
                {
                        currentSpeed.offsetY = car[0].y - 240;
                }

                sBackground.setPosition(-currentSpeed.offsetX, -currentSpeed.offsetY);
                app.draw(sBackground);

                Color colors[10] =
                {
                      Color::Red, Color::Green, Color::Magenta, Color::Blue, Color::White, Color::Yellow, Color::Black,
                };

                for (int i = 0; i < N; i++)
                {
                        sCar.setPosition(car[i].x - currentSpeed.offsetX, car[i].y - currentSpeed.offsetY);
                        sCar.setRotation(car[i].angle * 180 / 3.141593);
                        sCar.setColor(colors[i]);
                        app.draw(sCar);
                }

                app.display();
        }
}
