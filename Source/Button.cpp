#include "Button.h"
#include <Global.h>
#include <string.h>
#include <SoundsManager.h>

SoundsManager S;


Button::Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize, sf::Color color)
{
    //setting the button size/position
    this->color = color;
    button.setSize(buttonSize);
    button.setFillColor(sf::Color(0, 0, 0, 0));
    button.setPosition(buttonPos);
    inbut = 0;
    colorExtra = (sf::Color(0, 0, 0, 0));
    texture.loadFromFile("assets/cardsSheet.png");
    sprite.setTexture(texture);
    rect.width = 64; rect.height = 89;
    rect.left = 64 * 2; rect.top = 89 * 5;
    sprite.setPosition(buttonPos);
    sprite.setTextureRect(rect);
    buttonSpr.setPosition(buttonPos);

}


//const for buttons with texts
Button::Button(std::string Text, sf::Vector2f buttonPos, sf::Vector2f buttonSize, sf::Color color, sf::Color hoverColor)
{
    //setting the button size/position
    selected = 1;
    this->color = hoverColor;
    button.setSize(buttonSize);
    button.setFillColor(color);
    button.setPosition(buttonPos);
    inbut = 0;
    text.setString(Text);
    colorExtra = color;
    //text.setFont(font);
    font.loadFromFile("assets/Plaguard-ZVnjx.otf");
    text.setFont(font);
    text.setString(Text);
    text.setCharacterSize(25);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);
    text.setPosition(getPos().x + (thesize().x / 2) - 72, getPos().y + (thesize().y / 2) - 20);

}


//const for buttons with images

Button::Button(sf::Vector2f buttonPos, sf::Vector2f buttonSize,  sf::Color hoverColor,unsigned short temp)
{
    button.setSize(buttonSize);
    color = hoverColor;
    button.setPosition(buttonPos);
    inbut = 0;
    colorExtra = color;


}


void Button::setText(std::string str)
{
    text.setString(str);
}


void Button::drawDeck(sf::RenderWindow& window)
{
    changeDeckTexture();
    window.draw(sprite);

}
void Button::changeDeckTexture()
{
    if (changeTextureTimer > 0)
    {
        changeTextureTimer--;
    }
    else
    {
        changeTextureTimer = 120;
        redorwhite = redorwhite * -1;
        if (redorwhite > 0)
        {
            rect.left = 64 * 2;
        }
        else
        {
            rect.left = 64 * 3;
        }
        sprite.setTextureRect(rect);
    }

}



void Button::selectCard()
{
    button.setFillColor(color);
    selected = true;
}
void Button::unSelectCard()
{
    button.setFillColor(colorExtra);
    selected = false;
}



void Button::hoverOverButton()
{
    //text becomes gray
    button.setFillColor(color);
    buttonSpr.setColor(sf::Color::Yellow);
}

void Button::Unhover()
{
    button.setFillColor(sf::Color(0, 0, 0, 0));
    buttonSpr.setColor(originCol);

}

void Button::draw(sf::RenderWindow& window)
{
    window.draw(button);
    window.draw(text);
    window.draw(buttonSpr);
}



void Button::setImage(sf::Texture& buttonTexture)
{
    buttonSpr.setTexture(buttonTexture);
    buttonSpr.setScale(0.5f, 0.5f);
    originCol = buttonSpr.getColor();
}


//if cursor is inside the button -> we call the hover function(means text becomes gray)
void Button::update(sf::Vector2f CursCoords)
{
    if (checkCursInButton(CursCoords))
    {
        if (!inbut)
            S.playHoverSound();
        hoverOverButton();
        inbut = 1;
    }
    else
    {
        inbut = 0;
        if (!selected)
            Unhover();
    }

}

void Button::update2(sf::Vector2f curscoords)
{
    if (checkCursInButton(curscoords))
    {
        if (!inbut)
            S.playHoverSound();
        hoverOverButton();
        inbut = 1;
    }
    else
    {
        inbut = 0;
        unSelectCard();
    }

}

//checking if cursor is inside the button or not

bool Button::checkCursInButton(sf::Vector2f cursorPosition)
{
    return(cursorPosition.x >= button.getPosition().x && cursorPosition.x <= button.getPosition().x + button.getSize().x && cursorPosition.y >= button.getPosition().y && cursorPosition.y <= button.getPosition().y + button.getSize().y);
}
bool Button::checkClickedButton(sf::Vector2f cursorPosition)
{

    if (checkCursInButton(cursorPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        return true;
    }
    return false;
}

bool Button::checkClickedRightClick(sf::Vector2f cursorPosition)
{

    if (checkCursInButton(cursorPosition) && sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        return true;
    }
    return false;
}