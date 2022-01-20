#include <iostream>
#include <string>
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
    std::cout << "Will it be a successful tale full of wealth, love and kindness? \n ";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout << "...Or will it turn grim along the way? \n\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    system("clear");
}

//przejscie na nowa strone
void nextPage(int answer){
    newStory.currentPage = newStory.currentAnswers[(answer - 1)];
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
                //wydrukuj te linie ktore maja byc widoczne
                if(lineId >= pageId && lineId <= (pageId + 5) && line != "0"){
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

// walka 
void fightEnemy(std::string necessaryItem){
    std::cout << "======================\n";
    std::cout << "==      Fight!      ==\n";
    std::cout << "======================\n\n";
    
    if(newHero.checkItems(necessaryItem)){
        std::cout << "The enemy was struck with " << necessaryItem << "\n You take no damage and win this fight! \n";
    } else {
        std::cout << "nie zyjesz\n";
    }
}
