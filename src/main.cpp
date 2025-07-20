// MiniShell

//Libraries

#include "unistd.h"
#include "includes/lib/strings/strings.h"
#include "includes/shell/commands/commands.h"
#include "includes/shell/hashTable/hashTable.h"
int main() {
    // DECLARE HASH TABLE STRUCTURE
    Hash_commands_table commands_table;
    initCommandsTable(&commands_table);

    while (true) {
        char* inputBuffer = new char[1024];
        // DECLARE COMMANDS ARRAY
        char* command[2] = {nullptr, nullptr}; // [0] = COMMAND, [1] = ARGUMENT


        // WRITE PROMPT (OUT)
        write(STDOUT_FILENO, "\033[34m> \033[0m", getStringLength("\033[34m> \033[0m"));
        // GET A COMMAND (INPUT)
        ssize_t bytes_leidos = read(STDIN_FILENO, inputBuffer, 1024 -1);
        // CHECK ERRORS
        if (bytes_leidos > 0) {
            inputBuffer[bytes_leidos] = '\0';
        }

        if (inputBuffer[0] == '\n') {
            delete[] inputBuffer;
            continue;
        }

        //Limpiamos los saltos
        cleanJumpCharacter(inputBuffer);

        //LOWER CASE BUFFER CONTAINER
        char* lowerCaseBuffer = new char[1024];

        //SPLIT INPUT BUFFER
        splitStr(inputBuffer, command, 2);

        // CHECK IF "exit" COMMAND
        bool isCommandFoundInTable = findCommand(&commands_table, toLower(command[0], lowerCaseBuffer, 1024));

        // COMMANDS
        if (!isCommandFoundInTable) {
            write(STDOUT_FILENO, "\033[31mEl comando no existe\033[0m\n", getStringLength("\033[31mEl comando no existe\033[0m\n"));
            continue;
        } else {
            int commandResponse = runCommand(&commands_table, lowerCaseBuffer, command[1]);
            if (commandResponse != 0) {
                delete[] inputBuffer;
                delete[] lowerCaseBuffer;
                continue;
            } else {
                delete[] inputBuffer;
                delete[] lowerCaseBuffer;
                break;
            }
        }
    }
    // MEMORY LIBERATION
    return 0; // Successful exit
}