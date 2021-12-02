#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("input.txt");

    std::string direction;

    int horizontal = 0;
    int depth = 0;
    
    while(input >> direction) {

        int units = 0;

        input >> units;

        if(direction == "forward") {
            horizontal += units;
        }
        else if(direction == "up") {
            depth -= units;
        }
        else if(direction == "down") {
            depth += units;
        }
    }

    std::cout << horizontal * depth << std::endl;
}