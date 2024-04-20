#pragma once
#include <SFML/Graphics.hpp>


class TextManager
{
public:
    TextManager();


    void drawCardsLeftInDeck(sf::RenderWindow* window, int cards);

    void drawHANDPLAYED(sf::RenderWindow* window, std::string handName);

    void drawCustom(sf::RenderWindow* window, std::string str, sf::Vector2f position, int size, sf::Color color);

    void drawStartingTime(sf::RenderWindow* window, std::string str, const float timer);


    //Animation for text 
    void TextAnimation(sf::Text* text);


    //these are private variables that we use in functions
public:
    sf::Texture pairTexture;
    sf::Sprite pairSprite;
    sf::Text pair;
    sf::Font font;
    sf::Text play;
    sf::Text Score;
    sf::Text ScoreNUM;
    sf::Text Starting;
    sf::Text YouWonYouCanSkipText;
    sf::Text tip;
    sf::Text cardsLeft;
    int i = 0;
    short Loop = 1;
    sf::Text variableText;


};

