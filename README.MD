# MiniShell

## English

MiniShell is a simple command-line shell inspired by Bash, implemented from scratch in C/C++.  
The main goal of this project is to build a custom shell by implementing the core logic manually, **without relying on high-level library functions**. Instead, it uses low-level system calls and handcrafted logic to manage commands and filesystem operations.

### Features
- Supports common shell commands such as `exit`, `print`, `clear`, `help`, `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `touch`, and `cat`.
- Commands are stored and managed efficiently using a custom hash table for quick lookup.
- All error and info messages are displayed in color to improve user experience.
- Uses low-level syscalls (`mkdir`, `rmdir`, `creat`, `unlink`, etc.) to interact with the filesystem.
- Minimal external dependencies to better understand OS internals and shell mechanics.

### Development Rules
- No use of high-level standard library functions for command implementations.
- Manual management of memory and buffers.
- Direct usage of Linux syscalls for filesystem and IO operations.
- Focus on learning and re-implementing shell functionalities from the ground up.

---

## Español

MiniShell es una shell sencilla inspirada en Bash, implementada desde cero en C/C++.  
El objetivo principal de este proyecto es construir una shell personalizada implementando la lógica principal manualmente, **sin depender de funciones de biblioteca de alto nivel**. En su lugar, utiliza llamadas al sistema de bajo nivel y lógica propia para manejar comandos y operaciones en el sistema de archivos.

### Características
- Soporta comandos comunes como `exit`, `print`, `clear`, `help`, `pwd`, `cd`, `ls`, `mkdir`, `rmdir`, `touch` y `cat`.
- Los comandos se almacenan y gestionan eficientemente usando una tabla hash personalizada para una búsqueda rápida.
- Todos los mensajes de error e información se muestran en color para mejorar la experiencia de usuario.
- Utiliza llamadas al sistema de bajo nivel (`mkdir`, `rmdir`, `creat`, `unlink`, etc.) para interactuar con el sistema de archivos.
- Mínimas dependencias externas para entender mejor los internals del sistema operativo y la mecánica de la shell.

### Reglas de desarrollo
- No usar funciones de biblioteca estándar de alto nivel para implementar los comandos.
- Gestión manual de memoria y buffers.
- Uso directo de llamadas al sistema Linux para operaciones de sistema de archivos y entrada/salida.
- Enfoque en aprender y reimplementar funcionalidades de shell desde cero.

---

Feel free to contribute or modify this project for your own learning!

---

