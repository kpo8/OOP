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
	srand((unsigned)time(0));
	//Making enum attributes of struct safeguards passing faulty values to the struct, therefore no need to catch
	//faulty initialization with contructor.
	vector<card> deckOfCards;	
	generateDeck(deckOfCards);
	shuffleDeck(deckOfCards);	
	
	//Our players
	vector<card> player1;
	vector<card> player2;
	
	assignCards(deckOfCards, player1, player2);
	cout <<"player1" << endl;
	spotCheck(player1);
	cout <<"player2" <<endl;
	spotCheck(player2);

	duel(player1,player2);
	
	return 0;
}

