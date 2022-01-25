#include <string>
#include <vector>
#include <algorithm>


class currentPageClass{
    public:
        int currentChapter = 1;
        int currentPage = 1;
        std::string pageDescription; 
        std::string answersToPrint[4] = {"0", "0", "0", "0"};
        int numberOfOptions;
        int currentAnswers[4] = {1, 1, 1, 1};
        std::string fileName;
        
        //resetuj opowiesc 
        void resetStory(){
            currentChapter = 1;
            currentPage = 1; 
        }
                
        // wybierz ktory chapter ma byc pobrany
        std::string returnChapterFileName(int chapter){
            switch(chapter){
                case 1:
                    fileName = "chapOne.txt";
                    break;
                case 2:
                    fileName = "chapTwo.txt";
                    break;
                case 3:
                    fileName = "chapThree.txt";
                    break;
                case 4:
                    fileName = "chapFour.txt";
                    break;
                case 5:
                    fileName = "chapFive.txt";
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
        
        // zapisz text odpowiedzi
        void assignAnswersText(int lineId, std::string line){
            answersToPrint[(lineId % 10) - 3] = line;
        }
        
        // zapisz text odpowiedzi
        void clearAnswersText(){
            answersToPrint[0] = "0";
            answersToPrint[1] = "0";
            answersToPrint[2] = "0";
            answersToPrint[3] = "0";
        }
        
        // zapisz text strony
        void assignPageDescription(std::string line){
            pageDescription = line;
        }
        
        // zwieksz ilosc odpowiedzi
        void increaseNoO(){
            numberOfOptions++;
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
            
            currentItems.clear();
            isDead = false;
            health = 100;
                
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
            
        // death
            void heroDeath(int death){
                if(death){
                    std::cout << "You lost all your health points!\n";
                    std::cout << "Unfortunatly it is the end of your journey\n\n";
        
                    exit(0);
                }
            }
            
        // zabierz hp
            void dealDamage(int damage){
                health = health - damage;
                heroDeath({ checkHealth() });
                std::cout << "You currently have " << health << " health points!\n\n";
            }
};
