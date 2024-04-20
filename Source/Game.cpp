#include <Game.h>
#include <Animation.h>
#include <Global.h>
#include <SoundsManager.h>
#include <Button.h>
#include <Deck.h>
#include <TextManager.h>
#include <fstream>
#include <iostream>
#include <locale>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <TextBox.h>
#include <windows.h>
#include <shellapi.h>



//Text Manager Object
TextManager T;


//Main Menu Buttons
Button profileB(sf::Vector2f(125, 620), sf::Vector2f(100, 40), sf::Color(128, 128, 200, 130)); // a buttong for checking ur saves
Button playButton(sf::Vector2f(295, 585), sf::Vector2f(188, 80), sf::Color(128, 128, 200, 130)); // a "play" button
Button optionsB(sf::Vector2f(500, 585), sf::Vector2f(130, 65), sf::Color(255, 149, 0, 130)); // a button for Options
Button exitButton(sf::Vector2f(652, 585), sf::Vector2f(130, 70), sf::Color(204, 0, 0, 130)); // an exit button
//--------------------------------------------------------------------------------------------------------------------------------//


//Options Buttons
Button handRankingB(sf::Vector2f(SCREEN_WIDTH - 280, 390), sf::Vector2f(96, 54), sf::Color(128, 128, 200, 130)); // a "play" button



//--------------------------------------------------------------------------------------------------------------------------------//


//Finished Level Buttons
Button nextLevelB("Next Level", sf::Vector2f(890, 598), sf::Vector2f(160, 60), sf::Color::Transparent, sf::Color(204, 240, 0, 200)); // next level
Button saveB("Save Level", sf::Vector2f(890, 460), sf::Vector2f(160, 60), sf::Color::Transparent, sf::Color(204, 240, 0, 200)); // Save level
//--------------------------------------------------------------------------------------------------------------------------------//


//Pause/Failed Buttons
Button replayB("replay Level", sf::Vector2f(890, 598), sf::Vector2f(160, 60), sf::Color::Transparent, sf::Color(0, 240, 240, 200)); // replay level
Button returnB("Return", sf::Vector2f(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2), sf::Vector2f(160, 60), sf::Color::Black, sf::Color(100, 100, 20, 100)); // return to game
Button saveRunB("Save Game", sf::Vector2f(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + 80), sf::Vector2f(160, 60), sf::Color::Black, sf::Color(100, 100, 20, 100)); // return to game
Button mainMenuB("Main Menu", sf::Vector2f(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 + (80 * 2)), sf::Vector2f(160, 60), sf::Color::Black, sf::Color(100, 100, 20, 100)); // return to game
//--------------------------------------------------------------------------------------------------------------------------------//





//saves buttons
Button save1("", sf::Vector2f(80, 200), sf::Vector2f(190, 60), sf::Color::Black, sf::Color(255, 191, 0)); // first level button
Button save2("", sf::Vector2f(80, 200 + 70), sf::Vector2f(190, 60), sf::Color::Black, sf::Color(255, 191, 0)); // first level button
Button save3("", sf::Vector2f(80, 200 + 140), sf::Vector2f(360, 60), sf::Color::Black, sf::Color(255, 191, 0)); // first level button
Button save4("", sf::Vector2f(80, 200 + 210), sf::Vector2f(360, 60), sf::Color::Black, sf::Color(255, 191, 0)); // first level button

//--------------------------------------------------------------------------------------------------------------------------------//



//TextBox
Textbox text1(20, sf::Color::White, true);
Button inputBox("", sf::Vector2f(SCREEN_WIDTH / 2 - 160, 200), sf::Vector2f(300, 60), sf::Color(0, 0, 0, 150), sf::Color(100, 100, 20, 100)); // return to game
//---------------------------------------------------------//


//A Deck Of Cards
Deck D;

//Animator
Animation anim;

//A Sound Manager Object
SoundsManager SM;



