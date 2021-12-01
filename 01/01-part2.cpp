#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input("input.txt");

    int increases = 0;

    int windowASum = 0;
    int windowBSum = 0;
    
    std::vector<int> depths;

    int depth;
    while(input >> depth) {
        depths.push_back(depth);
    }

    for(int i = 3; i < depths.size(); i++) {
        windowASum = depths[i - 1] + depths[i - 2] + depths[i - 3];
        windowBSum = depths[i] + depths[i - 1] + depths[i - 2];

        if(windowBSum > windowASum) {
            increases++;
        }
    }

    std::cout << increases << std::endl;
}