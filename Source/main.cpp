
#include <SFML/Graphics.hpp>
#include <Global.h>
#include <Game.h>
#include "time.h"
#include "iostream"
#include <windows.h>
#include <shellapi.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{

    srand(time(NULL));


    //creating a window for the game
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Balatro");
    //Creating an object game of the class Game .
    Game game(window);
    //Initializing fpslimit/Texts/Score
    game.Init();
    //Running the game(Game loop)
    //this way its looks nicer than putting the game loop in here
    game.Run();

    //returns 0 after closing the game window
    return EXIT_SUCCESS;
}
