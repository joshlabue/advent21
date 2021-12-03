#include <iostream>
#include <fstream>
#include <vector>

// finds which value is most common at a given positon for each entry in a vector
int mostCommon(std::vector<std::string> a, int position);

// filter a list to only include entries that have the right value at the right position
std::vector<std::string> isolate(std::vector<std::string> source, char valueToIsolate, int position);

int main() {
    std::ifstream input("input.txt");

    std::vector<std::string> numbers;

    std::string line;
    while(input >> line) {
        numbers.push_back(line);
    }

    int targetBit = 0;

    std::vector<std::string> oxygenCandidates = numbers;
    while(oxygenCandidates.size() != 1) {
        if(mostCommon(oxygenCandidates, targetBit) == 0) {
            oxygenCandidates = isolate(oxygenCandidates, '0', targetBit);
        }
        else {
            oxygenCandidates = isolate(oxygenCandidates, '1', targetBit);
        }
        targetBit++;
    }
    int oxygen = stoi(oxygenCandidates[0], nullptr, 2);

    targetBit = 0;
    std::vector<std::string> co2Candidates = numbers;
    while(co2Candidates.size() != 1) {
        if(mostCommon(co2Candidates, targetBit) != 0) {
            co2Candidates = isolate(co2Candidates, '0', targetBit);
        }
        else {
            co2Candidates = isolate(co2Candidates, '1', targetBit);
        }
        targetBit++;
    }
    int co2 = stoi(co2Candidates[0], nullptr, 2);
    
    std::cout << oxygen * co2 << std::endl;


    return 0;
}


int mostCommon(std::vector<std::string> a, int position) {
    int zeroes = 0;
    int ones = 0;

    for(int i = 0; i < a.size(); i++) {
        if(a[i].at(position) == '0') zeroes++;
        else ones++;
    }

    if(ones >= zeroes) {
        return 1;
    }
    else {
        return 0;
    }
}

std::vector<std::string> isolate(std::vector<std::string> source, char valueToIsolate, int position) {
    std::vector<std::string> result;

    for(int i = 0; i < source.size(); i++) {
        if(source[i].at(position) == valueToIsolate) {
            result.push_back(source[i]);
        }
    }

    return result;
}