#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream input("input.txt");

    std::vector<int> zeroes;
    std::vector<int> ones;

    std::string line;
    while(input >> line) {
        for(int i = 0; i < line.length(); i++) {
            if(line.at(i) == '0') {
                if(zeroes.size() <= i) zeroes.push_back(0);
                zeroes[i]++;
            }
            else {
                if(ones.size() <= i) ones.push_back(0);
                ones[i]++;
            }
        }
    }

    std::string gammaBinary = "";
    std::string epsilonBinary = "";
    for(int i = 0; i < zeroes.size(); i++) {
        gammaBinary += (zeroes[i] > ones[i] ? '0' : '1'); // write the more common bit
        epsilonBinary += (zeroes[i] < ones[i] ? '0' : '1'); // write the less common bit
        // std::cout << gammaBinary << std::endl;
    }
    
    int gamma = stoi(gammaBinary, nullptr, 2);
    int epsilon = stoi(epsilonBinary, nullptr, 2);
    std::cout << gamma * epsilon << std::endl;

    return 0;
}