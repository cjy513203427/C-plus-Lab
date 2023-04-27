#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

enum Direction {
    Left,
    Right
};

void printStars(int n);
void printSpaces(int n);
void printFigure(int n, Direction dir);
void readDirection();

#endif /* FUNCTIONS_HPP_ */