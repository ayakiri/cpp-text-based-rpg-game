#include <iostream>
#include <string>
#include <vector>
#include <curses.h>

int getKeyboardInput() {
    char c;
    initscr();
    c = getch();
    endwin();
    std::cout << c << "\n";
    return 0;
}

int main(void) {
    
    system("clear");
    
    // Wybranie imienia i rozpoczecie rozgrywki
    
    std::cout << "Hello Adventurer! \n";
    
    std::string name = "Hero";
    std::cout << "What is your name?";
    std::cin >> name;
    
    system("clear");
    
    std::cout << "And here begins the story of a little human known as " << name << "\n \n";
    std::cout << "Will it be a successful tale full of wealth, love and kindness? \n ...Or will it turn grim along the way? \n";
        
    getKeyboardInput();
    
    return 0;
}
