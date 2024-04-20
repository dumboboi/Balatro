#include "Deck.h"
#include <iostream>
#include <Button.h>
#include <algorithm>
#include <TextManager.h>
#include <windows.h> 
#include "time.h"
#define pb push_back


TextManager MM;

Button playB("Play Hand", sf::Vector2f(400, 600), sf::Vector2f(160, 100), sf::Color(13, 161, 214, 250), sf::Color(13, 161, 214, 130));
Button DiscardB("Discard", sf::Vector2f(700, 600), sf::Vector2f(160, 100), sf::Color(255, 99, 71, 250), sf::Color(255, 99, 71, 130));
Button CARDS(sf::Vector2f(1100, 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));

Button b1(sf::Vector2f(360, 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b2(sf::Vector2f(360 + 80, 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b3(sf::Vector2f(360 + (80 * 2), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b4(sf::Vector2f(360 + (80 * 3), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b5(sf::Vector2f(360 + (80 * 4), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b6(sf::Vector2f(360 + (80 * 5), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b7(sf::Vector2f(360 + (80 * 6), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));
Button b8(sf::Vector2f(360 + (80 * 7), 460), sf::Vector2f(75, 105), sf::Color(0, 128, 0, 130));




Deck::Deck()
{
	srand(time(NULL));

	if (!cardsTexture.loadFromFile("assets/cardsSheet.png"))
	{
		std::cout << "Failed to Load Cards !!! \n";
	}
	else
	{
		std::cout << "   *Cards Loaded successfully\n";
		std::cout << "############################################\n\n\n";
	}
	cardsSprite.setTexture(cardsTexture);
	cardsSprite.setTextureRect(sf::IntRect(0, 0, 64, 89));
	cardsSprite.setPosition(600, 580);

}

void Deck::resetAllRun()
{
	resetDeck();
	handPos.x = 600;
	handPos.y = 580;
	std::vector<int> intvect = convertCardsToNumbers(hand);
	bubbleSort(intvect, intvect.size());
}

void Deck::fillHand()
{
	int x;
	for (int c = 0; c < 8; c++)
	{



		x = rand() % cards.size();

		hand.push_back(cards[x]);
		std::vector<std::string>::iterator it = cards.begin();
		cards.erase(it + x);
		cardsClicked.pb(false);
		clickingCD.pb(60);
		canClick.pb(true);
	}

}

void Deck::setMinimumScore(int mscore)
{
	minimumScore = mscore;
}

bool Deck::checkIfFailed(int score)
{
	return (handsCount < 1 && score < minimumScore);

}

bool Deck::checkIfFinished(int score)
{
	return (handsCount >= 0 && score >= minimumScore);
}


void Deck::checkToaddCards()
{
	if (needToAddCards)
	{

		if (hand.size() < 8)
		{
			int x = rand() % cards.size();

			hand.push_back(cards[x]);
			std::vector<std::string>::iterator it = cards.begin();
			cards.erase(it + x);
		}
		else
		{
			needToAddCards = false;
		}
	}

}

void Deck::discardCards(std::vector<std::string> selectedC)
{

	for (auto& x : selectedC)
	{
		hand.erase(find(hand.begin(), hand.end(), x));
	}
	needToAddCards = true;
}

sf::IntRect Deck::getTexture(std::string cardName)
{
	sf::IntRect textureCoords;
	textureCoords.width = 64;
	textureCoords.height = 89;
	if (cardName.length() == 3)
	{
		if (cardName[0] == '1' && cardName[1] == '0')
		{
			textureCoords.top = 89 * 3;
			if (cardName[2] == 'C')
			{
				textureCoords.left = 64 * 6;
			}
			else if (cardName[2] == 'D')
			{
				textureCoords.left = 64 * 7;
			}
			else if (cardName[2] == 'H')
			{
				textureCoords.left = 64 * 8;
			}
			else
			{
				textureCoords.left = 64 * 9;
			}

		}
		else if (cardName[0] == '1' && cardName[1] == '1')
		{
			textureCoords.top = 89 * 4;
			if (cardName[2] == 'C')
			{
				textureCoords.left = 0;
			}
			else if (cardName[2] == 'D')
			{
				textureCoords.left = 64;
			}
			else if (cardName[2] == 'H')
			{
				textureCoords.left = 64 * 2;
			}
			else
			{
				textureCoords.left = 64 * 3;
			}

		}
		else if (cardName[0] == '1' && cardName[1] == '2')
		{
			textureCoords.top = 89 * 4;
			if (cardName[2] == 'C')
			{
				textureCoords.left = 64 * 4;
			}
			else if (cardName[2] == 'D')
			{
				textureCoords.left = 64 * 5;
			}
			else if (cardName[2] == 'H')
			{
				textureCoords.left = 64 * 6;
			}
			else
			{
				textureCoords.left = 64 * 7;
			}

		}
		else if (cardName[0] == '1' && cardName[1] == '3')
		{
			if (cardName[2] == 'C')
			{
				textureCoords.top = 89 * 4;
				textureCoords.left = 64 * 8;
			}
			else if (cardName[2] == 'D')
			{
				textureCoords.top = 89 * 4;
				textureCoords.left = 64 * 9;
			}
			else if (cardName[2] == 'H')
			{
				textureCoords.top = 89 * 5;
				textureCoords.left = 0;
			}
			else
			{
				textureCoords.top = 89 * 5;
				textureCoords.left = 64;
			}

		}
	}
	else
		if (cardName[0] == '1' && cardName.length() <= 2)
		{

			textureCoords.top = 0;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 0;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 128;
			}
			else
			{
				textureCoords.left = 64 * 3;
			}
		}
		else if (cardName[0] == '2')
		{
			textureCoords.top = 0;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 64 * 4;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64 * 5;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 6;
			}
			else
			{
				textureCoords.left = 64 * 7;
			}
		}
		else if (cardName[0] == '3')
		{
			if (cardName[1] == 'C')
			{
				textureCoords.top = 0;

				textureCoords.left = 64 * 8;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.top = 0;

				textureCoords.left = 64 * 9;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.top = 89;
				textureCoords.left = 0;
			}
			else
			{
				textureCoords.top = 89;
				textureCoords.left = 64;
			}

		}
		else if (cardName[0] == '4')
		{
			textureCoords.top = 89;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 64 * 2;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64 * 3;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 4;
			}
			else
			{
				textureCoords.left = 64 * 5;
			}
		}
		else if (cardName[0] == '5')
		{
			textureCoords.top = 89;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 64 * 6;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64 * 7;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 8;
			}
			else
			{
				textureCoords.left = 64 * 9;
			}

		}
		else if (cardName[0] == '6')
		{
			textureCoords.top = 178;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 0;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 2;
			}
			else
			{
				textureCoords.left = 64 * 3;
			}
		}
		else if (cardName[0] == '7')
		{
			textureCoords.top = 178;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 64 * 4;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64 * 5;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 6;
			}
			else
			{
				textureCoords.left = 64 * 7;
			}

		}
		else if (cardName[0] == '8')
		{
			if (cardName[1] == 'C')
			{
				textureCoords.top = 178;

				textureCoords.left = 64 * 8;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.top = 178;

				textureCoords.left = 64 * 9;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.top = 89 * 3;

				textureCoords.left = 0;
			}
			else
			{
				textureCoords.top = 89 * 3;

				textureCoords.left = 64;
			}

		}
		else if (cardName[0] == '9')
		{
			textureCoords.top = 89 * 3;
			if (cardName[1] == 'C')
			{
				textureCoords.left = 64 * 2;
			}
			else if (cardName[1] == 'D')
			{
				textureCoords.left = 64 * 3;
			}
			else if (cardName[1] == 'H')
			{
				textureCoords.left = 64 * 4;
			}
			else
			{
				textureCoords.left = 64 * 5;
			}
		}


	return textureCoords;



}

int Deck::nbClicked()
{
	int sum = 0;
	for (int x = 0; x < cardsClicked.size(); x++)
	{
		if (cardsClicked[x])
			sum += 1;
	}
	return sum;
}


void Deck::setRun(std::vector<std::string> handsaved, std::vector<std::string> deck, int discardsL, int handsL)
{
	hand.clear();
	hand = handsaved;

	cards.clear();
	cards = deck;
	cardsClicked.clear();
	clickingCD.clear();
	canClick.clear();

	discardCount = discardsL;
	handsCount = handsL;
	for (int c = 0; c < 8; c++)
	{
		cardsClicked.pb(false);
		clickingCD.pb(60);
		canClick.pb(true);
	}

}


void Deck::bubbleSort(std::vector<int>& intvector, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already 
		// in place 
		for (j = 0; j < n - i - 1; j++)
			if (intvector[j] > intvector[j + 1])
			{
				int aux = intvector[j];
				intvector[j] = intvector[j + 1];
				intvector[j + 1] = aux;
				std::string temp = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = temp;

			}
}


void Deck::drawHand(sf::RenderWindow* window)
{
	playB.draw(*window);
	DiscardB.draw(*window);
	MM.drawCardsLeftInDeck(window, cards.size());
	for (int i = 0, left = 360; i < hand.size(); i++, left += 80)
	{
		cardsSprite.setTextureRect(getTexture(hand[i]));
		cardsSprite.setPosition(left, 460);
		cardsSprite.setScale(1.2, 1.2);
		window->draw(cardsSprite);
	}
	int HC = hand.size();
	if (HC == 8)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
		b4.draw(*window);
		b5.draw(*window);
		b6.draw(*window);
		b7.draw(*window);
		b8.draw(*window);
	}
	else if (HC == 7)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
		b4.draw(*window);
		b5.draw(*window);
		b6.draw(*window);
		b7.draw(*window);
	}
	else if (HC == 6)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
		b4.draw(*window);
		b5.draw(*window);
		b6.draw(*window);
	}
	else if (HC == 5)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
		b4.draw(*window);
		b5.draw(*window);
	}
	else if (HC == 4)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
		b4.draw(*window);
	}
	else if (HC == 3)
	{
		b1.draw(*window);
		b2.draw(*window);
		b3.draw(*window);
	}
	else if (HC == 2)
	{
		b1.draw(*window);
		b2.draw(*window);
	}
	else if (HC == 1)
	{
		b1.draw(*window);
	}
	CARDS.drawDeck(*window);
	MM.drawCustom(window, std::to_string(Multip), sf::Vector2f(245, 480), 35, sf::Color(255, 255, 255, 255));
	MM.drawCustom(window, std::to_string(NumbToMult), sf::Vector2f(90, 480), 35, sf::Color(255, 255, 255, 255));
	MM.drawCustom(window, std::to_string(minimumScore), sf::Vector2f(185, 189), 35, sf::Color(229, 29, 29, 255));
	MM.drawCustom(window, std::to_string(handsCount), sf::Vector2f(169, 591), 25, sf::Color(0, 128, 255, 255));
	MM.drawCustom(window, std::to_string(discardCount), sf::Vector2f(259, 591), 25, sf::Color(229, 29, 29, 255));

}

void Deck::update(sf::Vector2f cursCoords, sf::RenderWindow* window, int& Score)
{
	std::vector<int> intvect = convertCardsToNumbers(hand);
	bubbleSort(intvect, intvect.size());

	playB.update2(cursCoords);
	DiscardB.update2(cursCoords);

	updateButtons(cursCoords, window);
	int nbc = nbClicked();
	std::vector<std::string> temp = cardsnamesclicked();

	if (nbc != 0 && DiscardB.checkClickedButton(cursCoords))
	{
		if (discardCount > 0)
		{
			discardCards(temp);
			//CLEAR ALL THE BUTTONS CLICKED 
			b1.unSelectCard();
			b2.unSelectCard();
			b3.unSelectCard();
			b4.unSelectCard();
			b5.unSelectCard();
			b6.unSelectCard();
			b7.unSelectCard();
			b8.unSelectCard();
			//NOW CLEAR THE CARDS CLICKED VECTOR
			for (int i = 0; i < cardsClicked.size(); i++)
			{
				cardsClicked[i] = false;
			}
			discardCount--;
		}


	}

	if (nbc == 2 && isPair(temp))
	{
		pair = 1;
		prio = 2;
		Multip = 2;
		NumbToMult = 10;
		MM.drawCustom(window, "Pair", sf::Vector2f(145, 428), 20, sf::Color(255, 255, 255, 255));

		if (playB.checkClickedButton(cursCoords) && prio == 2)
		{
			if (canClickPlay)
			{
				handsCount--;

				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				TextPlayedAnnouncement = true;
				handPlayed = "Pair";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (find(temp.begin(), temp.end(), hand[i]) == temp.end())
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();

				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				temp.clear();
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				pair = false;
				return;
			}

		}
	}
	checkToaddCards();
	if (TextPlayedAnnouncement)
	{
		if (playedPairCD > 0)
		{
			playedPairCD--;

			MM.drawHANDPLAYED(window, handPlayed);
		}
		else
		{
			TextPlayedAnnouncement = false;
			playedPairCD = 300;
		}

	}

	if (nbc == 3)
	{

		if (isThreeOfAKind(temp))
		{
			if (prio <= 4)
			{
				prio = 4;
				Multip = 3;
				NumbToMult = 20;
				MM.drawCustom(window, "Three Of A Kind", sf::Vector2f(100, 435), 20, sf::Color(255, 255, 255, 255));
			}


			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 4)
			{
				prio = 0;
				handsCount--;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				TextPlayedAnnouncement = true;
				handPlayed = "Three Of A Kind";
				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}

	}
	if (nbc == 4)
	{

		if (isTwoPair(temp))
		{

			if (prio <= 3)
			{
				twoPairsSaved = temp;

				prio = 3;
				pair = false;
				threeofakind = false;
				Multip = 2;
				NumbToMult = 20;
				MM.drawCustom(window, "Two Pairs", sf::Vector2f(117, 435), 20, sf::Color(255, 255, 255, 255));
			}

			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 3)
			{
				prio = 0;
				handsCount--;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;

				TextPlayedAnnouncement = true;
				handPlayed = "Two Pairs";
				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}

	}
	//checking for Four of a kind
	if (nbc == 4)
	{

		if (isFourOfAKind(temp))
		{
			if (prio <= 8)
			{
				prio = 8;

				Multip = 5;
				NumbToMult = 60;
				MM.drawCustom(window, "Four Of A Kind", sf::Vector2f(117, 435), 20, sf::Color(255, 255, 255, 255));
			}

			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 8)
			{
				prio = 0;
				handsCount--;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				TextPlayedAnnouncement = true;
				handPlayed = "Four Of A Kind";
				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}

	}



	if (nbc == 5)
	{
		//checking for straight flush
		if (isStraightFlush(temp))
		{
			if (prio <= 9)
			{
				prio = 9;
				NumbToMult = 100;
				Multip = 8;
				MM.drawCustom(window, "Straight Flush", sf::Vector2f(70, 430), 20, sf::Color(255, 255, 255, 255));
			}
			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 9)
			{
				prio = 0;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				handsCount--;
				needToAddCards = true;
				handPlayed = "Straight Flush";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}
		//checking for full house
		else if (isFullHouse(temp))
		{
			if (prio <= 7)
			{
				prio = 7;
				NumbToMult = 40;
				Multip = 4;
				MM.drawCustom(window, "Full House", sf::Vector2f(120, 380), 30, sf::Color(255, 255, 255, 255));
				fullhouse = true;
			}
			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 7)
			{
				prio = 0;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				handsCount--;
				needToAddCards = true;
				handPlayed = "Full House";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				fullhouse = false;
				prio = 0;
				return;
			}


		}

		//checking for flush
		else if (isFlush(temp))
		{
			if (prio <= 6)
			{
				prio = 6;
				NumbToMult = 40;
				Multip = 3;
				MM.drawCustom(window, "Flush", sf::Vector2f(120, 435), 26, sf::Color(255, 255, 255, 255));
			}
			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 6)
			{
				prio = 0;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				handsCount--;
				needToAddCards = true;
				handPlayed = "STRAIGHT";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}

		//checking for straight
		else if (isStraight(temp))
		{
			if (prio <= 5)
			{
				prio = 5;
				NumbToMult = 30;
				Multip = 3;
				MM.drawCustom(window, "Straight", sf::Vector2f(120, 380), 30, sf::Color(255, 255, 255, 255));
			}
			if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 5)
			{
				prio = 0;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				for (auto& x : tempVector)
				{
					if (x == 1 || x > 9)
						NumbToMult += 10;
					else
						NumbToMult += x;
				}
				Score += NumbToMult * Multip;
				handsCount--;
				needToAddCards = true;
				handPlayed = "STRAIGHT";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}

		}








	}



	if (prio < 2)
		pair = false;
	if (nbc >= 1)
	{
		if (nbc == 1)
			prio = 1;
		if (isHighCard(temp) && !pair && !threeofakind && prio < 2)
		{
			prio = 1;
			pair = false;

			NumbToMult = 5;
			Multip = 1;
			MM.drawCustom(window, "High Card", sf::Vector2f(85, 430), 20, sf::Color(255, 255, 255, 255));
			if (playB.checkClickedButton(cursCoords) && canClickPlay)
			{
				prio = 0;
				std::vector<int>tempVector = convertCardsToNumbers(temp);
				std::vector<int>::iterator result;

				if (tempVector.size() > 0)
				{
					result = std::max_element(tempVector.begin(), tempVector.end());
					if (*result == 1)
						NumbToMult += 10;
					else
						NumbToMult += *result;
				}
				Score += NumbToMult * Multip;
				handsCount--;
				handPlayed = "High Card";

				for (int i = 0; i < canClick.size(); i++)
				{
					canClick[i] = 0;
				}
				std::vector<std::string>tempvect;
				for (int i = 0; i < hand.size(); i++)
				{
					if (!search1(temp, hand[i]))
					{
						tempvect.push_back(hand[i]);
					}
				}
				hand.clear();
				hand = tempvect;
				tempvect.clear();
				temp.clear();
				canClickPlay = 0;
				//CLEAR ALL THE BUTTONS CLICKED 
				b1.unSelectCard();
				b2.unSelectCard();
				b3.unSelectCard();
				b4.unSelectCard();
				b5.unSelectCard();
				b6.unSelectCard();
				b7.unSelectCard();
				b8.unSelectCard();
				//NOW CLEAR THE CARDS CLICKED VECTOR
				for (int i = 0; i < cardsClicked.size(); i++)
				{
					cardsClicked[i] = false;
				}
				needToAddCards = true;
				NumbToMult = 0;
				Multip = 0;
				prio = 0;
				return;
			}
			NumbToMult = 0;
			Multip = 0;

		}

		std::vector<std::string>temp2;
		//checking for pair
		if (nbc >= 2 && prio <= 2)
		{
			temp2.clear();
			if (isPair({ temp[0],temp[1] }))
			{
				temp2 = { temp[0],temp[1] };
				pair = true;
			}
			if (nbc >= 3)
			{
				if (isPair({ temp[1],temp[2] }))
				{
					temp2 = { temp[1],temp[2] };
					pair = true;
				}
			}
			if (nbc >= 4)
			{
				if (isPair({ temp[2],temp[3] }))
				{
					temp2 = { temp[2],temp[3] };
					pair = true;
				}
			}
			if (nbc >= 5)
			{
				if (isPair({ temp[3],temp[4] }))
				{
					temp2 = { temp[3],temp[4] };
					pair = true;
				}
			}
			if (pair && !threeofakind && !fourofakind)
			{
				std::vector<int>tempVector = convertCardsToNumbers(temp2);

				prio = 2;
				Multip = 2;
				NumbToMult = 10;
				MM.drawCustom(window, "Pair", sf::Vector2f(145, 428), 20, sf::Color(255, 255, 255, 255));

				if (playB.checkClickedButton(cursCoords))
				{
					if (canClickPlay)
					{
						handsCount--;

						std::vector<int>tempVector = convertCardsToNumbers(temp2);

						for (auto& x : tempVector)
						{
							if (x == 1 || x > 9)
								NumbToMult += 10;
							else
								NumbToMult += x;
						}
						Score += NumbToMult * Multip;
						TextPlayedAnnouncement = true;
						handPlayed = "Pair";

						for (int i = 0; i < canClick.size(); i++)
						{
							canClick[i] = 0;
						}
						std::vector<std::string>tempvect;
						for (int i = 0; i < hand.size(); i++)
						{
							if (find(temp.begin(), temp.end(), hand[i]) == temp.end())
							{
								tempvect.push_back(hand[i]);
							}
						}
						hand.clear();
						hand = tempvect;
						tempvect.clear();

						canClickPlay = 0;
						//CLEAR ALL THE BUTTONS CLICKED 
						b1.unSelectCard();
						b2.unSelectCard();
						b3.unSelectCard();
						b4.unSelectCard();
						b5.unSelectCard();
						b6.unSelectCard();
						b7.unSelectCard();
						b8.unSelectCard();
						//NOW CLEAR THE CARDS CLICKED VECTOR
						for (int i = 0; i < cardsClicked.size(); i++)
						{
							cardsClicked[i] = false;
						}
						temp.clear();
						temp2.clear();
						needToAddCards = true;
						NumbToMult = 0;
						Multip = 0;
						pair = false;
						prio = 0;
						return;
					}

				}

			}


		}
		//checking for 2 pairs
		if (nbc >= 4 && prio <= 3 && !threeofakind && !fourofakind)
		{

			temp2.clear();
			temp2 = twoPairsSaved;
			std::vector<int>tempVector = convertCardsToNumbers(temp2);
			std::vector<int>tempIntVector = convertCardsToNumbers(twoPairsSaved);
			std::vector<int>tempIntVector2 = convertCardsToNumbers(temp);
			bool test1 = twoPairsSaved.size() > 0;
			for (auto& element : tempIntVector)
			{
				if (count(tempIntVector2.begin(), tempIntVector2.end(), element) != 2)
				{
					test1 = false;
				}
			}
			if (test1)
			{
				twopair = true;
			}



			if (twopair)
			{

				prio = 3;
				Multip = 2;
				NumbToMult = 20;
				MM.drawCustom(window, "Two Pairs", sf::Vector2f(117, 435), 20, sf::Color(255, 255, 255, 255));
				if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 3)
				{
					prio = 0;
					handsCount--;
					for (auto& x : tempVector)
					{
						if (x == 1 || x > 9)
							NumbToMult += 10;
						else
							NumbToMult += x;
					}
					Score += NumbToMult * Multip;
					TextPlayedAnnouncement = true;
					handPlayed = "Two Pairs";
					for (int i = 0; i < canClick.size(); i++)
					{
						canClick[i] = 0;
					}
					std::vector<std::string>tempvect;
					for (int i = 0; i < hand.size(); i++)
					{
						if (!search1(temp, hand[i]))
						{
							tempvect.push_back(hand[i]);
						}
					}
					hand.clear();
					hand = tempvect;
					tempvect.clear();
					temp.clear();
					canClickPlay = 0;
					//CLEAR ALL THE BUTTONS CLICKED 
					b1.unSelectCard();
					b2.unSelectCard();
					b3.unSelectCard();
					b4.unSelectCard();
					b5.unSelectCard();
					b6.unSelectCard();
					b7.unSelectCard();
					b8.unSelectCard();
					//NOW CLEAR THE CARDS CLICKED VECTOR
					for (int i = 0; i < cardsClicked.size(); i++)
					{
						cardsClicked[i] = false;
					}
					needToAddCards = true;
					NumbToMult = 0;
					Multip = 0;
					prio = 0;
					twopair = 0;
					return;
				}
				//twopair = 0;

			}


		}
		//checking for 3 of a kind
		if (nbc >= 3 && prio <= 4)
		{
			temp2.clear();
			if (isThreeOfAKind({ temp[0] , temp[1] , temp[2] }))
			{
				temp2 = { temp[0] , temp[1] , temp[2] };
				threeofakind = true;
			}
			if (nbc >= 4)
			{
				if (isThreeOfAKind({ temp[1] , temp[2] , temp[3] }))
				{
					temp2 = { temp[1] , temp[2] , temp[3] };
					threeofakind = true;
				}

			}
			if (nbc == 5)
			{
				if (isThreeOfAKind({ temp[2] , temp[3] , temp[4] }))
				{
					temp2 = { temp[2] , temp[3] , temp[4] };
					threeofakind = true;
				}
			}
			if (threeofakind)
			{
				if (prio <= 4)
				{
					prio = 4;
					Multip = 3;
					NumbToMult = 20;
					MM.drawCustom(window, "Three Of A Kind", sf::Vector2f(100, 435), 20, sf::Color(255, 255, 255, 255));
				}


				if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 4)
				{
					prio = 0;
					handsCount--;
					std::vector<int>tempVector = convertCardsToNumbers(temp2);
					for (auto& x : tempVector)
					{
						if (x == 1 || x > 9)
							NumbToMult += 10;
						else
							NumbToMult += x;
					}
					Score += NumbToMult * Multip;
					TextPlayedAnnouncement = true;
					handPlayed = "Three Of A Kind";
					for (int i = 0; i < canClick.size(); i++)
					{
						canClick[i] = 0;
					}
					std::vector<std::string>tempvect;
					for (int i = 0; i < hand.size(); i++)
					{
						if (!search1(temp, hand[i]))
						{
							tempvect.push_back(hand[i]);
						}
					}
					hand.clear();
					hand = tempvect;
					tempvect.clear();
					temp.clear();
					canClickPlay = 0;
					//CLEAR ALL THE BUTTONS CLICKED 
					b1.unSelectCard();
					b2.unSelectCard();
					b3.unSelectCard();
					b4.unSelectCard();
					b5.unSelectCard();
					b6.unSelectCard();
					b7.unSelectCard();
					b8.unSelectCard();
					//NOW CLEAR THE CARDS CLICKED VECTOR
					for (int i = 0; i < cardsClicked.size(); i++)
					{
						cardsClicked[i] = false;
					}
					needToAddCards = true;
					NumbToMult = 0;
					Multip = 0;
					prio = 0;
					return;
				}
				threeofakind = 0;

			}





		}
		//checking for 4 of a kind
		if (nbc >= 4 && prio <= 8)
		{
			temp2.clear();
			if (isFourOfAKind({ temp[0] , temp[1] , temp[2], temp[3] }))
			{
				temp2 = { temp[0] , temp[1] , temp[2], temp[3] };
				fourofakind = true;
			}
			if (nbc == 5)
			{
				if (isFourOfAKind({ temp[1] , temp[2], temp[3], temp[4] }))
				{
					temp2 = { temp[1] , temp[2], temp[3], temp[4] };
					fourofakind = true;
				}
			}
			if (fourofakind)
			{
				if (prio <= 8)
				{
					prio = 8;

					Multip = 5;
					NumbToMult = 60;
					MM.drawCustom(window, "Four Of A Kind", sf::Vector2f(117, 435), 20, sf::Color(255, 255, 255, 255));
				}

				if (playB.checkClickedButton(cursCoords) && canClickPlay && prio == 8)
				{
					prio = 0;
					handsCount--;
					std::vector<int>tempVector = convertCardsToNumbers(temp2);
					for (auto& x : tempVector)
					{
						if (x == 1 || x > 9)
							NumbToMult += 10;
						else
							NumbToMult += x;
					}
					Score += NumbToMult * Multip;
					TextPlayedAnnouncement = true;
					handPlayed = "Four Of A Kind";
					for (int i = 0; i < canClick.size(); i++)
					{
						canClick[i] = 0;
					}
					std::vector<std::string>tempvect;
					for (int i = 0; i < hand.size(); i++)
					{
						if (!search1(temp, hand[i]))
						{
							tempvect.push_back(hand[i]);
						}
					}
					hand.clear();
					hand = tempvect;
					tempvect.clear();
					temp.clear();
					canClickPlay = 0;
					//CLEAR ALL THE BUTTONS CLICKED 
					b1.unSelectCard();
					b2.unSelectCard();
					b3.unSelectCard();
					b4.unSelectCard();
					b5.unSelectCard();
					b6.unSelectCard();
					b7.unSelectCard();
					b8.unSelectCard();
					//NOW CLEAR THE CARDS CLICKED VECTOR
					for (int i = 0; i < cardsClicked.size(); i++)
					{
						cardsClicked[i] = false;
					}
					needToAddCards = true;
					NumbToMult = 0;
					Multip = 0;
					prio = 0;
					return;
				}

			}






		}




	}





	//checking if removed a card from four of a kind and still valid or not
	if (fourofakind && nbc > 3)
	{
		std::vector<std::string>temp2;
		std::vector<std::string>temp3;

		temp2 = { temp[0],temp[1], temp[2], temp[3] };
		if (nbc == 5)
		{
			temp3 = { temp[1], temp[2], temp[3],temp[4] };
		}
		if (nbc == 5)
		{
			if (!isFourOfAKind(temp2) && !isFourOfAKind(temp3))
			{
				fourofakind = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 4)
		{
			if (!isFourOfAKind(temp2))
			{
				fourofakind = 0;
				prio = 0;
				return;
			}

		}
		else if (nbc < 4)
		{
			fourofakind = 0;
			prio = 0;
			return;
		}


	}





	if (nbc < 5 && fullhouse)
	{
		fullhouse = 0;
		prio = 0;
	}
	if (nbc < 4 && twopair)
	{
		twopair = 0;
		prio = 0;
	}
	if (nbc < 4 && fourofakind)
	{
		fourofakind = 0;
		prio = 0;
	}




	if (prio == 0)
	{
		pair = false;
		threeofakind = false;
		fullhouse = false;
		fourofakind = false;
		twopair = false;
	}
	else if (prio == 2)
	{
		pair = true;
		threeofakind = false;
		fullhouse = false;
		fourofakind = false;
		twopair = false;
	}
	else if (prio == 3)
	{
		pair = false;
		threeofakind = false;
		fullhouse = false;
		fourofakind = false;
		twopair = true;
	}
	else if (prio == 4)
	{
		pair = false;
		threeofakind = true;
		fullhouse = false;
		fourofakind = false;
		twopair = false;
	}
	else if (prio == 7)
	{
		pair = false;
		threeofakind = false;
		fullhouse = true;
		fourofakind = false;
		twopair = false;
	}



	if (fourofakind)
	{
		threeofakind = false;
	}

	//checking if removed a card from three of a kind and still valid or not
	if (threeofakind && nbc > 2)
	{
		std::vector<std::string>temp2;
		std::vector<std::string>temp3;
		std::vector<std::string>temp4;

		temp2 = { temp[0],temp[1], temp[2] };


		if (nbc >= 4)
		{
			temp3 = { temp[1], temp[2], temp[3] };
		}
		if (nbc == 5)
		{
			temp4 = { temp[2], temp[3],temp[4] };
		}
		if (nbc == 5)
		{
			if (!isThreeOfAKind(temp2) && !isThreeOfAKind(temp3) && !isThreeOfAKind(temp4))
			{
				threeofakind = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 4)
		{
			if (!isThreeOfAKind(temp2) && !isThreeOfAKind(temp3))
			{
				threeofakind = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 3)
		{
			if (!isThreeOfAKind(temp2))
			{
				threeofakind = 0;
				prio = 0;
				return;
			}

		}


	}
	std::vector<int>tempIntVector = convertCardsToNumbers(twoPairsSaved);
	std::vector<int>tempIntVector2 = convertCardsToNumbers(temp);

	if (twopair)
	{


		for (auto& element : tempIntVector)
		{
			if (count(tempIntVector2.begin(), tempIntVector2.end(), element) != 2)
			{
				twopair = 0;
				prio = 0;
				return;
			}
		}
	}
	//checking if removed a card in a pair hand
	if (pair &&nbc>	1)
	{
		if(nbc == 5)
		{
			if (!isPair({ temp[0],temp[1] })	&& !isPair({ temp[1],temp[2] }) && !isPair({ temp[2],temp[3] }) && !isPair({ temp[3],temp[4] }))
			{
				pair = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 4)
		{
			if (!isPair({ temp[0],temp[1] }) && !isPair({ temp[1],temp[2] }) && !isPair({ temp[2],temp[3] }))
			{
				pair = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 3)
		{
			if (!isPair({ temp[0],temp[1] }) && !isPair({ temp[1],temp[2] }) )
			{
				pair = 0;
				prio = 0;
				return;
			}
		}
		else if (nbc == 2)
		{
			if (!isPair({ temp[0],temp[1] }))
			{
				pair = 0;
				prio = 0;
				return;
			}
		}

	}





	CDtoPlay();
	MM.drawCustom(window, std::to_string(Score), sf::Vector2f(195, 320), 30, sf::Color(255, 255, 255, 255));
}



void Deck::updateButtons(sf::Vector2f cursCoords, sf::RenderWindow* window)
{
	int HC = hand.size();

	if (HC == 8)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		b4.update(cursCoords);
		b5.update(cursCoords);
		b6.update(cursCoords);
		b7.update(cursCoords);
		b8.update(cursCoords);
		if (b8.checkClickedButton(cursCoords))
		{
			if (canClick[7])
			{
				if (cardsClicked[7] == false && nbClicked() <= 4)
				{
					cardsClicked[7] = true;
					b8.selectCard();

				}
				else
				{
					cardsClicked[7] = false;
					b8.unSelectCard();
				}
			}
			canClick[7] = false;
			if (!canClick[7])
			{
				if (clickingCD[7] >= 0)
				{
					clickingCD[7]--;
				}
				else
				{
					clickingCD[7] = 60;
					canClick[7] = true;
				}

			}
		}

		if (b7.checkClickedButton(cursCoords))
		{
			if (canClick[6])
			{
				if (cardsClicked[6] == false && nbClicked() <= 4)
				{
					cardsClicked[6] = true;
					b7.selectCard();

				}
				else
				{
					cardsClicked[6] = false;
					b7.unSelectCard();
				}
			}
			canClick[6] = false;
			if (!canClick[6])
			{
				if (clickingCD[6] >= 0)
				{
					clickingCD[6]--;
				}
				else
				{
					clickingCD[6] = 60;
					canClick[6] = true;
				}

			}
		}
		if (b6.checkClickedButton(cursCoords))
		{
			if (canClick[5])
			{
				if (cardsClicked[5] == false && nbClicked() <= 4)
				{
					cardsClicked[5] = true;
					b6.selectCard();

				}
				else
				{
					cardsClicked[5] = false;
					b6.unSelectCard();
				}
			}
			canClick[5] = false;
			if (!canClick[5])
			{
				if (clickingCD[5] >= 0)
				{
					clickingCD[5]--;
				}
				else
				{
					clickingCD[5] = 60;
					canClick[5] = true;
				}

			}
		}
		if (b5.checkClickedButton(cursCoords))
		{
			if (canClick[4])
			{
				if (cardsClicked[4] == false && nbClicked() <= 4)
				{
					cardsClicked[4] = true;
					b5.selectCard();

				}
				else
				{
					cardsClicked[4] = false;
					b5.unSelectCard();
				}
			}
			canClick[4] = false;
			if (!canClick[4])
			{
				if (clickingCD[4] >= 0)
				{
					clickingCD[4]--;
				}
				else
				{
					clickingCD[4] = 60;
					canClick[4] = true;
				}

			}
		}
		if (b4.checkClickedButton(cursCoords))
		{
			if (canClick[3])
			{
				if (cardsClicked[3] == false && nbClicked() <= 4)
				{
					cardsClicked[3] = true;
					b4.selectCard();

				}
				else
				{
					cardsClicked[3] = false;
					b4.unSelectCard();
				}
			}
			canClick[3] = false;
			if (!canClick[3])
			{
				if (clickingCD[3] >= 0)
				{
					clickingCD[3]--;
				}
				else
				{
					clickingCD[3] = 60;
					canClick[3] = true;
				}

			}
		}
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false && nbClicked() <= 4)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false && nbClicked() <= 4)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false && nbClicked() <= 4)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 7)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		b4.update(cursCoords);
		b5.update(cursCoords);
		b6.update(cursCoords);
		b7.update(cursCoords);
		if (b7.checkClickedButton(cursCoords))
		{
			if (canClick[6])
			{
				if (cardsClicked[6] == false && nbClicked() <= 4)
				{
					cardsClicked[6] = true;
					b7.selectCard();

				}
				else
				{
					cardsClicked[6] = false;
					b7.unSelectCard();
				}
			}
			canClick[6] = false;
			if (!canClick[6])
			{
				if (clickingCD[6] >= 0)
				{
					clickingCD[6]--;
				}
				else
				{
					clickingCD[6] = 60;
					canClick[6] = true;
				}

			}
		}
		if (b6.checkClickedButton(cursCoords))
		{
			if (canClick[5])
			{
				if (cardsClicked[5] == false && nbClicked() <= 4)
				{
					cardsClicked[5] = true;
					b6.selectCard();

				}
				else
				{
					cardsClicked[5] = false;
					b6.unSelectCard();
				}
			}
			canClick[5] = false;
			if (!canClick[5])
			{
				if (clickingCD[5] >= 0)
				{
					clickingCD[5]--;
				}
				else
				{
					clickingCD[5] = 60;
					canClick[5] = true;
				}

			}
		}
		if (b5.checkClickedButton(cursCoords))
		{
			if (canClick[4])
			{
				if (cardsClicked[4] == false && nbClicked() <= 4)
				{
					cardsClicked[4] = true;
					b5.selectCard();

				}
				else
				{
					cardsClicked[4] = false;
					b5.unSelectCard();
				}
			}
			canClick[4] = false;
			if (!canClick[4])
			{
				if (clickingCD[4] >= 0)
				{
					clickingCD[4]--;
				}
				else
				{
					clickingCD[4] = 60;
					canClick[4] = true;
				}

			}
		}
		if (b4.checkClickedButton(cursCoords))
		{
			if (canClick[3])
			{
				if (cardsClicked[3] == false && nbClicked() <= 4)
				{
					cardsClicked[3] = true;
					b4.selectCard();

				}
				else
				{
					cardsClicked[3] = false;
					b4.unSelectCard();
				}
			}
			canClick[3] = false;
			if (!canClick[3])
			{
				if (clickingCD[3] >= 0)
				{
					clickingCD[3]--;
				}
				else
				{
					clickingCD[3] = 60;
					canClick[3] = true;
				}

			}
		}
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false && nbClicked() <= 4)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false && nbClicked() <= 4)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false && nbClicked() <= 4)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 6)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		b4.update(cursCoords);
		b5.update(cursCoords);
		b6.update(cursCoords);
		if (b6.checkClickedButton(cursCoords))
		{
			if (canClick[5])
			{
				if (cardsClicked[5] == false && nbClicked() <= 4)
				{
					cardsClicked[5] = true;
					b6.selectCard();

				}
				else
				{
					cardsClicked[5] = false;
					b6.unSelectCard();
				}
			}
			canClick[5] = false;
			if (!canClick[5])
			{
				if (clickingCD[5] >= 0)
				{
					clickingCD[5]--;
				}
				else
				{
					clickingCD[5] = 60;
					canClick[5] = true;
				}

			}
		}
		if (b5.checkClickedButton(cursCoords))
		{
			if (canClick[4])
			{
				if (cardsClicked[4] == false && nbClicked() <= 4)
				{
					cardsClicked[4] = true;
					b5.selectCard();

				}
				else
				{
					cardsClicked[4] = false;
					b5.unSelectCard();
				}
			}
			canClick[4] = false;
			if (!canClick[4])
			{
				if (clickingCD[4] >= 0)
				{
					clickingCD[4]--;
				}
				else
				{
					clickingCD[4] = 60;
					canClick[4] = true;
				}

			}
		}
		if (b4.checkClickedButton(cursCoords))
		{
			if (canClick[3])
			{
				if (cardsClicked[3] == false && nbClicked() <= 4)
				{
					cardsClicked[3] = true;
					b4.selectCard();

				}
				else
				{
					cardsClicked[3] = false;
					b4.unSelectCard();
				}
			}
			canClick[3] = false;
			if (!canClick[3])
			{
				if (clickingCD[3] >= 0)
				{
					clickingCD[3]--;
				}
				else
				{
					clickingCD[3] = 60;
					canClick[3] = true;
				}

			}
		}
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false && nbClicked() <= 4)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false && nbClicked() <= 4)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false && nbClicked() <= 4)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 5)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		b4.update(cursCoords);
		b5.update(cursCoords);
		if (b5.checkClickedButton(cursCoords))
		{
			if (canClick[4])
			{
				if (cardsClicked[4] == false)
				{
					cardsClicked[4] = true;
					b5.selectCard();

				}
				else
				{
					cardsClicked[4] = false;
					b5.unSelectCard();
				}
			}
			canClick[4] = false;
			if (!canClick[4])
			{
				if (clickingCD[4] >= 0)
				{
					clickingCD[4]--;
				}
				else
				{
					clickingCD[4] = 60;
					canClick[4] = true;
				}

			}
		}
		if (b4.checkClickedButton(cursCoords))
		{
			if (canClick[3])
			{
				if (cardsClicked[3] == false)
				{
					cardsClicked[3] = true;
					b4.selectCard();

				}
				else
				{
					cardsClicked[3] = false;
					b4.unSelectCard();
				}
			}
			canClick[3] = false;
			if (!canClick[3])
			{
				if (clickingCD[3] >= 0)
				{
					clickingCD[3]--;
				}
				else
				{
					clickingCD[3] = 60;
					canClick[3] = true;
				}

			}
		}
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 4)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		b4.update(cursCoords);
		if (b4.checkClickedButton(cursCoords))
		{
			if (canClick[3])
			{
				if (cardsClicked[3] == false)
				{
					cardsClicked[3] = true;
					b4.selectCard();

				}
				else
				{
					cardsClicked[3] = false;
					b4.unSelectCard();
				}
			}
			canClick[3] = false;
			if (!canClick[3])
			{
				if (clickingCD[3] >= 0)
				{
					clickingCD[3]--;
				}
				else
				{
					clickingCD[3] = 60;
					canClick[3] = true;
				}

			}
		}
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 3)
	{

		b1.update(cursCoords);
		b2.update(cursCoords);
		b3.update(cursCoords);
		if (b3.checkClickedButton(cursCoords))
		{
			if (canClick[2])
			{
				if (cardsClicked[2] == false)
				{
					cardsClicked[2] = true;
					b3.selectCard();

				}
				else
				{
					cardsClicked[2] = false;
					b3.unSelectCard();
				}
			}
			canClick[2] = false;
			if (!canClick[2])
			{
				if (clickingCD[2] >= 0)
				{
					clickingCD[2]--;
				}
				else
				{
					clickingCD[2] = 60;
					canClick[2] = true;
				}

			}
		}
		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 2)
	{
		b1.update(cursCoords);
		b2.update(cursCoords);

		if (b2.checkClickedButton(cursCoords))
		{
			if (canClick[1])
			{
				if (cardsClicked[1] == false)
				{
					cardsClicked[1] = true;
					b2.selectCard();

				}
				else
				{
					cardsClicked[1] = false;
					b2.unSelectCard();
				}
			}
			canClick[1] = false;
			if (!canClick[1])
			{
				if (clickingCD[1] >= 0)
				{
					clickingCD[1]--;
				}
				else
				{
					clickingCD[1] = 60;
					canClick[1] = true;
				}

			}
		}
		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
	else if (HC == 1)
	{
		b1.update(cursCoords);

		if (b1.checkClickedButton(cursCoords))
		{
			if (canClick[0])
			{
				if (cardsClicked[0] == false)
				{
					cardsClicked[0] = true;
					b1.selectCard();

				}
				else
				{
					cardsClicked[0] = false;
					b1.unSelectCard();
				}
			}
			canClick[0] = false;
			if (!canClick[0])
			{
				if (clickingCD[0] >= 0)
				{
					clickingCD[0]--;
				}
				else
				{
					clickingCD[0] = 60;
					canClick[0] = true;
				}

			}
		}
	}
}



