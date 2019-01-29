#include<iostream>
#include<math.h>
#include <algorithm>
#include <vector>
#include "war.hpp"

using std::cout;
using std::endl;
using std::vector;

// how many players are playing up to 4
#define CARDPLAYER 2

void generateDeck(card* deckOfCards[]);
void shuffleDeck(card* deckOfCards[]);
int chooseRank();
int chooseSuit();
void assignPlayersDec(vector<vector<card> > numOfPlayers,card* deckOfCards[]);
void duel();

int main()
{
	srand((unsigned)time(0));
	//Making enum attributes of struct safeguards passing faulty values to the struct, therefore no need to catch
	//faulty initialization with contructor.
	card* deckOfCards[4];	
	generateDeck(deckOfCards);
	shuffleDeck(deckOfCards);

	//This is the players cards made out of vector so we don't have to delete and add manually
	vector<vector<card> > numOfPlayers(CARDPLAYER, vector<card>(52/CARDPLAYER));
	assignPlayersDec(numOfPlayers,deckOfCards);

	return 0;
}

void assignPlayersDec(vector<vector<card> > numOfPlayers,card* deckOfCards[])
{
	int counter = 0;
	int counter2 =0;
	for(int i = 0; i < 4; ++i)
	{
		for(int j =0; j < 13; ++j)
		{
			if(counter == CARDPLAYER)
			{
				counter =0;
				++counter2;
			}
			if(counter2 < 52/CARDPLAYER)
			{	
				numOfPlayers[counter][counter2] = deckOfCards[i][j];
			}
			++counter;
		}
	}
	for(int i = 0; i < CARDPLAYER; ++i)
	{
		for(int j =0; j < 52/ CARDPLAYER; ++j)
		{
			cout << "(" << numOfPlayers[i][j].cardSuit <<  "," << numOfPlayers[i][j].cardRank << ")";	
		}
		cout << endl;
	}
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
