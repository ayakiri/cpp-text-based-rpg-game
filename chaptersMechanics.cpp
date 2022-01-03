#include <iostream>

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

// do wyswietlania stron
int printPage(){
    return 0;
}

//do przechodzenia miedzy kartami opowiesci
int switchPage(){
    return 0;
}
