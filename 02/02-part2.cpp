#include <iostream>
#include <fstream>

int main() {
    std::ifstream input("input.txt");

    std::string direction;

    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    
    while(input >> direction) {

        int units = 0;

        input >> units;

        if(direction == "forward") {
            horizontal += units;
            depth += aim * units;
        }
        else if(direction == "up") {
            aim -= units;
        }
        else if(direction == "down") {
            aim += units;
        }
    }

    std::cout << horizontal * depth << std::endl;
}