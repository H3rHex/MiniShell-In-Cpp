#include "strings.h"

int getStringLength(const char *lChar) {
    int count = 0;
    while (lChar[count] != '\0') {
        count++;
    }
    return count;
}

bool compareStrings(const char *a, const char *b) {
    if (a == nullptr || b == nullptr) {
        return false;
    }

    const int len_a = getStringLength(a);
    const int len_b = getStringLength(b);

    if (len_a != len_b) {
        return false;
    }

   for (int i = 0; i <= len_a; i++) {
       if (a[i] != b[i]) {
           return false;
       }
   }
    return true;
}

void cleanJumpCharacter(char *str) {
    if (str == nullptr) {
        return;
    }

    int read_index = 0;
    int write_index = 0;

    while (str[read_index] != '\0') {
        if (str[read_index] != '\n') {
            str[write_index] = str[read_index];
            write_index ++;
        }
        read_index ++;
    }

    str[write_index] = '\0';
}

// MODIFICAR PARA MEJORAR LA GESTION DE MEMORIA -> Usar un buffer externo a la memoria.
char* toLower(const char *originalString, char *toLowerCaseString, int destBufferSize) {
    if (originalString == nullptr || toLowerCaseString == nullptr) {
        return nullptr;
    }

    int i = 0;
    while (originalString[i] != '\0' && i < destBufferSize - 1) {
        // CHECK IF IS UPPER CASE
        if (originalString[i] >= 65 && originalString[i] <= 90) {
            toLowerCaseString[i] = originalString[i] + 32;
        } else {
            toLowerCaseString[i] = originalString[i];
        }
        i++;
    }
    toLowerCaseString[i] = '\0';

    return toLowerCaseString;
}

char* copyString(const char* originalStr, char* destinationStr, int destBufferSize) {
    if (originalStr == nullptr) {
        return destinationStr;
    }

    // COPY ALL originalStr ARRAY TO destionationStr ARRAY
    int i = 0;
    while (originalStr[i] != '\0' && i < destBufferSize -1) {
        destinationStr[i] = originalStr[i];
        i++;
    }
    // ADD NULL TERMINATOR TO THE LAST BYTE
    destinationStr[i] = '\0';

    return destinationStr;
}