Game::Game(sf::RenderWindow& win) :
    //getting the window from the main.cpp
    window(win),
    isPlaying(0),
    inSaves(0),
    //setting isRunning to 1
    isRunning(1),
    canPause(1),
    canSave(1),
    inOptions(0),
    canOpenLink(1),
    linkCD(200),
    finishedGame(0),
    musicLoopCD(120000),
    deleteCD(500),
    canDelete(1)
{




    std::cout << "                                                  *Loading Images/Fonts*\n\n\n\n";

    loadSaves();

    if (!font.loadFromFile("assets/Plaguard-ZVnjx.otf"))
    {
        std::cout << "Failed to Load Font !!! \n";
    }
    else
    {
        std::cout << "   *Font Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }



    text.setFont(font);
    text.setString("");



    if (!savesTexture.loadFromFile("assets/saves_bg.png"))
    {
        std::cout << "Failed to Load Saves Background !!! \n";
    }
    else
    {
        std::cout << "   *Saves BackGround Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }

    savesSprite.setTexture(savesTexture);


    if (!pausedTexture.loadFromFile("assets/paused_bg.png"))
    {
        std::cout << "Failed to Load Pause-BackGround !!! \n";
    }
    else
    {
        std::cout << "   *Pause-BackGround Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }


    pausedSprite.setTexture(pausedTexture);



    if (!bgTexture.loadFromFile("assets/ezgif-frame-020.jpg"))
    {
        std::cout << "Failed to Load MainMenu Theme !!! \n";
    }
    else
    {
        std::cout << "   *MainMenu-Theme Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }



    if (!finishedLevelTexture.loadFromFile("assets/finished_level_menu.png"))
    {
        std::cout << "Failed to Load Finished Level Menu !!! \n";
    }
    else
    {
        std::cout << "   *Finished Level Menu Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }

    if (!handRankingTexture.loadFromFile("assets/hand_ranking.jpg"))
    {
        std::cout << "Failed to Load Hand Ranking!!! \n";
    }
    else
    {
        std::cout << "   *Hand Ranking Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }
    if (!icon.loadFromFile("assets/icon.png"))
    {
        std::cout << "Failed to Load icon!!! \n";
    }
    else
    {
        std::cout << "   *icon Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }



    handRankingB.setImage(handRankingTexture);

    finishedLevelSprite.setTexture(finishedLevelTexture);
    finishedLevelSprite.setPosition(160, 140);
    bgSprite.setTexture(bgTexture);


    if (!ingBgTexture.loadFromFile("assets/wp.jpg"))
    {
        std::cout << "Failed to Load InGame-BackGround !!! \n";
    }
    else
    {
        std::cout << "   *InGame-BackGround Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }
    if (!finishedGAMEText.loadFromFile("assets/finished_game.png"))
    {
        std::cout << "Failed to Load finishedGame-BackGround !!! \n";
    }
    else
    {
        std::cout << "   *finishedGame-BackGround Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }
    finishedGAMESpr.setTexture(finishedGAMEText);

    ingBgSprite.setTexture(ingBgTexture);
    GraySprite.setPosition(10, 0);
    GraySprite.setColor(sf::Color(250, 250, 250, 190));
    minimumScores.push_back(300);
    minimumScores.push_back(450);
    minimumScores.push_back(750);
    minimumScores.push_back(1200);


    //setting level and scord
    currentLevel = 0;
    Score = 0;
        
        ;
    D.setMinimumScore(minimumScores[currentLevel]);
    finishedLevel = false;


    text1.setPosition({ SCREEN_WIDTH / 2 - 160, 210 });
    text1.setLimit(true, 30);
    text1.setFont(font);
    //Setting Balatro icon of the window
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

}

void Game::loadSaves()
{
    lastruns.clear();
    linesSaved.clear();
    Saves.open("Saves.txt", std::ios::in);
    if (!Saves.is_open())
    {
        std::cout << "Failed to Open Saves File !!! \n";
    }
    else
    {
        std::cout << "   *Saves File Loaded successfully\n";
        std::cout << "############################################\n\n\n";
    }


    if (Saves.is_open()) {
        std::string tempstr;
        getline(Saves, tempstr);
        while (Saves)
        {
            struct save tempSave;
            if (tempstr != "" && tempstr != "\n" && tempstr != " " && tempstr != "LINES")
            {
                linesSaved.push_back(tempstr);
                getRun(tempSave, tempstr);
                lastruns.push_back(tempSave);

                std::getline(Saves, tempstr);
            }
            if (tempstr == "LINES")
                std::getline(Saves, tempstr);

        }
    }
    else
    {
        std::cout << "Couldnt open file";
        return;
    }
    Saves.close();
    if (lastruns.size() == 0)
        return;

    if (lastruns.size() >= 4)
    {
        save1.setText(lastruns[0].runName);
        save2.setText(lastruns[1].runName);
        save3.setText(lastruns[2].runName);
        save4.setText(lastruns[3].runName);
    }
    else if (lastruns.size() >= 3)
    {
        save1.setText(lastruns[0].runName);
        save2.setText(lastruns[1].runName);
        save3.setText(lastruns[2].runName);
        save4.setText("");
    }
    else if (lastruns.size() >= 2)
    {
        save1.setText(lastruns[0].runName);
        save2.setText(lastruns[1].runName);
        save3.setText("");
        save4.setText("");
    }
    else if (lastruns.size() >= 1)
    {
        save1.setText(lastruns[0].runName);
        save2.setText("");
        save3.setText("");
        save4.setText("");
    }
    else
    {
        save1.setText("");
        save2.setText("");
        save3.setText("");
        save4.setText("");
    }
    std::cout << "Line saved size : " << linesSaved.size();

}

void Game::deleteSave(int save)
{
    Saves.open("Saves.txt", std::ofstream::out | std::ofstream::trunc);
    //Saves << "SAVES\n";

    if (save == 1)
    {

        for (int i = 1; i < linesSaved.size(); i++)
        {
            Saves << linesSaved[i] + "\n";

        }

    }
    else if (save == 2)
    {
        Saves << linesSaved[0] + "\n";

        if (lastruns.size() == 3)
        {
            Saves << linesSaved[2] + "\n";

        }
        else if (lastruns.size() == 4)
        {
            Saves << linesSaved[2] + "\n";
            Saves << linesSaved[3] + "\n";
        }

    }
    else if (save == 3)
    {


        Saves << linesSaved[0] + "\n";
        Saves << linesSaved[1] + "\n";
        if (lastruns.size() == 4)
            Saves << linesSaved[3] + "\n";

    }
    else if (save == 4)
    {

        for (int i = 0; i < 3; i++)
        {
            Saves << linesSaved[i] + "\n";
        }
    }
    Saves.close();
    std::cout << "Line saved size : " << linesSaved.size();

}

//Initialiser
void Game::Init()
{
    //Capping the fps to 120
    window.setFramerateLimit(120);
    timer = 600;
    if (currentLevel == 0)
    {
        graybondeTexture.loadFromFile("assets/small_blind.png");
    }
    else if (currentLevel == 1)
    {
        graybondeTexture.loadFromFile("assets/big_blind.png");
    }
    else if (currentLevel == 2)
    {
        graybondeTexture.loadFromFile("assets/small_blind_extra.png");
    }
    else if (currentLevel == 3)
    {
        graybondeTexture.loadFromFile("assets/big_blind_extra.png");
    }
    GraySprite.setTexture(graybondeTexture);

    typingSaveName = 0;
    text.setPosition(100, 200);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
}


//game loop
void Game::Run()
{
    SM.playMusic();
    //while isRunning is 1 the game loop keeps going
    while (Running())
    {


        while (1 == window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                Close();
                break;
            }

            if (event.type == sf::Event::TextEntered)
            {

                if (typingSaveName)

                    text1.typedOn(event);
            }
        }
        
        checkLoopMusic();
        //game logic
        Logic();
    }
}

void Game::printSave(std::vector<std::string> handcards, int discardscount, int handscount, int score)
{
    std::cout << "----------------------------------------" << std::endl;
    for (auto& c : handcards)
    {
        std::cout << c << " ";
    }
    std::cout << "\n";
    std::cout << "discards counts : " << discardscount << std::endl;
    std::cout << "hands counts : " << handscount << std::endl;
    std::cout << "score  : " << score << std::endl;
    std::cout << "----------------------------------------";

}



void Game::addRun(std::string runName, std::string hand, std::string handsLeftCount, std::string discardLeftCount, std::string deck)
{

    Saves.open("Saves.txt", std::ios::app);
    std::string strToSave = runName + ";" + handsLeftCount + ";" + discardLeftCount + ";" + hand + ";" + deck + ";" + std::to_string(currentLevel) + ";" + std::to_string(Score) + ".\n";
    const char* strToChar = strToSave.c_str();
    std::cout << "char : " << strToChar << std::endl;
    Saves << strToSave;
    Saves.close();
}

void Game::getRun(struct save& RunSaved, std::string runLine)
{
    if (runLine == "")
        return;

    std::string tempStr = "";
    int p = 0;
    while (p < runLine.length() && runLine[p] != ';')
    {
        tempStr += runLine[p];
        p++;
    }
    RunSaved.runName = tempStr;
    tempStr = "";
    p++;
    RunSaved.handLeftInRun = runLine[p] - '0';
    p += 2;
    RunSaved.discardsLeftInRun = runLine[p] - '0';
    p += 2;
    //gettig cards in hand
    for (int c = 1; c <= 8; c++)
    {
        std::string temp = "";

        while (runLine[p] != ',' && runLine[p] != '.' && runLine[p] != ';')
        {
            temp += runLine[p];
            p++;
        }
        //std::cout << "card : " << temp << " ";
        RunSaved.cardsInHand.push_back(temp);
        p++;
    }
    //getting cards in deck
    tempStr = "";
    std::string temp = "";
    while (p < runLine.length() - 1 && runLine[p] != ';')
    {


        if (runLine[p] != ',' && runLine[p] != ';' && runLine[p] != '.')
        {
            temp += runLine[p];
            p++;
        }
        else
        {
            // std::cout << temp << " ";
            RunSaved.cardsInDeck.push_back(temp);
            temp = "";
            p++;
        }
    }
    RunSaved.cardsInDeck.push_back(temp);


    //get the leved saved
    p = runLine.find(".");

    while (runLine[p] != ';')
    {
        p--;
    }
    RunSaved.levelSaved = runLine[p - 1] - '0';

    //get the score
    p = runLine.find(".");

    while (runLine[p - 1] != ';')
    {
        p--;
    }
    tempStr = "";
    while (runLine[p] != '.')
    {
        tempStr += runLine[p];
        p++;
    }


    RunSaved.Score = stoi(tempStr);

}


void Game::saveStep1(std::string saveNameVar)
{
    typingSaveName = 0;
    save tempSave;
    tempSave.Score = Score;

    tempSave.runName = saveNameVar;
    //adding cards in hand
    std::vector<std::string> cardsInHand = D.getHand();
    std::string tempcardsih = "";
    for (auto& s : cardsInHand)
    {
        tempcardsih += s + ",";
    }
    tempcardsih.pop_back();
    //adding cards in deck
    std::vector<std::string> cardsInDeck = D.getDeck();
    std::string tempdeck = "";
    for (auto& s : cardsInDeck)
    {
        tempdeck += s + ",";
    }
    tempdeck.pop_back();
    int handLeftInRun = D.getHandsLeftCount();
    int discardsLeftInRun = D.getDiscardsLeftCount();
    addRun(savenameStr, tempcardsih, std::to_string(handLeftInRun), std::to_string(discardsLeftInRun), tempdeck);
    loadSaves();
}




void Game::Logic()
{
    //clear the screen in the game loop
    Clear();
    if (isPlaying)
    {
        Draw();
        Updates();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && canPause)
        {
            paused = 1;
            isPlaying = 0;
        }


    }
    else if (paused)
    {
        checkCanDelete();
        window.draw(pausedSprite);
        returnB.draw(window);
        returnB.update2(CursCoords());
        mainMenuB.draw(window);
        mainMenuB.update2(CursCoords());
        saveRunB.draw(window);
        saveRunB.update2(CursCoords());

        if (returnB.checkClickedButton(CursCoords()))
        {
            paused = 0;
            canPause = 0;
            isPlaying = 1;

        }
        if (mainMenuB.checkClickedButton(CursCoords()))
        {
            paused = 0;
            canPause = 0;
            isPlaying = 0;
            Reset();
                    SM.playMusic();

        }
        if (saveRunB.checkClickedButton(CursCoords()))
        {
            typingSaveName = 1;

        }
        if (typingSaveName)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
                if (typingSaveName)

                    text1.setSelected(true);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                if (typingSaveName)

                    text1.setSelected(false);
            }
            savenameStr = text1.getText();
            inputBox.draw(window);
            text1.drawTo(window);
            T.drawCustom(&window, "You can Save to 4 Runs", { SCREEN_WIDTH / 2 - 160, 280 }, 25, sf::Color::Black);
            if (lastruns.size() == 4)
            {
                T.drawCustom(&window, "(You already have 4 saves)", { SCREEN_WIDTH / 2 - 160, 320 }, 20, sf::Color::Black);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                if (lastruns.size() < 4)
                {
                    saveStep1(savenameStr);
                }
            }
        }
    }
    else if (finishedLevel)
    {

        window.draw(ingBgSprite);
        window.draw(GraySprite);
        D.drawHand(&window);
        window.draw(finishedLevelSprite);


        T.drawCustom(&window, std::to_string(minimumScores[currentLevel]), sf::Vector2f(615, 495), 35, sf::Color(229, 29, 29, 255));
        T.drawCustom(&window, std::to_string(Score), sf::Vector2f(720, 598), 35, sf::Color::Yellow);
        if (!isPlaying)
        {
            if (timer > 0)
            {
                T.drawStartingTime(&window, "You can Play Next Level in ", timer);
                timer--;
            }
            else
            {

                nextLevelB.draw(window);
                nextLevelB.update2(CursCoords());
                saveB.draw(window);
                saveB.update2(CursCoords());
                if (saveB.checkClickedButton(CursCoords()))
                {
                    if (lastruns.size() < 4)
                    {
                        if (canSave)
                        {
                            
                            saveStep1("Save" + std::to_string(saveNum));
                            saveNum++;
                            Score = 0;
                            canSave = 0;
                        }
                    }
                    else
                    {
                        T.drawCustom(&window, "You need to go ur saves and Delete a save by rightClicking on it", { SCREEN_WIDTH / 2,50 }, 30, sf::Color::Black);
                    }

                }
                if (nextLevelB.checkClickedButton(CursCoords()))
                {
                    if (currentLevel == 3)
                    {
                        finishedGame = 1;
                        isPlaying = 0;
                    }

                    else
                    {
                        currentLevel++;
                        isPlaying = 1;
                    }
                    setLevelTexture();
                    GraySprite.setTexture(graybondeTexture);
                    finishedLevel = 0;
                    Score = 0;
                    D.resetDeck();
                    D.setMinimumScore(minimumScores[currentLevel]);
                    timer = 600;
                    canSave = 1;

                }
            }

        }
    }
    else if (lost)
    {
        if (timer > 0)
        {
            T.drawStartingTime(&window, "You lost you can Re-Play in ", timer);
            timer--;
        }
        else
        {
            replayB.draw(window);
            replayB.update2(CursCoords());
            if (replayB.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                finishedLevel = 0;
                lost = 0;
                Score = 0;
                D.resetDeck();
                D.setMinimumScore(minimumScores[currentLevel]);
                timer = 600;

            }
        }

    }
    else if (inSaves)
    {
        window.draw(savesSprite);
        mainMenuB.draw(window);
        mainMenuB.update2(CursCoords());
        T.drawCustom(&window, "SAVES", sf::Vector2f(80, 120), 30, sf::Color(255, 191, 0));

        if (lastruns.size() >= 4)
        {
            save1.draw(window);
            save1.update2(CursCoords());
            save2.draw(window);
            save2.update2(CursCoords());
            save3.draw(window);
            save3.update2(CursCoords());
            save4.draw(window);
            save4.update2(CursCoords());
            if (save1.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(1);
                loadSaves();
                canDelete = 0;

            }
            else if (save2.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(2);
                loadSaves();
                canDelete = 0;


            }
            else if (save3.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(3);
                loadSaves();
                canDelete = 0;


            }
            else if (save4.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(4);
                loadSaves();
                canDelete = 0;

            }

            if (save1.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[0].levelSaved;
                D.setRun(lastruns[0].cardsInHand, lastruns[0].cardsInDeck, lastruns[0].discardsLeftInRun, lastruns[0].handLeftInRun);
                Score = lastruns[0].Score;
                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save2.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[1].levelSaved;
                D.setRun(lastruns[1].cardsInHand, lastruns[1].cardsInDeck, lastruns[1].discardsLeftInRun, lastruns[1].handLeftInRun);
                Score = lastruns[1].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save3.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[2].levelSaved;
                D.setRun(lastruns[2].cardsInHand, lastruns[2].cardsInDeck, lastruns[2].discardsLeftInRun, lastruns[2].handLeftInRun);
                Score = lastruns[2].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save4.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[3].levelSaved;
                D.setRun(lastruns[3].cardsInHand, lastruns[3].cardsInDeck, lastruns[3].discardsLeftInRun, lastruns[3].handLeftInRun);
                Score = lastruns[3].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            D.setMinimumScore(minimumScores[currentLevel]);
        }
        else if (lastruns.size() >= 3)
        {
            save1.draw(window);
            save1.update2(CursCoords());
            save2.draw(window);
            save2.update2(CursCoords());
            save3.draw(window);
            save3.update2(CursCoords());
            if (save1.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(1);
                loadSaves();
                canDelete = 0;

            }
            else if (save2.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(2);
                loadSaves();
                canDelete = 0;

            }
            else if (save3.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(3);
                loadSaves();
                canDelete = 0;


            }
            if (save1.checkClickedButton(CursCoords()))
            {

                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[0].levelSaved;
                D.setRun(lastruns[0].cardsInHand, lastruns[0].cardsInDeck, lastruns[0].discardsLeftInRun, lastruns[0].handLeftInRun);
                Score = lastruns[0].Score;
                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save2.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[1].levelSaved;
                D.setRun(lastruns[1].cardsInHand, lastruns[1].cardsInDeck, lastruns[1].discardsLeftInRun, lastruns[1].handLeftInRun);
                Score = lastruns[1].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save3.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[2].levelSaved;
                D.setRun(lastruns[2].cardsInHand, lastruns[2].cardsInDeck, lastruns[2].discardsLeftInRun, lastruns[2].handLeftInRun);
                Score = lastruns[2].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            D.setMinimumScore(minimumScores[currentLevel]);

        }
        else if (lastruns.size() >= 2)
        {
            save1.draw(window);
            save1.update2(CursCoords());
            save2.draw(window);
            save2.update2(CursCoords());
            if (save1.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(1);
                loadSaves();
                canDelete = 0;


            }
            else if (save2.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(2);
                loadSaves();
                canDelete = 0;

            }

            if (save1.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[0].levelSaved;
                D.setRun(lastruns[0].cardsInHand, lastruns[0].cardsInDeck, lastruns[0].discardsLeftInRun, lastruns[0].handLeftInRun);
                Score = lastruns[0].Score;
                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            else if (save2.checkClickedButton(CursCoords()))
            {
                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[1].levelSaved;
                D.setRun(lastruns[1].cardsInHand, lastruns[1].cardsInDeck, lastruns[1].discardsLeftInRun, lastruns[1].handLeftInRun);
                Score = lastruns[1].Score;

                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }

            D.setMinimumScore(minimumScores[currentLevel]);

        }
        else if (lastruns.size() >= 1)
        {
            save1.draw(window);
            save1.update2(CursCoords());
            if (save1.checkClickedRightClick(CursCoords()) && canDelete)
            {
                deleteSave(1);
                loadSaves();
                canDelete = 0;

            }
            if (save1.checkClickedButton(CursCoords()))
            {

                isPlaying = 1;
                inSaves = 0;
                currentLevel = lastruns[0].levelSaved;
                Score = lastruns[0].Score;
                D.setRun(lastruns[0].cardsInHand, lastruns[0].cardsInDeck, lastruns[0].discardsLeftInRun, lastruns[0].handLeftInRun);
                setLevelTexture();
                GraySprite.setTexture(graybondeTexture);
            }
            D.setMinimumScore(minimumScores[currentLevel]);

        }
        checkCanDelete();

        if (mainMenuB.checkClickedButton(CursCoords()))
        {
            inSaves = 0;
        }

    }

    else if (inOptions)//in optionsmenu
    {
        checkCanDelete();
        window.draw(savesSprite);
        mainMenuB.draw(window);
        mainMenuB.update2(CursCoords());
        handRankingB.draw(window);
        handRankingB.update(CursCoords());

        T.drawCustom(&window, "Options", sf::Vector2f(SCREEN_WIDTH/2 - 100, 120), 30, sf::Color(255, 191, 0));
        T.drawCustom(&window, "Tips", sf::Vector2f(SCREEN_WIDTH - 300, 200), 23, sf::Color(255, 191, 0));
        T.drawCustom(&window, "*Poker Hands are sets of between \n\n none and five cards that can \n\n be played in Balatro to obtain \n\n Chips and Mult for scoring.", sf::Vector2f(SCREEN_WIDTH - 400, 240), 15, sf::Color(255, 191, 0));
        T.drawCustom(&window, "*If you want to learn about the\n\n Hands Ranking Click on this \n\n button.", sf::Vector2f(SCREEN_WIDTH - 400, 340), 15, sf::Color(255, 191, 0));
        if (mainMenuB.checkClickedButton(CursCoords()))
        {
            inOptions = 0;
        }
        if (handRankingB.checkClickedButton(CursCoords()) && canOpenLink)
        {
            ShellExecute(0, 0, L"https://balatrogame.fandom.com/wiki/Poker_Hands", 0, 0, SW_SHOW);
            canOpenLink = 0;
        }
        if (!canOpenLink)
        {
            if (linkCD > 0)
                linkCD--;
            else
            {
                linkCD = 200;
                canOpenLink = 1;
            }
        }
    }
    else if (finishedGame) // finished the game
    {
        checkCanDelete();
        window.draw(finishedGAMESpr);
        mainMenuB.draw(window);
        mainMenuB.update2(CursCoords());

        T.drawCustom(&window, "Congratulations You Finished Balatro", { 270,SCREEN_HEIGHT / 2 }, 25, sf::Color::White);
        T.drawCustom(&window, "Congratulations You Finished Balatro", { 270,SCREEN_HEIGHT / 2 + 1 }, 25, sf::Color::Black);

        if (mainMenuB.checkClickedButton(CursCoords()))
        {
            finishedGame = 0;
            currentLevel = 0;

            setLevelTexture();
            GraySprite.setTexture(graybondeTexture);
            isPlaying = 0;
            finishedLevel = 0;
            Score = 0;
            D.resetDeck();
            D.setMinimumScore(minimumScores[currentLevel]);
            timer = 600;
            canSave = 1;
        }




    }
    else //in mainmenu
    {

        checkCanDelete();
        anim.MainMenuAnim(&bgSprite, &bgTexture);
        window.draw(bgSprite);
        profileB.draw(window);
        profileB.update2(CursCoords());
        playButton.draw(window);
        playButton.update(CursCoords());
        optionsB.draw(window);
        optionsB.update(CursCoords());
        exitButton.draw(window);
        exitButton.update(CursCoords());

        if (profileB.checkClickedButton(CursCoords()))
        {
            inSaves = 1;
        }
        if (playButton.checkClickedButton(CursCoords()))
        {
            isPlaying = 1;
            D.resetAllRun();
            playButton.update(CursCoords());
        }
        if (optionsB.checkClickedButton(CursCoords()))
        {
            inOptions = 1;
        }
        if (exitButton.checkClickedButton(CursCoords()))
        {
            isPlaying = 1;
            Close();
        }

    }
    window.display();
}

//clearing the window
void Game::Clear()
{
    window.clear(sf::Color::Black);
}

void Game::checkCanDelete()
{
    if (!canDelete)
    {
        if (deleteCD > 0)
        {
            deleteCD--;
        }
        else
        {
            deleteCD = 500;
            canDelete = 1;
        }
    }
}


void Game::setLevelTexture()
{
    if (currentLevel == 0)
    {

        graybondeTexture.loadFromFile("assets/small_blind.png");

    }
    else if (currentLevel == 1)
    {
        graybondeTexture.loadFromFile("assets/big_blind.png");
    }
    else if (currentLevel == 2)
    {
        graybondeTexture.loadFromFile("assets/small_blind_extra.png");
    }
    else if (currentLevel == 3)
    {
        graybondeTexture.loadFromFile("assets/big_blind_extra.png");
    }


}

//Updating ingame objects(updating deck / checking if player lost or won)
void Game::Updates()
{
    //pausing cooldown
    if (!canPause)
    {
        if (pauseCD > 0)
            pauseCD--;
        else
        {
            pauseCD = 80;
            canPause = 1;
        }
    }
    D.update(CursCoords(), &window, Score);
    if (D.checkIfFinished(Score))
    {
        isPlaying = false;
        finishedLevel = true;

    }

    if (D.checkIfFailed(Score))
    {
        lost = true;
        isPlaying = false;
        finishedLevel = false;
        Score = 0;
    }


}


//drawing objects(hand/deck/background)
void Game::Draw()
{
    window.draw(ingBgSprite);
    window.draw(GraySprite);
    D.drawHand(&window);

}



//getting cursor coords on the window;
sf::Vector2f Game::CursCoords()
{
    // get the current mouse position in the window
    sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
    // convert it to world coordinates
    sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
    return worldPos;
}

void Game::checkLoopMusic()
{
    if (clock.getElapsedTime().asSeconds()>123)
    {
        SM.playMusic();
        clock.restart();
    }

}

void Game::Reset()
{
    D.resetDeck();
    Score = 0;
    currentLevel = 0;
    setLevelTexture();

}

//closing game
void Game::Close()
{
    inputfile.close();
    outfile.close();

    isRunning = 0;
    window.close();
}