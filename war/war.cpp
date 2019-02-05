#include<iostream>
#include<math.h>
#include <algorithm>
#include <vector>
#include "war.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::random_shuffle;

// how many players are playing up to 4
#define CARDPLAYER 2

void generateDeck(vector<card>& deckOfCards);
void shuffleDeck(vector<card>& deckOfCards);

int main()
{
	srand((unsigned)time(0));
	//Making enum attributes of struct safeguards passing faulty values to the struct, therefore no need to catch
	//faulty initialization with contructor.
	vector<card> deckOfCards;	
	generateDeck(deckOfCards);
	shuffleDeck(deckOfCards);
	for(int i =0; i<52;++i)
	{
		cout << "suit: " << deckOfCards[i].cardSuit << " " << "rank: "<< deckOfCards[i].cardRank << endl;
	}
	
	return 0;
}

/*This functuion geberates the carddeck
 * Takes vector of structs
 * shuffles deck
 * returns nothing
 */
void shuffleDeck(vector<card>& deckOfCards)
{
	random_shuffle(deckOfCards.begin(), deckOfCards.end());
}

/*This function generates the carddeck
 * Takes array of pointers deckOfCards
 * This returns nothing
 */
void generateDeck(vector <card>& deckOfCards)
{
	card pushBackCard;
	for(int i=0; i < 4; ++i)
	{
		for(int j=0; j< 13; ++j)
		{
			pushBackCard.cardSuit = static_cast<suits>(i);
			pushBackCard.cardRank = static_cast<rank>(j);
			deckOfCards.push_back(pushBackCard); 
		}
	}
}
