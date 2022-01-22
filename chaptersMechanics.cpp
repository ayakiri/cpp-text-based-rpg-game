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

// smierc
void death(int death){
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
        std::cout << "The enemy was distracted with " << necessaryItem << "\n You take no damage and win this fight! \n\n";
    } else {
        std::cout << "The enemy is too powerfull!\n";
        std::cout << "You lose " << stoi(damage) << " health points!\n\n";
        newHero.health = newHero.health - stoi(damage);
        death({ newHero.checkHealth() });
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
    std::cout << obtainedItem << " was added to your inventory! \n\n";
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
        case 666:
            nextChapter();
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
