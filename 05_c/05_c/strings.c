#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "strings.h"

char* concatenate(const char* a, const char* b) {
    size_t lenA = strlen(a);
    size_t lenB = strlen(b);
    size_t lenResult = lenA + lenB + 1; // +1 for the null terminator

    char* result = (char*)malloc(lenResult * sizeof(char));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    strcpy(result, a);
    strcat(result, b);

    return result;
}

int split(char** dest, const char* src, const char* splitStr) {
    size_t splitLen = strlen(splitStr);
    int count = 0;

    char* srcCopy = strdup(src);
    char* token = strtok(srcCopy, splitStr);

    while (token != NULL) {
        dest[count] = strdup(token);
        count++;

        token = strtok(NULL, splitStr);
    }

    free(srcCopy);

    return count;
}
