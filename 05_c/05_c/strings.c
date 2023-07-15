#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "strings.h"

char* concatenate(const char* a, const char* b) {
    size_t lenA = strlen(a);
    size_t lenB = strlen(b);

    char* result = malloc((lenA + lenB + 1) * sizeof(char));
    if (result == NULL) {
        return NULL; // Failed to allocate memory
    }

    strcpy(result, a);
    strcat(result, b);

    return result;
}

int split(char** dest, const char* src, const char* splitStr) {
    int count = 0;

    // Create a writable copy of the source string
    char* srcCopy = strdup(src);
    if (srcCopy == NULL) {
        return -1; // Failed to allocate memory
    }

    // Tokenize the string using strtok()
    char* token = strtok(srcCopy, splitStr);
    while (token != NULL) {
        dest[count] = strdup(token);
        if (dest[count] == NULL) {
            // Failed to allocate memory
            // Clean up the previously allocated strings
            for (int i = 0; i < count; i++) {
                free(dest[i]);
            }
            free(srcCopy);
            return -1;
        }
        count++;
        token = strtok(NULL, splitStr);
    }

    free(srcCopy);

    return count;
}
