#include <iostream>
#include <curses.h>
#include "chaptersMechanics.cpp"
#include "chapterOne.cpp"

int main(void){
    system("clear");

    std::cout << "Hello Adventurer! \n";
    
    newHero.createHero();
    
    displayGameIntro();

    // chapter 1
    
    beginChapter(newHero.currentChapter);
    
    std::cout << "koniec \n";
    
    return 0;
}
