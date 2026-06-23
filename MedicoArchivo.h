#pragma once
#include "Medico.h"
#include <cstring>
///MAI PC
//--- MAI ---
using namespace std;

class MedicoArchivo{
private:
    string _nombreArchivo;


public:
    MedicoArchivo(string nombreArchivo="medico.dat");
    int buscarMatricula(int matricula);
    int buscarDni(string dni);
    int getCantidadRegistros();
    int leerTodos(Medico vMedico[], int cantidad);
    bool crear(const Medico &reg);
    bool actualizar(int pos, const Medico &reg);
    bool existeMatricula (int matricula);
    Medico leer (int pos);
};
