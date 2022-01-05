#include <iostream>
#include "chaptersMechanics.cpp"

int page1018(){
    system("clear");
    //opis fabuly
    
    std::cout << "GUARD 2: “ Ya know what, it looks good enough for me” GUARD 1: “But we will keep that in case you cause any trouble. Now go away before we change our mind”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Enter the castle \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            // delete Item 
            //beginChapterTwo();
            break;
    }
    
    return 0;
}

int page1017(){
    system("clear");
    //opis fabuly
    
    std::cout << "FAMILIAR VOICE: “You noisy kids, don’t you see this kid is in a rush” \n The familiar voice that rushed to your aid belongs to none other than an old tailor from the shop. \n TAILOR: “Is that bribe you are taking not enough to satisfy your greedy mouths?” \n Guards started to look a little bit paler. \n GUARD 1: “W-Well, w-we didn’t know you are an important g-guest..Come in-inside!”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Enter the castle \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //beginChapterTwo();
            break;
    }
    
    return 0;
}

int page1016(){
    system("clear");
    //opis fabuly
    
    std::cout << "FAMILIAR VOICE: “Aren’t you the one waiting for an audience with the king?” \n The familiar voice that rushed to your aid belongs to none other than a friendly woman from a bakery. \n WOMAN: “You should be ashamed- treating our precious guest like that! What would THE KING do, if he were to find out!” \n Guards started to look a little bit paler. \n GUARD 1: “W-Well, w-we didn’t know you are an important g-guest..Come in-inside!”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Enter the castle \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //beginChapterTwo();
            break;
    }
    
    return 0;
}

int page1015(){
    system("clear");
    //opis fabuly
    
    std::cout << "GUARD 1: “Listen I will beat the–”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Fight the guards \n";
    // if befriended woman || tailor -> possible options +1 and cout :
    std::cout << "2: Ask passerby for help \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //page1011(); - death
            break;
        case 2:
            // if befriended woman
            page1016();
            // if befriended tailor
            page1017();
            break;
    }
    
    return 0;
}

int page1014(){
    //opis fabuly
    
    std::cout << "GUARD 2: “And who do ya think ya are, kid?” \n GUARD 1: “I don’t want to deal with you, so leave before I lose my patience” " << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 2;
    
    std::cout << "1: Fight the guards \n";
    std::cout << "2: Insist \n";
    
    // przejscia po wyborze
    
    system("clear");
    switch(pickAnswer(possibleOptions)){
        case 1:
            //page1011(); - death
            break;
        case 2:
            page1015();
            break;
    }
    
    return 0;
}

int page1012(){
    system("clear");
    //opis fabuly
    
    std::cout << "GUARD 1: “ Yeah, you do? You’ve written it yourself?” \n GUARD 2: “Ya don’t look like ya could write”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 3;
    
    std::cout << "1: Fight the guards \n";
    std::cout << "2: HERO: “Let me pass or I’ll have you punished” \n";
    std::cout << "3: Show the permit anyway \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //page1011(); - death
            break;
        case 2:
            page1014();
            break;
        case 3:
            page1018();
            break;
    }
    
    return 0;
}

int page1013(){
    system("clear");
    //opis fabuly
    
    std::cout << "GUARD 1: “Right, everyone needs to. Unfortunately for you I need to do my job, so go away”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 3;
    
    std::cout << "1: Fight the guards \n";
    std::cout << "2: HERO: “But I have a written permit” \n";
    std::cout << "3: HERO: “Let me pass or I’ll have you punished” \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //page1011(); - death
            break;
        case 2:
            page1012();
            break;
        case 3:
            page1014();
            break;
    }
    
    return 0;
}

int page1010(){
    system("clear");
    //opis fabuly
    
    std::cout << "Finally decided to head into the castle, you spot two guards in front of the gate. \n HERO: I’m here to see the king” \n GUARD 1: “Castle’s closed today.” \n HERO: “But I’m here to see the king” \n GUARD 2: “Ya deaf, buddy? Ya not going anywhere.”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 4;
    
    std::cout << "1: Fight the guards \n";
    std::cout << "2: HERO: “I have a written permit” \n";
    std::cout << "3: HERO: “I need to see the king” \n";
    std::cout << "4: HERO: “Let me pass or I’ll have you punished” \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            //page1011(); - death
            break;
        case 2:
            page1012();
            break;
        case 3:
            page1013();
            break;
        case 4:
            page1014();
            break;
    }
    
    return 0;
}

int page1009(){
    system("clear");
    //opis fabuly
    
    std::cout << "TAILOR: “Then look faster! Don’t you have a job to do or places to be?! The Younger generation never think about the future!” \n The owner started murmuring under his breath for a while, and - not wanting to face any more of his grumpiness, you left the store." << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Leave \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            page1010();
            break;
    }
    
    return 0;
}

int page1008(){
    system("clear");
    //opis fabuly
    
    std::cout << "TAILOR: “...a-art?” \n Owner whispered and turned his face to the side. Was it just your imagination or the old man is blushing?  \n TAILOR: “WELL! As someone who acknowledged my masterpiece, you deserved to be rewarded. Take it and don’t hurt my eyes anymore with those clothes of yours!” \n Looking at an old man’s hand you see a shiny scarf. " << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 2;
    
    std::cout << "1: Accept the gift \n";
    std::cout << "2: Don't accept the gift \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            // addItem();
            // befriend - old tailor
            std::cout << "Item added to the inventory\n";
        case 2:
            page1010();
            break;
    }
    
    return 0;
}

