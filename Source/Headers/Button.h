#pragma once
#include <string>
#include "SFML/Graphics.hpp"
//--------------------------------------------------//

//since sfml doesnt have a pre-defined button class, i made my own button class which is pretty helpfull.

//--------------------------------------------------//

class Button
{
public:
    // a constructor that takes the button title, button position, button size
    Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize, sf::Color color);//simple button const
    Button(std::string Text, sf::Vector2f buttonPos, sf::Vector2f buttonSize, sf::Color color, sf::Color hoverColor);//text button const
    Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize,sf::Color hoverColor,unsigned short temp);//image button const

    //Functions
public:
    //Drawing button
    void draw(sf::RenderWindow& window);
    //drawing deck
    void drawDeck(sf::RenderWindow& window);

    void changeDeckTexture();


    void setText(std::string str);

    //set button's background to white-gray color.
    void hoverOverButton();
    //set button's background transparent
    void Unhover();
    //Updates
    void update(sf::Vector2f CursCoords);
    //get button's position.
    sf::Vector2f getPos() { return button.getPosition(); }
    //getting button's size.
    sf::Vector2f thesize() { return button.getSize(); }
    //check if button is clicked
    bool checkClickedButton(sf::Vector2f cursorPosition);
    bool checkClickedRightClick(sf::Vector2f cursorPosition);
    //check if cursor is in button bounds
    bool checkCursInButton(sf::Vector2f cursorPosition);
    //color the card selected
    void selectCard();
    //remove highlight color
    void unSelectCard();
    //update for playbutton
    void update2(sf::Vector2f curscoords);

    void setImage(sf::Texture &buttonTexture);

    //Variables
public:
    sf::Text text;

private:
    sf::RectangleShape button;
    sf::Font font;
    bool inbut;
    bool selected = false;
    sf::Color color;
    sf::Color colorExtra;
    sf::Color originCol;
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Sprite buttonSpr ;
    float changeTextureTimer = 120;
    int redorwhite = 1;
    sf::IntRect rect;
};