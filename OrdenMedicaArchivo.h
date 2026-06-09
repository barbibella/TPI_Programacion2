#pragma once
#include "OrdenMedica.h"

class OrdenMedicaArchivo{
private:
    char nombreArchivo[30];

public:
    OrdenMedicaArchivo();

    int contarRegistros();
    bool guardar(OrdenMedica registro);
    bool modificar(OrdenMedica registro, int pos);
    OrdenMedica leer(int pos);
    int buscarId(int idOrden);
};



