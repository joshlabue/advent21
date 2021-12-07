#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <math.h>

int main() {
    std::ifstream input("input.txt");

    std::vector<int> crabs;

    std::string line;
    while(getline(input, line, ',')) {
        crabs.push_back(stoi(line));
    }

    std::cout << crabs.size() << " crabs\n";

    int lowestCost = INT_MAX;

    /*
    @Mitch-Siegel mentioned using a cache here to keep track of any solved distance costs since 
    recalculating them every time is inefficient. I think it's a bit disingenuous to include 
    it in my code considering it wasn't my idea and this code is ideally a decent representation
    of what my code is like, but I figured it would be worth mentioning for anyone who is looking
    at this code in the future.
    */

    for(int i = 0; i < crabs.size(); i++) {
        int fuelCost = 0;
        for(int crab = 0; crab < crabs.size(); crab++) {
            int individualCost = 0;
            int distance = abs(crabs[crab] - i);
            for(int j = 0; j <= distance; j++) {
                individualCost += j;
            }

            fuelCost += individualCost;
        }

        if(fuelCost < lowestCost) lowestCost = fuelCost;
    }

    std::cout << lowestCost << std::endl;

}