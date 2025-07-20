// commands.h

#ifndef COMMANDS_H_ // <-- Guarda de inclusión corregido
#define COMMANDS_H_ // <-- Guarda de inclusión corregido

// MANAGE SYSCALLS
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


#include "../../lib/strings/strings.h"
#include "../hashTable/hashTable.h"

//COMMAND FUNCTIONS
void run_exit(const char* arg);
void run_print(const char* arg);
void run_clear(const char* arg);
void run_help(const char* arg);
void run_pwd(const char* arg);
void run_cd(const char* arg);
void run_ls(const char* arg);
void run_mkdir(const char* arg);
void run_rmdir(const char* arg);
void run_touch(const char* arg);
void run_rm(const char* arg);
void run_cat(const char* arg);

// IMPORTANT, RESPECT THE ORDER

inline const char* commands_list[] = {
    "exit",
    "print",
    "clear",
    "help",
    "pwd",
    "cd",
    "ls",
    "mkdir",
    "rmdir",
    "touch",
    "rm",
    "cat",
    nullptr};

inline Command_node commands_funtions_list[] {
    {"exit", &run_exit},
    {"print", &run_print},
    {"clear", &run_clear},
    {"help", &run_help},
    {"pwd", &run_pwd},
    {"cd", &run_cd},
    {"ls", &run_ls},
    {"mkdir", &run_mkdir},
    {"rmdir", &run_rmdir},
    {"touch", &run_touch},
    {"rm", &run_rm},
    {"cat", &run_cat},
    {"nullptr", nullptr}
};

inline const char** getCommandsList() {
    return commands_list;
};

// INIT COMMAND_TABLE
void initCommandsTable(Hash_commands_table* table);
int runCommand(const Hash_commands_table* table, const char* commandName, const char* arg);

#endif // COMMANDS_H_ // <-- Guarda de inclusión corregido