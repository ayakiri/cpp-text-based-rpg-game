#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <chrono>
#include <fstream>
#include <limits>
#include "classes.cpp"

playerClass newHero;
currentPageClass newStory;

void pageContent(std::string fileName, int pageId);
void nextChapter();

// do wybierania odpowiedzi
int pickAnswer(int numberOfOptions){
    std::cout << "Choose a number between 1 and " << numberOfOptions << "... \n";
    int pickedAnswer;
    do {
        std::cin >> pickedAnswer;
        if (pickedAnswer > numberOfOptions || pickedAnswer < 1){
            std::cout << "Invalid number, please choose again \n";
        }
    } while (pickedAnswer > numberOfOptions || pickedAnswer < 1);
    return pickedAnswer;
}

// wstep i rozpoczecie gry
void displayGameIntro(){
    std::cout << "And here begins the story of a little human known as " << newHero.name << "\n \n";
    std::cout << "Will it be a successful tale full of wealth, love and kindness? \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "...Or will it turn grim along the way? \n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system("clear");
}


//obrazenia z innego powodu niz walka
void suffer(std::string damage, std::string reason){
    std::cout << "You have suffered from " << reason << ".\n";
    std::cout << "You lose " << stoi(damage) << " health points.\n\n";
    newHero.dealDamage(stoi(damage));
}

// walka 
void enemyEncounter(std::string damage, std::string necessaryItem){
    std::cout << "======================\n";
    std::cout << "==      Fight!      ==\n";
    std::cout << "======================\n\n";
    
    if(newHero.checkItems(necessaryItem)){
        std::cout << "The enemy was distracted with " << necessaryItem << "\n You take no damage and win this fight! \n\n";
    } else {
        std::cout << "The enemy is too powerfull!\n";
        std::cout << "You lose " << stoi(damage) << " health points!\n\n";
        newHero.dealDamage(stoi(damage));
    }
}

// odwiedz szpital
void visitHospital(std::string restoredHP){
    std::cout << "You met a friendly creature. Thanks to it, you can restore your health points. \n";
    std::cout << "This creature can heal up to " << restoredHP << " health points. \n\n";
    std::cout << "You currently have " << newHero.health << " health points!\n\n";
    
    int maxHealthToRestore;
    
    if(100 >= (newHero.health + stoi(restoredHP))){
        maxHealthToRestore = stoi(restoredHP);
    }else{
        maxHealthToRestore = (100 - newHero.health);
    }
    
    std::cout << "Would you like to heal " << maxHealthToRestore << " health points?\n";
    std::cout << "1: Heal\n";
    std::cout << "2: Don't heal\n";
    
    int answer = { pickAnswer(2) };
    
    if(answer == 1){
        newHero.heal(maxHealthToRestore);
    }
    
}

// dodaj przedmiot
void addItem(std::string obtainedItem){
    newHero.currentItems.push_back(obtainedItem);
    std::cout << obtainedItem << " was added to your inventory! \n\n";
}

// koniec gry
void gameOver(std::string deathReason){
    std::cout << deathReason << "\n";
    std::cout << "You can't continue your adventure \n";
    
    exit(0);
}

// wybor zakonczenia
void chooseEnding(){
    system("clear");
    std::string endingFile;
    if(newHero.checkItems("Wooden horse")){
        endingFile = "endGood.txt";
    } else if(newHero.health > 40){
        endingFile = "endNautral.txt";
    } else {
        endingFile = "endBad.txt";
    }
    
    std::string line;
    std::ifstream ending(endingFile);
    if(ending.is_open()){        
        for(int lineId = 1; getline(ending, line); lineId++){
            std::cout << line << "\n";
        }
    }
    
    exit(0);
}

// sprawdz dodatkowa akcje
void checkAction(std::string action){
    switch(stoi(action.substr(0, 3))){
        case 111:
            gameOver(action.substr(4, action.size()));
            break;
        case 222:
            addItem(action.substr(4, action.size()));
            break;
        case 333:
            visitHospital(action.substr(4, action.size()));
            break;
        case 444:
            enemyEncounter(action.substr(4, 3), action.substr(8, action.size()));
            break;
        case 555:
            chooseEnding();
            break;
        case 666:
            nextChapter();
            break;
        case 777:
            suffer(action.substr(4, 3), action.substr(8, action.size()));
            break;
    }
}


//przejscie na nowa strone
void nextPage(int answer){
    newStory.currentPage = newStory.currentAnswers[(answer - 1)];
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n\n";
    pageContent({ newStory.returnChapterFileName(newStory.currentChapter) }, newStory.currentPage);
}

// wyswietl strone 
void displayPage(){
    newStory.numberOfOptions = 0;
    
    std::cout << newStory.pageDescription << "\n\n";
    std::cout << "\n" << "What would you like to do?" << "\n";
    for(int i = 0; i < 4; i++){
        if(newStory.answersToPrint[i] != "0"){
            std::cout << newStory.answersToPrint[i] << "\n";
            newStory.increaseNoO();
        }
    }
    newStory.clearAnswersText();
    std::cout << "\n\n";
    
    nextPage({pickAnswer(newStory.numberOfOptions)});
}

//pobierz strone
void pageContent(std::string fileName, int currentPage){
    std::string line; 
    std::ifstream file(fileName);
    if(file.is_open()){        
        for(int lineId = 1; getline(file, line); lineId++){
            //zobacz akcje dodatkowe
            if(lineId == currentPage && line !="0"){
                checkAction(line);
            }
            // przypisz opis
            if(lineId == (currentPage + 1)){
                newStory.assignPageDescription(line);
            }
            //przypisz tekst odpowiedzi
            if(lineId >= (currentPage + 2) && lineId <= (currentPage + 5)){
                newStory.assignAnswersText(lineId, line);
            }
            //przypisz ktore strony sa po wybraniu odpowiedzi
            if(lineId >= (currentPage + 6) && lineId <= (currentPage + 9)){
                newStory.assignAnswersRoute(lineId, line);
            }
        }
        
        file.close();
    } else {
        std::cout << "Something went wrong\n\n";
    }
    
    displayPage();
}

// wstep do chapteru 
void beginChapter(int chapterNumber){
    system("clear");
    std::cout << "=====================================\n";
    std::cout << "==            Chapter "<< newStory.currentChapter << "            ==\n";
    std::cout << "=====================================\n\n";    
        
    pageContent({ newStory.returnChapterFileName(newStory.currentChapter) }, newStory.currentPage);
}

// nastepny rozdzial
void nextChapter(){
    newStory.currentChapter++;
    newStory.currentPage = 1;
    
    beginChapter(newStory.currentChapter);
}

// zacznij nowa opowiesc
void beginStory(){
    newHero.createHero();
    newStory.resetStory();
    //displayGameIntro();
    
    // zacznij gre    
    beginChapter(newStory.currentChapter);
}
