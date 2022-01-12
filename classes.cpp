#include <string>
#include <vector>
#include <algorithm>

// Gracz
class playerClass {
    public: 
        std::string name; 
        int health; 
        std::vector <std::string> currentItems; 
        
        void createHero(){
            std::cout << "What is your name? \n";
            std::getline(std::cin, name);
            
            if(name == ""){
                name = "Hero";
            }
            
            health = 100;
    
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
