#include <string>
#include <vector>
#include <algorithm>


class currentPageClass{
    public:
        int currentChapter = 1;
        int currentPage = 1;
        int currentAnswers[4] = {1, 1, 1, 1};
        std::string fileName;
        
                
        // wybierz ktory chapter ma byc pobrany
        std::string returnChapterFileName(int chapter){
            switch(chapter){
                case 1:
                    fileName = "chapOne.txt";
                    break;
                case 2:
                    fileName = "chapOne.txt";
                    break;
                case 3:
                    fileName = "chapOne.txt";
                    break;
                case 4:
                    fileName = "chapOne.txt";
                    break;
                case 5:
                    fileName = "chapOne.txt";
                    break;
            }
            return fileName; 
        }
        
        //wyznacz sciezki odpowiedzi //brzydki kawalek kodu, i know, poprawie jak nie zapomne
        void assignAnswersRoute(int lineId, std::string line){
            if(lineId % 10 == 0){
                currentAnswers[3] = stoi(line);
            } else {
                currentAnswers[(lineId % 10) - 7] = stoi(line);
            }
        }
};

// Gracz
class playerClass {
    public: 
        std::string name; 
        int health; 
        bool isDead;
        std::vector <std::string> currentItems; 
        
        // stworz bohatera
        void createHero(){
            std::cout << "What is your name? \n";
            std::getline(std::cin, name);
            
            if(name == ""){
                name = "Hero";
            }
            
            isDead = false;
            health = 60;
                
            system("clear");
        }
                    
        // czy w eq jest dany przedmiot 
            int checkItems(std::string necesseryItem){
                bool isObtained = std::find(currentItems.begin(), currentItems.end(), necesseryItem) != currentItems.end();
                return isObtained;
            }
            
        // czy bohater jeszcze zyje
            int checkHealth(){
                if(health < 1){
                    isDead = true;
                }
                return isDead;
            }
            
        // ulecz bohatera
            void heal(int hp){
                health = health + hp;
                std::cout << "\nYou have healed your wounds. \n";
                std::cout << "You currently have " << health << " health points!\n\n";
            }
};
