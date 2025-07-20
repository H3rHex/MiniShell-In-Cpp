cmake_minimum_required(VERSION 3.10)

project(MiniShell CXX)

set(CMAKE_CXX_STANDARD 11)

# --- CONFIGURATION PARA EL EJECUTABLE NORMAL ---
set(MAIN_SOURCES
        src/main.cpp
        src/includes/lib/strings/strings.cpp
        src/includes/shell/commands/commands.cpp
        src/includes/shell/hashTable/hashTable.cpp
)

add_executable(miniShell ${MAIN_SOURCES})

target_include_directories(miniShell PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src/includes
)