/*#include <iostream>

enum Direction {
    Left,c
    Right
};

void printStars(int n, Direction dir){
    if (dir == Left) {
        for(int i = 0; i < n; i++){
            std::cout << "*";
        } 
    } else {
        for (int i = 0; i < n; i++) {
            std::cout << " ";
        }
        for (int i = 0; i < n; i++) {
            std::cout << "*";
        }
    }
    std::cout<< std::endl;
}

void printFigure(int n, Direction dir){
    if(dir == Left){
            for(int i = n; i > 0; i--){
            printStars(i, dir);
        }
    
        for(int i = 2; i< n; i++){
            printStars(i, dir);
        }
    }else{
        for (int i = n; i > 0; i--) {
            printStars(i, dir);
        }
        for (int i = 2; i <= n; i++) {
            printStars(i, dir);
        }
    }
    
    
    
}

int main(int argc, char **argv)
{
    printFigure(5, Right);
    return 0;
}*/