int page1007(){
    system("clear");
    //opis fabuly
    
    std::cout << "TAILOR: “Y-You! I will call for help! Leave my shop right now!” \n The old man, visibly panicked, ran behind a counter and grabbed a broom. \n No longer being welcome, you turn around and leave the shop - with a smirk on your face. " << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Leave \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            page1010();
            break;
    }
    
    return 0;
}

int page1006(){
    system("clear");
    //opis fabuly
    
    std::cout << "A small and old looking tailor shop catches your eye instantly. In just a short while you found yourself staring at unusual garments. \n TAILOR: “Don’t you dare steal a single thing, tourist!” \n A grumpy voice from behind you warned you. It looks like it belongs to the shop owner - and the only other person in the room right now. " << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 3;
    
    std::cout << "1: HERO: “Well, nobody will see a thing, right? Or do you think YOU can stop me?” \n";
    std::cout << "3: HERO: “What? I’m not here to steal… I was just admiring this piece of art”  \n";
    std::cout << "4: HERO: “I’m just looking around” \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            // alg -5
            page1007();
            break;
        case 2:
            // alg + 5
            page1008();
            break;
        case 3:
            page1009();
            break;
    }
    
    return 0;
}

int page1005(){
    system("clear");
    //opis fabuly
    
    std::cout << "WOMAN: “Not much of a talker, are you? If you see anything you like just tell me” \n The woman stated, pointing to shelves full of pies. As nothing catches your eye, you turn around and leave." << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 1;
    
    std::cout << "1: Leave \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            page1010();
            break;
    }
    
    return 0;
}

int page1004(){
    system("clear");
    //opis fabuly
    
    std::cout << "WOMAN: “Business? Well it’s a busy world out there, isn’t it?” \n WOMAN: “Here, take this, don’t go around hungry” \n Looking at a small package you " << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 2;
    
    std::cout << "1: Accept the gift \n";
    std::cout << "2: Don't accept the gift \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            // addItem();
            std::cout << "Item added to the inventory\n";
        case 2:
            page1010();
            break;
    }
    
    return 0;
}

int page1003(){
    system("clear");
    //opis fabuly
    
    std::cout << "WOMAN:“A KING?”\nA woman looked at you, as if she had to find at least a small proof of your words. \nWOMAN:“As they say, you should not judge a book by it’s cover...ANYWAY! You can’t walk around hungry if you are summoned BY A KING HIMSELF!”\n A woman continued her monologue, getting more excited with every passing second. \nWOMAN: “Here, take this! I know, I’m awesome, but no need to thank me, just make sure to enjoy it, sweetie! Come on, don’t let THE KING wait”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 2;
    
    std::cout << "1: Accept the gift \n";
    std::cout << "2: Don't accept the gift \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            // addItem();
            std::cout << "Item added to the inventory\n";
            // befriend - woman from bakery
        case 2:
            page1010();
            break;
    }
    
    return 0;
}

int page1002(){
    system("clear");
    //opis fabuly
    
    std::cout << "Encouraged by the sweet smell of baked pies you walk straight to the local bakery. Apple pies, bagels, cakes, tarts, loafs - just everything your heart can desire. \n WOMAN: “See anything you like?”\nA deep female voice asked, just from behind your shoulders.\n WOMAN: “You don’t look like you are from here? Are you travelling, sweetheart?”" << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 3;
    
    std::cout << "1: “I got summoned by a king.” \n";
    std::cout << "3: “I have some business around.” \n";
    std::cout << "4: Say nothing \n";
    
    // przejscia po wyborze
    
    switch(pickAnswer(possibleOptions)){
        case 1:
            page1003();
            break;
        case 2:
            page1004();
            break;
        case 3:
            page1005();
            break;
    }
    
    return 0;
}

int page1001(){
    //opis fabuly
    
    std::cout << "Getting nearer to the palace turned out to be much more stressful than you have previously assumed. Or maybe it wasn’t a journey that was stressful, but rather what awaited you at the end. \n Couple of weeks ago you received a letter. A letter from none other than a king himself!  But what was it about? That’s what you were about to find out, because the letter didn’t explain it - just that it was urgent. \n As you get closer to your destination you decide to look around." << "\n\n";
    
    // mozliwe wybory
    int possibleOptions = 3;
    
    std::cout << "1: Examine a bakery \n";
    std::cout << "2: Go to the tailor \n";
    std::cout << "3: Don’t go anywhere \n";
    
    // przejscia po wyborze

    switch(pickAnswer(possibleOptions)){
        case 1:
            page1002();
            break;
        case 2:
            page1006();
            break;
        case 3:
            page1010();
            break;
    }
    
    return 0;
}

int beginChapterOne(){
    std::cout << "=================================================\n";
    std::cout << "==            Chapter One: Begining            ==\n";
    std::cout << "=================================================\n\n";
    
    page1001();
    
    return 0;
}
