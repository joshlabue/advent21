#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("input.txt");

    int increases = 0;

    int depth = 0;
    int lastDepth = 0;
    input >> lastDepth;
    while(input >> depth) {
        if(depth > lastDepth) {
            increases++;
        }

        lastDepth = depth;
    }

    std::cout << increases << std::endl;
}