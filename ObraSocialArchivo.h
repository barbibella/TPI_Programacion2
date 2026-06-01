#pragma once
#include "ObraSocial.h"

class ObraSocialArchivo{
    private:
    char nombreArchivo[30];

public:
    ObraSocialArchivo();

    bool guardar(ObraSocial reg);
    bool modificar(ObraSocial reg, int pos);
    ObraSocial leer(int pos);
    int contarRegistros();
    int buscar (int idBuscado);
    void listarTodo();
};
