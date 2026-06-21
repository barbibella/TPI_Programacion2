#pragma once
#include "Especialidad.h"
#include <cstring>
//--- MAI ---
using namespace std;

class EspecialidadArchivo{
private:
    string _nombreArchivo;


public:
    EspecialidadArchivo(string nombreArchivo="especialidad.dat");
    int buscarIdEspecialidad(int especialidad);
    int getCantidadRegistros();
    int leerTodos(Especialidad vEspecialidad[], int cantidad);
    bool crear(const Especialidad &reg);
    bool actualizar(int pos, const Especialidad &reg);
    bool existeEspecialidad (int especialidad);
    Especialidad leer (int pos);
    bool existeIdEspecialidad(int id);
};
