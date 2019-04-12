#include <cmath>

#include <SFML/Graphics.hpp>

using namespace sf;

#include "car.hpp"
#include "car.cpp"
#include "keyControls.hpp"
#include "keyControls.cpp"
#include "carSpeed.hpp"
#include "carSpeed.cpp"
#include "rock.hpp"
#include "rock.cpp"
#include "game.hpp"
#include "game.cpp"

int main()
{
	gameStart gameBegin;
	gameBegin.game();
	return 0;
}
