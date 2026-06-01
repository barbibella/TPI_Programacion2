#pragma once
#include "Medico.h"
class MedicoArchivo{
private:
    char nombreArchivo[30];

public:
    MedicoArchivo();

    bool guardar(Medico reg);            // Escribir al final
    bool modificar(Medico reg, int pos); // Sobrescribir uno existente
    Medico leer(int pos);                // Leer un registro específico
    int contarRegistros();                 // Saber cuántos hay en total
    int buscar(int nroMedico);           // Buscar por ID y devolver la posición
    void listarTodo();
};