bool Deck::search1(std::vector<std::string> v, std::string elem)
{
	if (v.size() < 1)
		return false;
	for (auto& x : v)
	{
		if (x == elem)
			return true;
	}

	return false;
}


void Deck::CDtoPlay()
{
	if (!canClickPlay)
	{
		if (canplayCD > 0)
		{
			canplayCD--;
		}
		else
		{
			canClickPlay = 1;
			canplayCD = 300;
		}
	}
}

void Deck::cannotClick()
{
	if (!canClick[0])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[1])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[2])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[3])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[4])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[5])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[6])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}

	}
	if (!canClick[7])
	{
		if (clickingCD[0] >= 0)
		{
			clickingCD[0]--;
		}
		else
		{
			clickingCD[0] = 60;
			canClick[0] = true;
		}
	}
}

std::vector<std::string> Deck::cardsnamesclicked()
{
	std::vector<std::string> temp;
	for (int c = 0; c < hand.size(); c++)
	{
		if (cardsClicked[c])
		{
			temp.push_back(hand[c]);
		}
	}
	return temp;
}


bool Deck::isPair(std::vector<std::string > cc)
{
	if (cc.size() <= 1)
		return false;
	std::string card1 = cc[0];
	std::string card2 = cc[1];
	if (card1.length() == card2.length())
	{
		if (card1.length() == 2)
		{
			if (card1[0] == card2[0])
				return true;
		}
		else
		{
			if (card1.length() == 3)
			{
				if (card1[0] == card2[0] && card1[1] == card2[1])
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool Deck::isTwoPair(std::vector<std::string > cc)
{
	if (cc.size() < 4)
		return false;
	std::vector<int> tempCardPicked = convertCardsToNumbers(cc);

	std::vector<int> tempV;
	for (auto& x : tempCardPicked)
	{
		if (find(tempV.begin(), tempV.end(), x) == tempV.end())
		{
			tempV.push_back(x);
		}
	}

	if (count(tempCardPicked.begin(), tempCardPicked.end(), tempV[0]) != 2 || count(tempCardPicked.begin(), tempCardPicked.end(), tempV[1]) != 2)
		return false;

	return true;
}



bool Deck::isThreeOfAKind(std::vector<std::string > cc)
{
	if (cc.size() <= 2)
		return false;
	std::string card1 = cc[0];
	std::string card2 = cc[1];
	std::string card3 = cc[2];
	if (card1.length() == card2.length() && card2.length() == card3.length())
	{
		if (card1.length() == 2)
		{
			if (card1[0] == card2[0] && card2[0] == card3[0])
				return true;
		}
		else
		{
			if (card1.length() == 3)
			{
				if (card1[0] == card2[0] && card2[0] == card3[0] && card1[1] == card2[1] && card2[1] == card3[1])
				{
					return true;
				}
			}
		}
	}
	return false;




}


bool Deck::isHighCard(std::vector<std::string> cc)
{
	if (cc.size() == 1)
		return true;


	if (cc.size() == 5)
	{
		return (!isStraightFlush(cc) && !isStraight(cc) && !isFlush(cc) && !isFullHouse(cc));
	}
	if (cc.size() == 4)
	{
		return (!isFourOfAKind(cc) && !isTwoPair(cc));
	}
	if (cc.size() == 3)
	{
		return !isThreeOfAKind(cc);
	}
	if (cc.size() == 2)
	{
		return !isPair(cc);
	}
	return true;
}



bool Deck::isStraight(std::vector<std::string > cc)
{
	if (cc.size() <= 4)
		return false;

	std::vector<int> tempCardPicked = convertCardsToNumbers(cc);

	sort(tempCardPicked.begin(), tempCardPicked.end());

	if (checkDiff(tempCardPicked))
		return true;

	if (checkDiffWithA(tempCardPicked))
	{
		return true;
	}

	return false;
}

bool Deck::isFullHouse(std::vector<std::string> cc)
{
	std::vector<int> tempV = convertCardsToNumbers(cc);
	sort(tempV.begin(), tempV.end());
	std::vector<int> tempV2;
	for (auto& x : tempV)
	{
		if (find(tempV2.begin(), tempV2.end(), x) == tempV2.end())
		{
			tempV2.push_back(x);
		}
	}
	int nbe1 = std::count(tempV.begin(), tempV.end(), tempV2[0]);
	int nbe2 = std::count(tempV.begin(), tempV.end(), tempV2[1]);


	if (nbe1 < 2 || nbe2 < 2)
		return false;

	if (nbe1 == 3)
	{
		if (nbe2 == 2)
		{
			return true;
		}
	}
	if (nbe2 == 3)
	{
		if (nbe1 == 2)
		{
			return true;
		}
	}


	return false;
}

bool Deck::isFourOfAKind(std::vector<std::string> cc)
{
	if (cc.size() < 4)
		return false;

	std::vector<int> tempvector = convertCardsToNumbers(cc);

	int nb = std::count(tempvector.begin(), tempvector.end(), tempvector[0]);

	if (nb == 4)
		return true;


	return false;
}




std::vector<int> Deck::convertCardsToNumbers(std::vector<std::string> cc)
{

	std::vector<int> tempCardPicked;

	for (auto& S : cc)
	{
		std::string tempCard = S;
		if (tempCard.length() == 2)
		{
			tempCard = tempCard[0];
		}
		else
		{
			tempCard = tempCard.substr(0, 2);
		}
		tempCardPicked.push_back(stoi(tempCard));
	}
	return tempCardPicked;
}

bool Deck::checkDiff(std::vector<int> cc)
{
	int d = cc[1] - cc[0];
	for (int i = 2; i < cc.size(); i++)
	{
		int y = cc[i] - cc[i - 1];
		if (y != d)
			return false;
	}
	return true;
}
bool Deck::checkDiffWithA(std::vector<int> cc)
{
	if (cc[0] != 1)
		return false;

	cc[0] = 14;
	sort(cc.begin(), cc.end());
	int d = cc[1] - cc[0];
	for (int i = 2; i < cc.size(); i++)
	{
		int y = cc[i] - cc[i - 1];
		if (y != d)
			return false;
	}

	return true;
}



bool Deck::isFlush(std::vector<std::string> cc)
{


	if (cc.size() < 5) //check if picked 5 cards minimum for the flush
		return false;
	std::vector<char> TV;
	for (int i = 0; i < cc.size(); i++)
	{
		std::string tempString = cc[i];
		TV.push_back(tempString.back());
	}
	char first = TV[0];
	for (int i = 1; i < TV.size(); i++)
	{
		if (TV[i] != first)
		{
			return false;
		}

	}
	return true;

}

bool Deck::isStraightFlush(std::vector<std::string> cc)
{
	return (isFlush(cc) && isStraight(cc));
}




void Deck::resetDeck()
{
	cards.clear();
	cards.pb("1C");
	cards.pb("1D");
	cards.pb("1H");
	cards.pb("1S");
	cards.pb("2C");
	cards.pb("2D");
	cards.pb("2H");
	cards.pb("2S");
	cards.pb("3C");
	cards.pb("3D");
	cards.pb("3H");
	cards.pb("3S");
	cards.pb("4C");
	cards.pb("4D");
	cards.pb("4H");
	cards.pb("4S");
	cards.pb("5C");
	cards.pb("5D");
	cards.pb("5H");
	cards.pb("5S");
	cards.pb("6C");
	cards.pb("6D");
	cards.pb("6H");
	cards.pb("6S");
	cards.pb("7C");
	cards.pb("7D");
	cards.pb("7H");
	cards.pb("7S");
	cards.pb("8C");
	cards.pb("8D");
	cards.pb("8H");
	cards.pb("8S");
	cards.pb("9C");
	cards.pb("9D");
	cards.pb("9H");
	cards.pb("9S");
	cards.pb("10C");
	cards.pb("10D");
	cards.pb("10H");
	cards.pb("10S");
	cards.pb("11C");
	cards.pb("11D");
	cards.pb("11H");
	cards.pb("11S");
	cards.pb("12C");
	cards.pb("12D");
	cards.pb("12H");
	cards.pb("12S");
	cards.pb("13C");
	cards.pb("13D");
	cards.pb("13H");
	cards.pb("13S");
	hand.clear();
	cardsClicked.clear();
	canClick.clear();
	clickingCD.clear();
	fillHand();
	b1.unSelectCard();
	b2.unSelectCard();
	b3.unSelectCard();
	b4.unSelectCard();
	b5.unSelectCard();
	b6.unSelectCard();
	b7.unSelectCard();
	b8.unSelectCard();
	handsCount = 4;
	discardCount = 4;
}
int Deck::getDiscardsLeftCount()
{
	return discardCount;
}

int Deck::getHandsLeftCount()
{
	return handsCount;
}
std::vector<std::string> Deck::getHand()
{
	return hand;
}


std::vector<std::string> Deck::getDeck()
{
	return cards;
}
