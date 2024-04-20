#include "SoundsManager.h"
#include "iostream"

SoundsManager::SoundsManager()
{

    if (!music.openFromFile("assets/musicName.ogg"))
    {
        std::cout << "Failed to Load Music !!! \n";
    }
    else
    {
        std::cout << "   *Music Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }
    music.setVolume(30);


    if (!buffer.loadFromFile("assets/MenuSelection.wav"))
    {
        std::cout << "Failed to Load Audio !!! \n";
    }
    else
    {
        std::cout << "   *Audio Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }

    hoverSound = sf::Sound(buffer);
    hoverSound.setVolume(90);
}



void SoundsManager::playMusic()
{
    music.play();

}

void SoundsManager::playHoverSound()
{
    hoverSound.play();

}