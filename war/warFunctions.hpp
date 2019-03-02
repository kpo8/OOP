#ifndef WARFUNCTIONS_H
#define WARFUNCTIONS_H

	//Type for suits
	enum suits
	{
		hearts,
		diamonds,
		spades,
		clubs
	};
	//type for ranks
	enum rank
	{
		two,
		three,
		four,
		five,
		six,
		seven,
		eight,
		nine,
		ten,
		jack,
		queen,
		king,
		ace
	};
	//color for jokers
	enum color	
	{	
		black,
		red,
	}
	struct joker
	{
		color jokerColor;
		joker()
		{

		}
		Color getColor();
	}
	//struct for playing card
	struct card
	{
		suits cardSuit;
		rank  cardRank;
		//leave in here in case something changes
		/*card ()
		{
			//Guardrail to catch bad initialization of suit
			if(cardSuit > 3 || cardSuit < 0) 
			{
				std::cout << "bad suit" << std::endl; 
				abort();
			}
			//Guardrail to catch bad initilization of rank
			if(cardSuit > 3 || cardSuit < 0) 
			{
				std::cout << "bad rank" << std::endl;
				abort();
			}
		}*/
	};
void generateDeck(vector<card>& deckOfCards);
void shuffleDeck(vector<card>& deckOfCards);
void spotCheck(vector<card>& deckOfCards);
void assignCards(vector<card>& deckOfCards, vector<card>& player1, vector<card>& player2);
void duel(vector<card>& player1, vector<card>& player2);
void warSpecialCase(vector<card>& player1, vector<card>& player2, card& player1Card, card& player2Card);

#endif
