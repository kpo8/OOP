#ifndef WAR_H
#define WAR_H

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

#endif
