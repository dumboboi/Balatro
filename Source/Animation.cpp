#include "Animation.h"
#include <Global.h>

Animation::Animation() :
    MMTimer(404),
    fnum(1)
{}



void Animation::MainMenuAnim(sf::Sprite* sprite, sf::Texture* texture)
{
    if (fnum <= 101)
    {
        if (MMTimer % 4 == 0)
        {
            std::string frame = switchFrame();
            texture->loadFromFile("assets/" + frame + ".jpg");
            sprite->setTexture(*texture);
        }
        MMTimer--;


    }
    else
    {
        MMTimer = 404;
        fnum = 35;
    }


}

std::string Animation::switchFrame()
{
    std::string res;
    if (fnum >= 100)
    {
        res = std::to_string(fnum);
    }
    else
    {
        if (fnum >= 10)
            res = "0" + std::to_string(fnum);
        else
            res = "00" + std::to_string(fnum);

    }
    fnum++;
    return "ezgif-frame-" + res;

}