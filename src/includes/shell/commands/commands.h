// commands.h

#ifndef COMMANDS_H_ // <-- Guarda de inclusión corregido
#define COMMANDS_H_ // <-- Guarda de inclusión corregido

#include <new>
#include "../../lib/strings/strings.h"

// STRUCTURE DEFFINES
struct Command_node {
    char command_name[30];
};

struct Hash_entry_node {
    Command_node command;
    Hash_entry_node* next;
};

struct Commands_entry {
    Hash_entry_node *head;
};

struct Hash_commands_table {
    Commands_entry entries[10];
    int size;
};

// HASH TABLE FUNCTIONS
void initializeHashTable(Hash_commands_table* table);
bool insertCommand(Hash_commands_table* table, const Command_node* command); // <-- Firma de la función corregida (añadido 'const')
bool findCommand(const Hash_commands_table* table, const char* Command_Name);
void destroyHashTable(Hash_commands_table* table);

#endif // COMMANDS_H_ // <-- Guarda de inclusión corregido