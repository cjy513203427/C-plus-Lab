#include "functions.hpp"
#include <iostream>

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "*";
    }
}

void printSpaces(int n) {
    for (int i = 0; i < n; i++) {
        std::cout << " ";
    }
}

void printFigure(int n, Direction dir) {
    if (dir == Left) {
        for (int i = n; i > 0; i--) {
            printStars(i);
            std::cout << std::endl;
        }
        for (int i = 2; i <= n; i++) {
            printStars(i);
            std::cout << std::endl;
        }
    } else if(dir == Right) {
        for (int i = n; i > 0; i--) {
            int numSpaces = n - i;
            printSpaces(numSpaces);
            printStars(i);
            printSpaces(2*numSpaces);
            std::cout << std::endl;
        }
        for (int i = 2; i <= n; i++) {
            int numSpaces = n - i;
            printSpaces(numSpaces);
            printStars(i);
            printSpaces(2*numSpaces);
            std::cout << std::endl;
        }
    }
}

void readDirection() {
    int dir;
    do {
        std::cout << "Enter pattern direction (0 for Left, 1 for Right): ";
        std::cin >> dir;
        if(dir == 0){
            printFigure(5, Left);
        }else if(dir == 1){
            printFigure(5, Right);
        }
        if (dir != 0 && dir != 1) {
            std::cout << "Invalid direction, please try again." << std::endl;
        }
    } while (true);
}

int main(int argc, char **argv) {
    readDirection();
    return 0;
}
