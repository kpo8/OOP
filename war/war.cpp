#include<iostream>
#include<math.h>
#include <algorithm>
#include "war.hpp"

using std::cout;
using std::endl;

// how many players are playing up to 4
#define CARDPLAYER 2

void generateDeck(card* deckOfCards[]);
void shuffleDeck(card* deckOfCards[]);
int chooseRank();
int chooseSuit();

int main()
{
	srand((unsigned)time(0));
	//Making enum attributes of struct safeguards passing faulty values to the struct, therefore no need to catch
	//faulty initialization with contructor.
	card* deckOfCards[4];	
	generateDeck(deckOfCards);	
	shuffleDeck(deckOfCards);
	return 0;
}

/*
 This function shuffles the deck
 This takes array of pointers deckOfCards
 This returns nothing
 */	
void shuffleDeck(card* deckOfCards[])
{
	for(int i=0; i < 4; ++i)
	{
		for(int j=0; j <13; ++j)
		{
			int rank = chooseRank();
			int suit = chooseSuit();
			std::swap(deckOfCards[i][j].cardSuit, deckOfCards[suit][rank].cardSuit);
			std::swap(deckOfCards[i][j].cardRank, deckOfCards[suit][rank].cardRank); 
		}
	}
}

/*This function picks a random rank
 * Takes nothing
 * Returns nothing
 */
int chooseRank()
{
	//sets a float equal to a random number
	//seeded in main
	//rounds up random number and multiple by power of ten
	int holder = round(((static_cast<float>(rand())/RAND_MAX)*12));
	return holder;
}

/*This function picks a random suit
 * Takes nothing
 * Returns nothing
 */
int chooseSuit()
{
	//sets a float equal to a random number
	//seeded in main
	//rounds up random number and multiple by power of ten
	int holder = round(((static_cast<float>(rand())/RAND_MAX)*3));
	return holder;
}

/*This function generates the carddeck
 * Takes array of pointers deckOfCards
 * This returns nothing
 */
void generateDeck(card* deckOfCards[])
{	
	for(int i=0; i < 4; ++i)
	{
		deckOfCards[i] = new card[13];

		for(int j=0; j <13; ++j)
		{
			deckOfCards[i][j].cardSuit = static_cast<suits>(i);
			deckOfCards[i][j].cardRank = static_cast<rank>(j);
		}
	}
}
