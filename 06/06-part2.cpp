#include <iostream>
#include <fstream>
#include <vector>

std::vector<long> iterate(std::vector<long> fish);

int main() {
    std::ifstream input("input.txt");

    std::vector<long> fish;

    for(int i = 0; i <= 8; i++) {
        fish.push_back(0);
    }

    std::string entry;
    while(getline(input, entry, ',')) {
        int value = stoi(entry);
        fish[value]++;
    }

    for(int day = 0; day < 256; day++) {
        fish = iterate(fish);
    }
    
    long sum = 0;
    for(int i = 0; i < fish.size(); i++) {
        sum += fish[i];
    }

    std::cout << sum << std::endl;   
}

std::vector<long> iterate(std::vector<long> fish) {
    std::vector<long> newFish;
    
    newFish.push_back(fish[1]); // now at index 0
    newFish.push_back(fish[2]); // 1
    newFish.push_back(fish[3]); // 2
    newFish.push_back(fish[4]); // 3
    newFish.push_back(fish[5]); // 4
    newFish.push_back(fish[6]); // 5
    newFish.push_back(fish[7] + fish[0]); // 6 
    newFish.push_back(fish[8]); // 7
    newFish.push_back(fish[0]); // 8

    return newFish;
}