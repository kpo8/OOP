#include "warFunctions.hpp"

/*In case of a tie implement war scenario
 * takes vector card player 1 and player 2 as well a current cards
 * returns nothing
 */
void warSpecialCase(vector<card>& player1, vector<card>& player2, card& player1Card, card& player2Card)
{
	vector <card> warSpoil;
	while(player2Card.cardRank == player1Card.cardRank)
	{

		if (player1.empty())
		{
			cout << "Player1 is out of cards." << endl;
			cout << "Player2 wins." << endl;	
			break;
		}
		else if (player2.empty())
		{
			cout << "Player2 is out of cards." << endl;
			cout << "Player1 wins" << endl;	
			break;
		}
		warSpoil.push_back(player1Card);
		warSpoil.push_back(player2Card);
		
		//Put into warspoil pot
		warSpoil.push_back(player1[0]);
		warSpoil.push_back(player2[0]);
		player1.erase(player1.begin());
		player2.erase(player2.begin());
		
		//compare last 2
		player1Card = player1[0];
		player2Card = player2[0];

	}
		
	if(player1Card.cardRank > player2Card.cardRank)
	{
		for (int i = 0; i < warSpoil.size(); i++)
		{
			player1.push_back(warSpoil[i]);
			warSpoil.erase(warSpoil.begin());
		}
	}
	
	if(player2Card.cardRank > player1Card.cardRank)
	{
		for (int i = 0; i < warSpoil.size(); i++)
		{
			player2.push_back(warSpoil[i]);
			warSpoil.erase(warSpoil.begin());
		}
	}

	
}
/*compares and swaps cards
 * takes in player1 and player2
 * returns nothing
 */
void duel(vector<card>& player1, vector<card>& player2)
{
	//Play until one vector is empty	
	while(!player1.empty() && !player2.empty())
	{
		//draw deck and erase top card
		card player1Card = player1[0];
		card player2Card = player2[0]; 
		player1.erase(player1.begin());
		player2.erase(player2.begin());

		if(player1Card.cardRank > player2Card.cardRank)
		{
			player1.push_back(player1Card);
			player1.push_back(player2Card);
		}
		if(player2Card.cardRank > player1Card.cardRank)
		{
			player2.push_back(player1Card);
			player2.push_back(player2Card);
		}
		if(player2Card.cardRank == player1Card.cardRank)
		{
			warSpecialCase(player1,player2,player1Card,player2Card);
		}
				cout << "Player1" <<endl;
				spotCheck(player1);
				cout << "Player2" << endl;
				spotCheck(player2);
	}
}
/*This function deals the deck
 * takes deckOfCards, player1, player2
 * returns nothing
 */
void assignCards(vector<card>& deckOfCards, vector<card>& player1, vector<card>& player2)
{
	for(int i=0;i<52; ++i)
	{
		if( i % 2 == 0)
		{
		//	cout << i << " " << "one" << endl;
			player1.push_back(deckOfCards[i]);
		}
		if(i % 2 != 0)
		{
		//	cout << i << " " << "two" << endl;
			player2.push_back(deckOfCards[i]);
		}
	}	
}


/* This function is just a check to make sure deck is right
 * takes deck of cards
 * displays deck of cards
 * returns nothing
 */
void spotCheck(vector<card>& deckOfCards)
{
	for(int i =0; i<deckOfCards.size();++i)
	{
		cout << "(" << deckOfCards[i].cardSuit << "," << deckOfCards[i].cardRank <<")" << " ";
	}
	cout << endl;
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
