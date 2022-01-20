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

// smierc w walce rip
void deathInBattle(int death){
    if(death){
        std::cout << "You lost all your health points!\n";
        std::cout << "Unfortunatly it is the end of your journey\n\n";
        
        exit(0);
    }
}

// walka 
void enemyEncounter(std::string damage, std::string necessaryItem){
    std::cout << "======================\n";
    std::cout << "==      Fight!      ==\n";
    std::cout << "======================\n\n";
    
    if(newHero.checkItems(necessaryItem)){
        std::cout << "The enemy was distracted with " << necessaryItem << "\n You take no damage and win this fight! \n";
    } else {
        std::cout << "The enemy is too powerfull!\n";
        std::cout << "You lose " << damage << " health points!\n\n";
        newHero.health = newHero.health - stoi(damage);
        deathInBattle({ newHero.checkHealth() });
        std::cout << "You currently have " << newHero.health << " health points!\n\n";
    }
}

// odwiedz szpital
void visitHospital(std::string restoredHP){
    std::cout << "You entered the hospital. Here you can restore your health points. \n";
    std::cout << "This hospital can heal up to " << restoredHP << " health points. \n\n";
    std::cout << "You currently have " << newHero.health << " health points!\n\n";
    
    int maxHealthToRestore;
    
    if(100 >= (newHero.health + stoi(restoredHP))){
        maxHealthToRestore = stoi(restoredHP);
    }else{
        maxHealthToRestore = (100 - newHero.health);
    }
    
    std::cout << "Would you like to heal " << maxHealthToRestore << " health points?\n";
    std::cout << "1: Use hospital\n";
    std::cout << "2: Don't use hospital\n";
    
    int answer = { pickAnswer(2) };
    
    if(answer == 1){
        newHero.heal(maxHealthToRestore);
    }
    
}

// dodaj przedmiot
void addItem(std::string obtainedItem){
    newHero.currentItems.push_back(obtainedItem);
    std::cout << newHero.name << ", " << obtainedItem << " was added to your inventory! \n\n";
}

// sprawdz dodatkowa akcje
void checkAction(std::string action){
    switch(stoi(action.substr(0, 3))){
        case 111:
            
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
            
            break;
    }
}


//przejscie na nowa strone
void nextPage(int answer){
    newStory.currentPage = newStory.currentAnswers[(answer - 1)];
    std::cout << "\n- - - - - - - - - - - - - - - - - - - - \n\n";
    pageContent({ newStory.returnChapterFileName(newStory.currentChapter) }, newStory.currentPage);
}

//pobierz i wyswietl strone
void pageContent(std::string fileName, int pageId){
    int numberOfOptions = -1; 
    std::string line; 
    std::ifstream file(fileName);
    if(file.is_open()){
        while(!file.eof()){
            for(int lineId = 1; getline(file, line) || lineId <= (pageId+9); lineId++){
                //zobacz akcje dodatkowe
                if(lineId == pageId && line != "0"){
                    checkAction(line);
                }
                //wydrukuj te linie ktore maja byc widoczne
                if(lineId > pageId && lineId <= (pageId + 5) && line != "0"){
                    if(lineId % 10 == 3){
                        std::cout << "\n" << "What would you like to do?" << "\n";
                    }
                    std::cout << line << "\n";
                    numberOfOptions++; 
                }
                //przypisz ktore strony sa po wybraniu odpowiedzi
                if(lineId >= (pageId + 6) && lineId <= (pageId + 9)){
                    newStory.assignAnswersRoute(lineId, line);
                }
            }
        }
    } else {
        std::cout << "Something went wrong\n\n";
    }
    
    nextPage({pickAnswer(numberOfOptions)});
}

// wstep do chapteru 
void beginChapter(int chapterNumber){
    std::cout << "=====================================\n";
    std::cout << "==            Chapter "<< newStory.currentChapter << "            ==\n";
    std::cout << "=====================================\n\n";    
        
    pageContent({ newStory.returnChapterFileName(newStory.currentChapter) }, newStory.currentPage);
}
