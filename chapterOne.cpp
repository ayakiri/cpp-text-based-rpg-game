#include <iostream>
#include "chaptersMechanics.cpp"

int page1001(){
    //opis fabuly
    
    std::cout << "Getting nearer to the palace turned out to be much more stressful than you have previously assumed. Or maybe it wasn’t a journey that was stressful, but rather what awaited you at the end. \n Couple of weeks ago you received a letter. A letter from none other than a king himself!  But what was it about? That’s what you were about to find out, because the letter didn’t explain it - just that it was urgent. \n As you get closer to your destination you decide to look around." << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 4;
    
    std::cout << "1: Examine a bakery \n";
    std::cout << "2: Talk to the locals \n";
    std::cout << "3: Go to the tailor \n";
    std::cout << "4: Don’t go anywhere \n";
    
    int pickedOption {pickAnswer(possibleOptions)};
    
    std::cout << pickedOption;
    
    return 0;
}

int beginChapterOne(){
    std::cout << "=================================================\n";
    std::cout << "==            Chapter One: Begining            ==\n";
    std::cout << "=================================================\n\n";
    
    page1001();
    
    return 0;
}
