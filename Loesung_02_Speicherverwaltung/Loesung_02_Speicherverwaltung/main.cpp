#include <iostream>


int main(int argc, char **argv)
{
    /*int intVal = 42;
    int* pIntVal = &intVal;
    std::cout << "Wert von IntVal " << intVal << std::endl;
    std::cout << "Wert von &IntVal " << &intVal << std::endl;
    std::cout << "Wert von pIntVal " << pIntVal << std::endl;
    std::cout << "Wert von *pIntVal " << *pIntVal << std::endl;
    std::cout << "Wert von &pIntVal " << &pIntVal << std::endl;*/
    
    
/*    char c = 'T', d = 'S';
    char* p1 = &c;
    char* p2 = &d;
    char* p3;
    p3 = &d;
    std::cout << "*p3 = " << *p3 << std::endl;
    p3 = p1;
    std::cout << "*p3 = " << *p3
    << ", p3 = " << (void*)p3 << std::endl;
    *p1 = *p2;
    std::cout << "*p1 = " << *p1
    << ", p1 = " << (void*)p1 << std::endl;
    return 0;*/
    
    int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // array of 10 integers
    int* pArr = arr;
    std::cout << "Address of first element: " << pArr << std::endl;
    std::cout << "Address of second element: " << pArr + 1 << std::endl;
    std::cout << "Address of third element: " << pArr + 2 << std::endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
