#include <stdio.h>
#include <stdlib.h>
#include "strings.h"
#include "registers.h"

int main() {
/*    // Test concatenate function
    const char* str1 = "Hello";
    const char* str2 = "World";
    char* result = concatenate(str1, str2);
    printf("Concatenated string: %s\n", result);
    free(result);

    // Test split function
    const char* src = "Hello;;World;;!";
    const char* splitStr = ";;";
    char* dest[10]; // Assuming dest is large enough to hold the split strings
    int count = split(dest, src, splitStr);

    printf("Split strings:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", dest[i]);
        free(dest[i]);
    }*/
    
    // Option 1: Bitwise operators
    printf("Using bitwise operators:\n");
    setRegisters(&ADCCON3);

    // Option 2: Structs
    printf("\nUsing structs:\n");
    setRegistersStruct(&ADCCON3);
    
    
    #ifdef USE_STRUCTS
        printf("Using structs:\n");
        setRegistersStruct(&ADCCON3);
    #else
        printf("Using bitwise operators:\n");
        setRegisters(&ADCCON3);
    #endif
    
    return 0;
}
