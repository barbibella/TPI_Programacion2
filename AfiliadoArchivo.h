#pragma once
#include "Afiliado.h"

class AfiliadoArchivo{
private:
    char nombreArchivo[30];

public:
    AfiliadoArchivo();

    bool guardar(Afiliado reg);            // Escribir al final
    bool modificar(Afiliado reg, int pos); // Sobrescribir uno existente
    Afiliado leer(int pos);                // Leer un registro específico
    int contarRegistros();                 // Saber cuántos hay en total
    int buscar(const char* dni);           // Buscar por ID y devolver la posición
    void listarTodo();
    Afiliado buscarPorDNI(const char* dni);
};

