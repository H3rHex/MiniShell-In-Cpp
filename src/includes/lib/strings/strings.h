#ifndef STRINGS_MANAGMENT_H
#define STRINGS_MANAGMENT_H


int getStringLength(const char *lChar);
bool compareStrings(const char *a, const char *b);
void cleanJumpCharacter(char *str);
char* toLower(const char *originalString, char *toLowerCaseString, int destBufferSize);
char* copyString(const char* originalStr, char* destinationStr, int destBufferSize);
void splitStr(const char* originalStr, char** separatedStringArray, const int maxTockens);

#endif //STRINGS_MANAGMENT_H
