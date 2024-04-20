#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Animation
{
public:
    Animation();

    //player animation
    void MainMenuAnim(sf::Sprite* sprite, sf::Texture* texture);


    std::string switchFrame();

    //TIMERS
private:
    int MMTimer;
    int fnum;

};