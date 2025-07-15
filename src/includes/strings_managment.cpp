#include "strings_managment.h"

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

char* toLower(const char *a) {
    if (a == nullptr) {
        return nullptr;
    }

    const int len_a = getStringLength(a);
    char* buffer = new char[len_a + 1]; // add the null character \0
    buffer[len_a] = '\0';

    for (int i = 0; i < len_a; i++) {
        // CHECK IF IS CHAR IS IN ASCI UPPER CHARS
        if (a[i] >= 65 && a[i] <= 90) {
            buffer[i] = (a[i] + 32);
        } else {
            buffer[i] = a[i];
        }
    }
    return buffer;
}
