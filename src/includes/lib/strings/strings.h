#ifndef STRINGS_MANAGMENT_H
#define STRINGS_MANAGMENT_H


int getStringLength(const char *lChar);
bool compareStrings(const char *a, const char *b);
void cleanJumpCharacter(char *str);
char* toLower(const char *originalString, char *toLowerCaseString, int destBufferSize);
char* copyString(const char* originalStr, char* destinationStr, int destBufferSize);

#endif //STRINGS_MANAGMENT_H
