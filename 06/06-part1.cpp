#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> iterate(std::vector<int> fish);

int main() {
    std::ifstream input("input.txt");

    std::vector<int> fish;

    std::string entry;
    while(getline(input, entry, ',')) {
        fish.push_back(stoi(entry));
    }

    for(int day = 0; day < 80; day++) {
        fish = iterate(fish);
    }

    std::cout << fish.size() << std::endl;
    
}

std::vector<int> iterate(std::vector<int> fish) {
    std::vector<int> newFish;
    
    for(int i = 0; i < fish.size(); i++) {
        int cooldown = fish[i];
        
        if(cooldown == 0) {
            cooldown = 6;
            newFish.push_back(8);
        }
        else {
            cooldown--;
        }

        newFish.push_back(cooldown);
    }

    return newFish;
}