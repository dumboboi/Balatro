#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "fstream"
#include <fstream>
#include <stdio.h>
#include <string.h>
class Game
{
public:
    Game(sf::RenderWindow& win);

    //Functions
public:
    std::ifstream inputfile;
    std::ofstream outfile;

    //Initialize things
    void Init();
    void loadSaves();

    //Game loop
    void Run();
private:
    //Game logic
    void Logic();
    //Clear window
    void Clear();
    //Update objects(hand/deck)
    void Updates();
    //Draw objects
    void Draw();
    //Reset the game
    void Reset();
    //Close the game
    void Close();

    void printSave(std::vector<std::string> handcards, int discardscount, int handscount, int score);

    void setLevelTexture();

    void deleteSave(int save);

    void saveStep1(std::string saveNameVar);

    void checkLoopMusic();

    void checkCanDelete();

    bool Running() { return isRunning; }
    sf::Vector2f CursCoords();


    //variables
private:
    bool isRunning;
    bool isPlaying;
    bool finishedLevel;
    bool lost;
    bool typingSaveName;
    bool paused;
    bool canPause;
    bool inSaves;
    bool canSave;
    bool inOptions;
    bool canOpenLink;
    bool finishedGame;
    bool canDelete;


    float deleteCD;
    float musicLoopCD;
    float pauseCD;
    float linkCD;

    std::string input_text;
    sf::Font font;
    sf::Text text;

    sf::Image icon;

    sf::RenderWindow& window;
    sf::Event event;
    sf::Clock clock;
    sf::Texture bgTexture;
    sf::Texture savesTexture;
    sf::Texture ingBgTexture;
    sf::Texture graybondeTexture;
    sf::Texture finishedLevelTexture;
    sf::Texture pausedTexture;
    sf::Texture handRankingTexture;
    sf::Texture finishedGAMEText;
    sf::Sprite finishedLevelSprite;
    sf::Sprite pausedSprite;
    sf::Sprite GraySprite;
    sf::Sprite savesSprite;
    sf::Sprite bgSprite;
    sf::Sprite ingBgSprite;
    sf::Sprite finishedGAMESpr;
    int Score = 0;
    std::vector<int>minimumScores;
    int currentLevel = 0;
    int savedLevel;
    int saveNum = 1;
    float timer;
    //file 
    std::fstream Saves;
    std::string savedDataOfLastRun;
    std::string savenameStr;


    struct save {
        std::string runName;
        std::vector<std::string> cardsInHand;
        std::vector<std::string> cardsInDeck;
        int handLeftInRun;
        int discardsLeftInRun;
        int Score;
        int levelSaved;
    };
    std::vector<save> lastruns;
    std::vector<std::string> linesSaved;
    void addRun(std::string runName, std::string hand, std::string handsLeftCount, std::string discardLeftCount, std::string deck);
    void getRun(struct save& RunSaved, std::string runLine);
};