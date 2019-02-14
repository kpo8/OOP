#ifndef WARFUNCTIONS_H
#define WARFUNCTIONS_H

	//Type for suits
	unsigned enum suits
	{
		hearts,
		diamonds,
		spades,
		clubs
	};
	//type for ranks
	unsigned enum rank
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
	
	//struct for playing card
	struct card
	{
		 suits cardSuit;
		 rank  cardRank;
	};
	class startGame
	{
		public:

		startGame()
		{

		}
		void game();			
	};

void generateDeck(vector<card>& deckOfCards);
void shuffleDeck(vector<card>& deckOfCards);
void spotCheck(vector<card>& deckOfCards);
void assignCards(vector<card>& deckOfCards, vector<card>& player1, vector<card>& player2);
void duel(vector<card>& player1, vector<card>& player2);
void warSpecialCase(vector<card>& player1, vector<card>& player2, card& player1Card, card& player2Card);

#endif
