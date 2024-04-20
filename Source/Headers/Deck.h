#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Deck
{
public:
    Deck();


    void fillHand();
    void checkToaddCards();
    void discardCards(std::vector<std::string> selectedC);

    void setRunTo(int handsLeftInRun, int discardsLeftInRun, std::vector<std::string> cardsinRun);


    bool checkIfFailed(int score);
    bool checkIfFinished(int score);

    void drawHand(sf::RenderWindow* window);

    void setMinimumScore(int mscore);

    std::vector<int> convertCardsToNumbers(std::vector<std::string> cc);

    sf::IntRect getTexture(std::string cardName);

    //hands evaluation
    bool isPair(std::vector<std::string > cc); // 2 cards make a 
    bool isTwoPair(std::vector<std::string > cc);// 4 cards make 2 pairs;

    bool isThreeOfAKind(std::vector<std::string > cc); // 3 cards make a 3 of a kind
    bool isStraight(std::vector<std::string > cc);//check if 5 cards make a straight
    bool checkDiff(std::vector<int> cc);
    bool checkDiffWithA(std::vector<int> cc);

    bool isFlush(std::vector<std::string> cc);

    bool isFullHouse(std::vector<std::string> cc);

    bool isFourOfAKind(std::vector<std::string> cc);

    bool isStraightFlush(std::vector<std::string> cc);
    bool isHighCard(std::vector<std::string> cc);


    void resetAllRun();

    void setRun(std::vector<std::string> handsaved, std::vector<std::string> deck, int discardsL, int handsL);



    void update(sf::Vector2f cursCoords, sf::RenderWindow* window, int& Score);
    void updateButtons(sf::Vector2f cursCoords, sf::RenderWindow* window);

    void cannotClick();

    void CDtoPlay();

    bool search1(std::vector<std::string> v, std::string elem);

    int nbClicked();

    void bubbleSort(std::vector<int>& intvector, int n);

    std::vector<std::string> cardsnamesclicked();


    void resetDeck();


    int getDiscardsLeftCount();
    int getHandsLeftCount();
    std::vector<std::string> getHand();

    std::vector<std::string> getDeck();

private:
    std::vector<std::string> cards;
    std::vector<bool> cardsClicked;
    std::vector<bool> canClick;
    std::vector<float> clickingCD;
    std::vector<std::string> twoPairsSaved;


    bool canClickPlay = 1;
    bool pair = false;
    bool threeofakind = false;
    bool fullhouse = false;
    bool fourofakind = false;
    bool twopair = false;
    float canplayCD = 300;
    std::vector<std::string> hand;
    sf::Texture cardsTexture;
    sf::Sprite cardsSprite;
    sf::Vector2f handPos;
    bool TextPlayedAnnouncement;
    std::string handPlayed;
    float playedPairCD = 300;
    bool needToAddCards = 0;
    bool canDiscard;
    int discardCount = 4;
    int Multip = 0;
    int NumbToMult = 0;
    int handsCount = 4;
    int minimumScore;
    int prio = 0;


};