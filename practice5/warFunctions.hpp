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
	
	enum color
	{
		red,
		black,
	}
	
	//struct for playing card
	struct card
	{
		suits cardSuit;
		rank  cardRank;
	};
	struct joker
	{
		color jokerColor;
	}
	
	struct playingCard
	{
		card StandardCard;
		joker Card;
		
		playingCard tag;

		PlayingCard(Rank r, Suit s)
		: tag(Standard), data(r, s)
		{ }

		bool is_standard() const
		{
			return tag=standard;
		}
		bool is_joker() const
		{
			tag=Joker;
		}

	}
std::ostream& operator<<(std::ostream& os, suit s);
std::ostream& operator<<(std::ostream& os, rank r);
std::ostream& operator<<(std::ostream& os, color r);
std::ostream& operator<<(std::ostream& os, playingCard c);
std::ostream& operator<<(std::ostream& os, joker c);
std::ostream& operator<<(std::ostream& os, card c);

void generateDeck(vector<card>& deckOfCards);
void shuffleDeck(vector<card>& deckOfCards);
void spotCheck(vector<card>& deckOfCards);
void assignCards(vector<card>& deckOfCards, vector<card>& player1, vector<card>& player2);
void duel(vector<card>& player1, vector<card>& player2);
void warSpecialCase(vector<card>& player1, vector<card>& player2, card& player1Card, card& player2Card);

#endif
