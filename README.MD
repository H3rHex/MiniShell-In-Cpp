# Proyecto: MiniShell (Shell en C++ desde cero)

## 🧠 Objetivo del Proyecto
Construir una shell mínima desde cero usando C++ de bajo nivel, sin bibliotecas estándar de alto nivel, para entender cómo interactúan los procesos, la memoria y el sistema operativo Linux a través de llamadas al sistema (`syscalls`).

Este proyecto está diseñado como un reto técnico y educativo, ideal para comprender el funcionamiento de un entorno UNIX/Linux y sus primitivas más básicas.

---

## 🎯 Funcionalidades mínimas obligatorias

1. **Prompt simple**  
   Mostrar un prompt (`> ` o similar) que acepte comandos desde la entrada estándar.

2. **Parseo de comandos**  
   Separar el comando y sus argumentos (simulando `argv`).

3. **Ejecución de comandos externos**  
   Usar `fork()`, `execve()` y `waitpid()` para lanzar programas externos.

4. **Manejo básico de errores**  
   Mostrar errores si un comando no existe o falla al ejecutarse.

5. **Comando interno `exit`**  
   Termina la shell de forma limpia.
---

## 📏 Reglas del proyecto (disciplinas obligatorias)

- ❌ **No se permite** el uso de:
  - `std::vector`, `std::string`, `std::map`, ni otras estructuras estándar dinámicas.
  - `system()`, `popen()`, `pclose()` u otras funciones de alto nivel.
  - Ninguna biblioteca externa: el proyecto debe basarse **solo en syscalls y funciones de C**.

- ✅ **Se permite y se recomienda**:
  - `malloc`, `calloc`, `free`, `realloc`
  - `write`, `read`, `dup2`, `fork`, `execve`, `pipe`, `open`, `close`, `waitpid`
  - Implementar tus propias funciones auxiliares (`strtok`, `strlen`, `strcmp`, etc.)

- 📚 **Regla personal**:  
  No usar la IA a menos que hayas investigado por tu cuenta durante al menos 20 minutos.

---

## 🧩 Posibles extensiones futuras (opcionales)

- Redirección de entrada/salida: `comando > archivo`, `comando < archivo`
- Piping: `ls | grep cpp`
- Variables de entorno (`PATH`, `HOME`, etc.)
- Historial de comandos
- Soporte para `cd`, `pwd`, y otros comandos internos
- Soporte para operadores como `&&`, `||`

---

## 🛠️ Herramientas recomendadas

- Compilador: `Cmake`
- Build: `Makefile`

---
---

## V1:
- Comando exit funcional
- Funciones de manejo de Strings usando logica a bajo nivel:
    - getStringLength
    - compareStrings
    - toLower

