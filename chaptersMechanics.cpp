#include <iostream>
#include <thread>
#include <chrono>
#include "classes.cpp"

playerClass newHero;

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

// walka 
void fightEnemy(std::string necessaryItem){
    std::cout << "======================\n";
    std::cout << "==      Fight!      ==\n";
    std::cout << "======================\n\n";
    
    if(newHero.checkItems(necessaryItem)){
        std::cout << "zyjesz\n";
    }else {
        std::cout << "nie zyjesz\n";
    }
}

// wstep i rozpoczecie gry
void displayGameIntro(){
    std::cout << "And here begins the story of a little human known as " << newHero.name << "\n \n";
    std::cout << "Will it be a successful tale full of wealth, love and kindness? \n ";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "...Or will it turn grim along the way? \n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system("clear");
}

// wstep do chapteru 
void beginChapter(int chapterNumber){
    std::cout << "=====================================\n";
    std::cout << "==            Chapter "<< chapterNumber << "            ==\n";
    std::cout << "=====================================\n\n";
    
    //page1001();
    
}

// wyswietl aktualna strone
void displayPage(int pageNumber){
    
}
