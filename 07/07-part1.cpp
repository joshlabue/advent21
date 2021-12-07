#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

int main() {
    std::ifstream input("input.txt");

    std::vector<int> crabs;

    std::string line;
    while(getline(input, line, ',')) {
        crabs.push_back(stoi(line));
    }

    std::cout << crabs.size() << " crabs\n";

    int lowestCost = INT_MAX;

    for(int i = 0; i < crabs.size(); i++) {
        int fuelCost = 0;
        for(int crab = 0; crab < crabs.size(); crab++) {
            fuelCost += abs(crabs[crab] - i);
        }

        if(fuelCost < lowestCost) lowestCost = fuelCost;
    }

    std::cout << lowestCost << std::endl;

}