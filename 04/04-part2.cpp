#include <iostream>
#include <fstream>
#include <sstream>
#include <vector> 

struct BingoSpace {
    int value;
    bool marked;
};

struct Board {
    std::vector<BingoSpace> spaces;
    bool hasWon;
};

// mark a given number on a board
Board callNumber(Board board, int number);

// determine if a board has won
bool hasWon(Board board);

int main() {
    std::ifstream input("input.txt");

    std::string line;

    input >> line;

    std::istringstream drawsLine(line);
    std::vector<int> draws;
    std::string draw;
    while(std::getline(drawsLine, draw, ',')) {
        draws.push_back(stoi(draw));
    }
    
    
    std::vector<Board> boards;

    while(!input.eof()) {
        Board tmpBoard;

        for(int i = 0; i < 25; i++) {
            input >> line;
            int value = stoi(line);

            BingoSpace tmpSpace;
            tmpSpace.marked = false;
            tmpSpace.value = value;

            tmpBoard.spaces.push_back(tmpSpace);
        }
        boards.push_back(tmpBoard);
    }

    
    std::vector<Board> winningBoards;
    std::vector<int> winningDraw;

    int drawIndex = -1;

    while(drawIndex != draws.size()) {
        drawIndex++;
        int calledNumber = draws[drawIndex];
        for(int i = 0; i < boards.size(); i++) {

            if(boards[i].hasWon == true) continue;

            boards[i] = callNumber(boards[i], calledNumber);

            if(hasWon(boards[i])) {
                boards[i].hasWon = true;
                winningBoards.push_back(boards[i]);
                winningDraw.push_back(calledNumber);
            }
        }
    }

    Board lastWinner = winningBoards.back();

    int unmarkedSum = 0;

    for(int i = 0; i < lastWinner.spaces.size(); i++) {
        if(lastWinner.spaces[i].marked == false) unmarkedSum += lastWinner.spaces[i].value;
    }

    int finalScore = unmarkedSum * winningDraw[winningBoards.size()-1];

    std::cout << finalScore << std::endl;
}

Board callNumber(Board board, int number) {
    for(int i = 0; i < board.spaces.size(); i++) {
        if(board.spaces[i].value == number) {
            board.spaces[i].marked = true;
        }
    }

    return board;
}
    
bool hasWon(Board board) {
    bool winFound = false;
    for(int row = 0; row < 5; row++) {
        bool rowWon = true;
        bool colWon = true;
        for(int col = 0; col < 5; col++) {
            int positionHorizWin = (row * 5) + col;
            int positionVertWin = (col * 5) + row;
            if(board.spaces[positionHorizWin].marked == false) {
                rowWon = false;
            }

            if(board.spaces[positionVertWin].marked == false) {
                colWon = false;
            }

            if(rowWon == false && colWon == false) {
                break;
            }
            
        }

        if(rowWon) winFound = true;
    }

    return winFound;
}
