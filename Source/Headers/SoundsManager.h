#pragma once

#include <SFML/Audio.hpp>

class SoundsManager
{
public:
    SoundsManager();

    void playMusic();

    void playHoverSound();




private:
    sf::Music music;
    sf::Sound hoverSound;
    sf::SoundBuffer buffer;

};