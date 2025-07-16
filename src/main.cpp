// MiniShell

//Libraries

#include "unistd.h"
#include "includes/lib/strings/strings.h"
#include "includes/shell/commands/commands.h"

void initHashTable(Hash_commands_table* table, const char* commands_list[]) {
    // INITIALIZE HASH TABLE ON MEMORY
    initializeHashTable(table);
    for (int i = 0; commands_list[i] != nullptr; i++) {
        Command_node command;
        copyString(commands_list[i], command.command_name, sizeof(command.command_name));
        insertCommand(table, &command);
    }

}

int main() {
    // COMANDS ARRAY
    const char* commands_list[] = {"exit", "clear", "help", nullptr};

    // DECLARE HASH TABLE STRUCTURE
    Hash_commands_table commands_table;
    initHashTable(&commands_table, commands_list);

    char* buffer = new char[1024];

    while (true) {
        // WRITE PROMPT (OUT)
        write(STDOUT_FILENO, "\033[34m> \033[0m", getStringLength("\033[34m> \033[0m"));
        // GET A COMMAND (INPUT)
        ssize_t bytes_leidos = read(STDIN_FILENO, buffer, 1024 -1);
        // CHECK ERRORS
        if (bytes_leidos > 0) {
            buffer[bytes_leidos] = '\0'; // El ultimo byte sera nulo
        }

        //Limpiamos los saltos
        cleanJumpCharacter(buffer);

        // PASS TO LOWER CASE
        char* lowerCaseBuffer = new char[1024];
        // CHECK IF "exit" COMMAND
        bool isCommandFoundInTable = findCommand(&commands_table, toLower(buffer, lowerCaseBuffer, 1024));

        if (!isCommandFoundInTable) {
            delete[] lowerCaseBuffer;
            write(STDOUT_FILENO, "\033[31mEl comando no existe\033[0m\n", getStringLength("\033[31mEl comando no existe\033[0m\n"));
            continue;
        }

        // MEMORY LIBERATION
        if (compareStrings(lowerCaseBuffer, "exit")) {
            delete[] lowerCaseBuffer;
            break;
        }

        if (compareStrings(lowerCaseBuffer, "clear")) {
            // CALL CLEAR FUNCTON
            write(STDOUT_FILENO, "\033[2J\033[H", getStringLength("\033[2J\033[H"));
            delete[] lowerCaseBuffer;
            continue;
        }

        if (compareStrings(lowerCaseBuffer, "help")) {
            for (int i = 0; commands_list[i] != nullptr; i++) {
                write(STDOUT_FILENO, commands_list[i], getStringLength(commands_list[i]));
                write(STDOUT_FILENO, "\n", 1);
            }
            delete[] lowerCaseBuffer;
            continue;
        }
    }
    // MEMORY LIBERATION
    delete[] buffer;
    return 0; // Successful exit
}