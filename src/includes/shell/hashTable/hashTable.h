#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include "../../lib/strings/strings.h"
#include <new>

// COMMAND STRUCTURE
struct Command_node {
    char command_name[30];
    void (*command_function)(const char* arg);
};

struct Hash_entry_node {
    Command_node command;
    Hash_entry_node* next;
};

struct Commands_entry {
    Hash_entry_node *head;
};

struct Hash_commands_table {
    Commands_entry entries[15];
    int size;
};

// HASH TABLE FUNCTIONS
void initializeHashTable(Hash_commands_table* table);
bool insertCommand(Hash_commands_table* table, const Command_node* command); // <-- Firma de la función corregida (añadido 'const')
bool findCommand(const Hash_commands_table* table, const char* Command_Name);
void (*findCommandFunction(const Hash_commands_table* table, const char* command_name))(const char* args);

#endif
