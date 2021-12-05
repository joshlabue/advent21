#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

struct Line {
    int x1, y1, x2, y2;
    int maxX, maxY;
};

struct Map {
    std::vector<std::vector<int>> data;
};

Line parseLine(std::string line);

void printMap(Map map);

int main() {
    std::ifstream input("input.txt");

    std::vector<Line> lines;
    Map map; // outer level is x (columns), inner level is y (rows)

    int sizeX = 0;
    int sizeY = 0;

    std::string line;
    while(getline(input, line)) {
        Line tmpLine = parseLine(line);
        lines.push_back(tmpLine);

        if(sizeX <= tmpLine.maxX) sizeX = tmpLine.maxX;
        if(sizeY <= tmpLine.maxY) sizeY = tmpLine.maxY;
    }

    for(int x = 0; x <= sizeX; x++) {
        map.data.push_back(std::vector<int>());
        for(int y = 0; y <= sizeY; y++) {
            map.data[x].push_back(0);
        }
    }

    for(int i = 0; i < lines.size(); i++) {
        Line tmpLine = lines[i];

        if(tmpLine.x1 == tmpLine.x2) { // if vertical line
            int startY, endY;
            if(tmpLine.y1 < tmpLine.y2) {
                startY = tmpLine.y1;
                endY = tmpLine.y2;
            }
            else {
                startY = tmpLine.y2;
                endY = tmpLine.y1;
            }

            for(int j = startY; j <= endY; j++) {
                map.data[tmpLine.x1][j]++;
            }
        }
        else if(tmpLine.y1 == tmpLine.y2) { // if vertical line
            int startX, endX;
            if(tmpLine.x1 < tmpLine.x2) {
                startX = tmpLine.x1;
                endX = tmpLine.x2;
            }
            else {
                startX = tmpLine.x2;
                endX = tmpLine.x1;
            }

            for(int j = startX; j <= endX; j++) {
                map.data[j][tmpLine.y1]++;
            }
        }
        else { // if diagonal
            int startX, startY, endX, endY;
            if(tmpLine.x1 < tmpLine.x2) { // left to right
                startX = tmpLine.x1;
                startY = tmpLine.y1;
            
                endX = tmpLine.x2;
                endY = tmpLine.y2;
            }
            else { // right to left
                startX = tmpLine.x2;
                startY = tmpLine.y2;
            
                endX = tmpLine.x1;
                endY = tmpLine.y1;
            }

            std::cout << startX << "," << startY << " -> " << endX << "," << endY << std::endl;
            if(startY < endY) { // y is increasing
                for(int j = 0; j <= endX - startX; j++) {
                    map.data[startX + j][startY + j]++;
                }
            }
            else { // y is decreasing
                for(int j = 0; j <= endX - startX; j++) {
                    map.data[startX + j][startY - j]++;
                    std::cout << startX + j << "," << startY - j <<std::endl;
                }
            }
        }
    }

    int sum = 0;
    for(int x = 0; x <= sizeX; x++) {
        for(int y = 0; y <= sizeY; y++) {
            if(map.data[x][y] > 1) sum++;
        }
    }

    printMap(map);

    std::cout << sum << std::endl;
    std::cout << "done" << std::endl;

}

Line parseLine(std::string line) {
    Line tmpLine;

    int numbersRead = 0;

    std::string currentNumber = "";
    for(int i = 0; i < line.length(); i++) {
        char currentChar = line.at(i);

        if(currentChar >= '0' && currentChar <= '9') {
            currentNumber = currentNumber + currentChar;
        }
        else if(currentChar == '-' || currentChar == '>') {
            continue;
        }

        bool endOfNumber = false;

        if(currentChar == ',') endOfNumber = true;
        if(currentChar == ' ' && line.at(i+1) == '-') endOfNumber = true; // if second number, right before arrow
        if(i == line.length()-1) endOfNumber = true;

        if(endOfNumber) {
            int value = stoi(currentNumber);
            currentNumber = "";

            // std::cout << "read number " << value << std::endl;
            switch(numbersRead) {
                case 0:
                    tmpLine.x1 = value;
                    break;
                case 1:
                    tmpLine.y1 = value;
                    break;
                case 2:
                  tmpLine.x2 = value;
                    break;
                case 3:
                    tmpLine.y2 = value;
                    break;
            }
            numbersRead++;

        }
    }

    if(tmpLine.x1 > tmpLine.x2) tmpLine.maxX = tmpLine.x1;
    else tmpLine.maxX = tmpLine.x2;

    if(tmpLine.y1 > tmpLine.y2) tmpLine.maxY = tmpLine.y1;
    else tmpLine.maxY = tmpLine.y2;

    return tmpLine;
}

void printMap(Map map) {    
    for(int y = 0; y < map.data[0].size(); y++) {
        for(int x = 0; x < map.data.size(); x++) {
            if(map.data[x][y] == 0) std::cout << ".";
            else std::cout << map.data[x][y];
        }
        std::cout << std::endl;
    }
}