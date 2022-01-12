// rodzaje wyborow
class actionClass {
    public:
                
};

class changePage: public actionClass {
    
};

class addItem: public actionClass {
    
};

class fightEnemy: public actionClass {
    
};

class visitHospital: public actionClass {
    
};


// Strony fabuly
class pageClass {
    public:
        int pageId;
        std::string pageDescription;
        //actionClass choicesDescription[4] = {new visitHospital()}; 
        std::map <String, actionClass[]> choicesDescription =new Map;
        choicesDescription.insert(
            {"Visit hospital",
            new actionClass[1]{ new visitHospital()}},
            {"Fight",
            new actionClass[2]{ new fightEnemy()}},
            {"Visit hospital",
            new actionClass[3]{ new visitHospital()}},
            
        );
        
};



{
    pageId = 1001;
    std::string pageDescription = "Getting nearer to the palace turned out to be much more stressful than you have previously assumed. Or maybe it wasn’t a journey that was stressful, but rather what awaited you at the end. \n Couple of weeks ago you received a letter. A letter from none other than a king himself!  But what was it about? That’s what you were about to find out, because the letter didn’t explain it - just that it was urgent. \n As you get closer to your destination you decide to look around. \n\n";
    
    choicesDescription[0] = "1: Examine a bakery";
    choicesDescription[1] = "2: Go to the tailor";
    choicesDescription[2] = "3: Don’t go anywhere";
    choicesDescription[3] = "";
    
    
} 
