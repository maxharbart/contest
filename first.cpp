#include <iostream>
#include <string>

int main() {

    std::string word;
    std::cin >> word;
    std::string attempt;
    std::cin >> attempt;
    std::string used;
    
    for (int i = 0; i < word.length(); i++) {
        
        if (word[i] == attempt[i]) {
            std::cout << "correct" << std::endl;
            used += attempt[i];
        }
        else if (word[i] != attempt[i]) {
            if (word.find(attempt[i]) != std::string::npos) {
                if (used.find(attempt[i]) == std::string::npos) {
                    std::cout << "present" << std::endl;
                    used += attempt[i];
                }
                else {
                    std::cout << "absent1" << std::endl;
                }
                
            }
            else {
                std::cout<< "absent2" << std::endl;
            }
            
        }
    }
}