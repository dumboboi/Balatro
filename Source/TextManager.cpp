#include "TextManager.h"
#include "Global.h"
#include "iostream"

//this class is just to make things more clean so the game class wont be messy.
TextManager::TextManager()
{
    //loading fonts, seting size/style/position/string for all texts that will be show on the window.
    //Loading fonts


    if (!font.loadFromFile("assets/dogicapixel.otf"))
    {
        std::cout << "Failed to Load Font !!! \n";
    }
    else
    {
        std::cout << "   *Font Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }

    pair.setFont(font);
    Starting.setFont(font);
    variableText.setFont(font);
    cardsLeft.setFont(font);
    pair.setCharacterSize(30);
    Starting.setCharacterSize(20);
    cardsLeft.setCharacterSize(15);
    variableText.setCharacterSize(35);
    pair.setPosition(500, 50);
    Starting.setPosition(620, 550);
    cardsLeft.setPosition(1095, 550);
    //Setting this font to Score text
    Score.setFont(font);
    //Setting Score size
    Score.setCharacterSize(36);
    //Setting space between letters in score
    Score.setLetterSpacing(2.5);


}
//This fuction show a starting countdown
void TextManager::drawStartingTime(sf::RenderWindow* window, std::string str, const float timer)
{
    //settings string for Starting Text this way : "Start in " and we devide the starting timer on 120ms so it looks like seconds on screen.
    Starting.setString(str + std::to_string((int)(timer / 120)));
    window->draw(Starting);
}



void TextManager::drawCustom(sf::RenderWindow* window, std::string str, sf::Vector2f position, int size, sf::Color color)
{
    variableText.setFillColor(color);
    variableText.setString(str);
    variableText.setCharacterSize(size);
    variableText.setPosition(position);
    window->draw(variableText);

}



void TextManager::drawHANDPLAYED(sf::RenderWindow* window, std::string handName)
{
    pair.setString("Played " + handName);
    window->draw(pair);
    TextAnimation(&pair);
}

void TextManager::drawCardsLeftInDeck(sf::RenderWindow* window, int cards)
{

    cardsLeft.setString(std::to_string(cards) + "/" + "52");
    window->draw(cardsLeft);

}




//Animate a text(fade in/out) - POINTER
void TextManager::TextAnimation(sf::Text* text)
{
    if (Loop > 0)
    {
        if (i < 255)
        {
            i++;
        }
        else if (i == 255)
            Loop *= -1;
    }
    else
    {
        if (i > 0)
        {
            i--;
        }
        else if (i == 0)
            Loop *= -1;
    }
    text->setFillColor(sf::Color(i, i, i));
}