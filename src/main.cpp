// MiniShell

//Libraries
#include "unistd.h"
#include "includes/strings_managment.h"

int main() {
    char a[] = "exit\n";
    char* buffer = new char[1024];

    while (true) {
        // WRITE PROMPT (OUT)
        write(STDOUT_FILENO, "> ", 3);
        // GET A COMMAND (INPUT)
        ssize_t bytes_leidos = read(STDIN_FILENO, buffer, sizeof(buffer) -1);
        // CHECK ERRORS
        if (bytes_leidos > 0) {
            buffer[bytes_leidos] = '\0'; // El ultimo byte sera nulo
        }
        // PASS TO LOWER CASE
        char* lowerCaseBuffer = toLower(buffer);
        // CHECK IF "exit" COMMAND
        bool wntExit = compareStrings(a, lowerCaseBuffer);
        if (wntExit == true) {
            // MEMORY LIBERATION
            delete[] lowerCaseBuffer;
            break;
        }
    }
    // MEMORY LIBERATION
    delete[] buffer;
    return 0; // Successful exit
}