#include "hashTable.h"

// HASH TABLE FUNCTIONS //

// INITIALIZE HASH TABLE ON MEMORY

void initializeHashTable(Hash_commands_table* table) {
    // ASSING TABLE SIZE
    table->size = 15;
    // DECLARE ALL ENTRIES EMPTY
    for (int i = 0; i < table->size; i++) {
        table->entries[i].head = nullptr;
    }
}

// HASH FUNCTION -> GET A INDEX
int getTableIndex(const Hash_commands_table* table, const char* command) {
    int sum = 0;
    int tableSize = table->size;
    for (int i = 0; command[i] != '\0'; i++) {
        sum += command[i];
    }
    return sum % tableSize;
}

// INSERT DATA (COMMANDS)
bool insertCommand(Hash_commands_table* table, const Command_node* command){
    // GET INDEX OF command
    int index = getTableIndex(table, command->command_name);

    Hash_entry_node* newNode = new (std::nothrow)Hash_entry_node;
    if (newNode == nullptr) {
        return false; // ERROR IN MEMORY ASIGNATION
    }

    copyString(command->command_name, newNode->command.command_name, sizeof(newNode->command.command_name));
    newNode->command.command_function = command->command_function;

    newNode->next = nullptr; // Next pointer is null

    // INSERT CHAIN-LIST IN HAST TABLE INDEX
    newNode->next = table->entries[index].head;
    table->entries[index].head = newNode;

    return true;
}

bool findCommand(const Hash_commands_table* table, const char* command_Name) {
    int index = getTableIndex(table, command_Name);

    // GET FIRST POINTER
    Hash_entry_node* current_node = table->entries[index].head;

    while (current_node != nullptr) {
        if (compareStrings(current_node->command.command_name, command_Name)) {
            return true;
        }

        // MOVE TO NEXT NODE
        current_node = current_node->next;
    }

    return false;
}

void (*findCommandFunction(const Hash_commands_table* table, const char* command_name))(const char* args){
    int index = getTableIndex(table, command_name);

    // GET FIRST POINTER
    Hash_entry_node* current_node = table->entries[index].head;
    while (current_node != nullptr) {
        if (compareStrings(current_node->command.command_name, command_name)) {
            return  current_node->command.command_function;
        }
        current_node = current_node->next;
    }
    // IF FUNCTION ISN'T FIND
    return nullptr;
}
