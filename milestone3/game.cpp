#include "game.hpp"

void gameStart::game()
{
	RenderWindow app(VideoMode(640, 480), "Car Racing Game!");
        app.setFramerateLimit(60);

        Texture t1, t2, t3, player;
        t1.loadFromFile("images/background.png");
        t2.loadFromFile("images/car.png");
	t3.loadFromFile("images/rock.png");
	player.loadFromFile("images/car.png");

        t1.setSmooth(true);
        t2.setSmooth(true);
	t3.setSmooth(true);
	player.setSmooth(true);
        Sprite sBackground(t1), sCar(t2),playerCar(player);

	Sprite sRock[10];
	for(int i=0; i <10; ++i)
	{
		sRock[i].setTexture(t3);
	}
	
	sBackground.scale(2, 2);
        sCar.setOrigin(22, 22);
	playerCar.setOrigin(22,22);

        float R = 22;

        const int N = 6; // max
        Car pCar; 
	Car car[N];
	
	Rock rock[10] ={
				{-400,-400},
				{-800,-450},
				{-1300,-900},
				{-1400,-1500},
				{-2000,-1600},
				{-2500,-2000},
				{-2600,-3000},
				{-2000,-3300},
				{-1500,-3250},
				{-300,-2000}
			};

        for (int i = 0; i < N; i++)
        {
                car[i].x = 300 + i * 50;
                car[i].y = 1700 + i * 80;
                car[i].speed = 7 + i;
        }
	
	pCar.x = 300;
	pCar.y = 1700;

	pCar.speed = 7;

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
                currentSpeed.getSpeed(direction,car,R,N, pCar);
                // collision with ai
               aiCollision(car,pCar,N,R);

	       //collision with player
		pCollision(car,pCar,N,R);

		
		//collision with rock
		for(int i =0; i <10; ++i)
		{
			rock[i].rockCollision(sRock[i],car, playerCar, sCar, currentSpeed,N,pCar);
                }
	
                if (pCar.x > 320)
                {
			    currentSpeed.offsetX = pCar.x - 320;
                }
                if (pCar.y > 240)
                {
                        currentSpeed.offsetY = pCar.y - 240;
                }

                sBackground.setPosition(-currentSpeed.offsetX, -currentSpeed.offsetY);
                app.draw(sBackground);
		
		
		for(int i=0; i <10; ++i)
		{
			sRock[i].setPosition(-currentSpeed.offsetX, -currentSpeed.offsetY);
			sRock[i].setOrigin(rock[i].x,rock[i].y);
			app.draw(sRock[i]);

		}

		
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
	
		playerCar.setPosition(pCar.x - currentSpeed.offsetX, pCar.y - currentSpeed.offsetY);
                playerCar.setRotation(pCar.angle * 180 / 3.141593);
		playerCar.setColor(colors[0]);
		app.draw(playerCar);


                app.display();
        }
}
