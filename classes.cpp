#include <string>
#include <vector>
#include <algorithm>

//strony
class pageClass {
    public:
        int currentPage; 
        
};

class answersPageClass{
    public:
        int nextPage;
        int additionalAction;
        
        // sprawdz dodatkowa akcje
                
        // strona game over - id : 999
        
        // strona przedmiotu - id : 888
        
        // strona szpitala - id : 777
        
        // strona przeciwnika - id : 666
        
        // strona wygranej - id : 555
};

// Gracz
class playerClass {
    public: 
        std::string name; 
        int health; 
        std::vector <std::string> currentItems; 
        int currentPage; 
        
        // stworz bohatera
        void createHero(){
            std::cout << "What is your name? \n";
            std::getline(std::cin, name);
            
            if(name == ""){
                name = "Hero";
            }
            
            health = 100;
            currentPage = 1001;
    
            system("clear");
        }
        
        // dodaj przedmiot do eq
            void addItem(std::string obtainedItem){
                currentItems.push_back(obtainedItem);
            }
            
        // czy w eq jest dany przedmiot 
            int checkItems(std::string necesseryItem){
                bool isObtained = std::find(currentItems.begin(), currentItems.end(), necesseryItem) != currentItems.end();
                return isObtained;
            }
};

// Przeciwnicy
class enemyClass {
    public:
        std::string name;
        int damage; 
        std::string weapon;
};
