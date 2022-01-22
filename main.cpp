#include <iostream>
#include "chaptersMechanics.cpp"

int main(void){
    system("clear");

    std::cout << "Hello Adventurer! \n";
    
    newHero.createHero();
    
    //displayGameIntro();

    // zacznij gre    
    beginChapter(newStory.currentChapter);
    
    std::cout << "koniec \n";
    
    return 0;
}
