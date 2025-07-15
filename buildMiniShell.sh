#!/bin/bash
cmake -S . -B out || { echo "Error en la configuracion de CMake."; exit 1; }

cd out || { echo "Error: No se pudo entrar al directorio 'out'."; exit 1; }

cmake --build . && {
    # Si la construccion fue exitosa, entonces limpia la pantalla y ejecuta la shell
    clear
    ./miniShell
} || {
    echo "Error: La compilacion o ejecucion de miniShell ha fallado."
    exit 1
}