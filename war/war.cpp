#include<iostream>
#include<math.h>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::random_shuffle;

#include "warFunctions.hpp"
#include "warFunctions.cpp"

int main()
{
	startGame gameObj;
	
	gameObj.game();	
	
	return 0;
}

