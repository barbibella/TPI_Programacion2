#pragma once
#include "OrigenDeLaOrden.h"

class OrigenDeLaOrdenArchivo{
private:
    char nombreArchivo[30];

public:
    OrigenDeLaOrdenArchivo();

    int contarRegistros();
    bool guardar(OrigenDeLaOrden registro);
    bool modificar(OrigenDeLaOrden registro, int pos);
    OrigenDeLaOrden leer(int pos);
    int buscarId(int idOrigen);
};
#pragma once
