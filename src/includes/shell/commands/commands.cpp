// COMMANDS HASH TABLE
#include "commands.h"

// INIT COMMAND_TABLE
void initCommandsTable(Hash_commands_table* table) {
    initializeHashTable(table);
    for (int i = 0; commands_list[i] != nullptr; i++) {
        Command_node command;
        copyString(commands_list[i], command.command_name, sizeof(command.command_name));
        command.command_function = commands_funtions_list[i].command_function;
        insertCommand(table, &command);
    }
}

// CALL COMMANDS FUNCTIONS
int runCommand(const Hash_commands_table* table, const char* commandName, const char* arg) {
   void(*func)(const char*) = findCommandFunction(table, commandName);

    if (func == run_exit) {
        func(arg);
        return 0;
    }

    if (func != nullptr) {
        func(arg);
        return 1;
    } else {
        write(STDERR_FILENO, "\033[31mERROR EXECUTING THE COMMAND\033[0m\n", getStringLength("ERROR EXECUTING THE COMMAND\n"));
        return 1;
    }
}

void run_exit(const char* arg) {
    if (arg != nullptr) {
        const char* error_msg = "\033[31mERROR: You cannot use parameters for this command\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    _exit(0);
}

void run_print(const char* arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an argument for 'print'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    write(STDOUT_FILENO, arg, getStringLength(arg));
    write(STDOUT_FILENO, "\n", 1);
}

void run_clear(const char* arg) {
    if (arg != nullptr) {
        const char* error_msg = "\033[31mERROR: You cannot use parameters for this command\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    // ANSI: clear screen + move cursor to home
    write(STDOUT_FILENO, "\033[2J\033[H", getStringLength("\033[2J\033[H"));
}

void run_help(const char* arg) {
    if (arg != nullptr) {
        const char* error_msg = "\033[31mERROR: You cannot use parameters for this command\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }

    for (int i = 0; commands_list[i] != nullptr; i++) {
        write(STDOUT_FILENO, "  ", 2);
        write(STDOUT_FILENO, commands_list[i], getStringLength(commands_list[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}

void run_pwd(const char* arg) {
    char* tempBufferContainer = new char[1024];
    if (getcwd(tempBufferContainer, 1024) != nullptr) {
        write(STDOUT_FILENO,tempBufferContainer, getStringLength(tempBufferContainer));
        write(STDOUT_FILENO, "\n", 1);
    } else {
        write(STDERR_FILENO, "\033[31mERROR: Could not get current directory\033[0m\n", getStringLength("\033[31mERROR: Could not get current directory\033[0m\n"));
    }
    delete[] tempBufferContainer;
}

void run_cd(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an argument for 'cd'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    int response = chdir(arg);
    if (response != 0) {
        const char* error_msg = "\033[31mERROR: Changing directory\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
}

void run_ls(const char *arg) {
    DIR* dir = opendir(".");
    if (arg != nullptr) {
        dir = opendir(arg);
    }

    if (dir == nullptr) {
        const char* err = "\033[31mERROR: Could not open directory\033[0m\n";
        write(STDERR_FILENO, err, getStringLength(err));
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        const char* name = entry->d_name;
        if (name[0] == '.') {
            continue;
        }
        write(STDOUT_FILENO, name, getStringLength(name));
        write(STDOUT_FILENO, "\n", 1);
    }
    closedir(dir);
}

void run_mkdir(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an directory for 'mkdir'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    int response = mkdir(arg, 0755);

    if (response == -1) {
        const char* error_msg = "\033[31mERROR: Creating the directory\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
}

void run_rmdir(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an directory for 'rmdir'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    int response = rmdir(arg);

    if (response == -1) {
        const char* error_msg = "\033[31mERROR: Deleting the directory\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
}

void run_touch(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an name for 'touch'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    int response = creat(arg, 0755);
    if (response == -1) {
        const char* error_msg = "\033[31mERROR: Creating file\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
}

void run_rm(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an file for 'arg'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
    int response = unlink(arg);
    if (response == -1) {
        const char* error_msg = "\033[31mERROR: Deleting your file\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }
}


void run_cat(const char *arg) {
    if (arg == nullptr) {
        const char* error_msg = "\033[31mERROR: You must provide an file for 'cat'\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }

    int fd = open(arg, O_RDONLY);

    if (fd == -1 ) {
        const char* error_msg = "\033[31mERROR: Reading your file\033[0m\n";
        write(STDERR_FILENO, error_msg, getStringLength(error_msg));
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0){
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    write(STDOUT_FILENO, "\n", 1);
    close(fd);
    return;
}
