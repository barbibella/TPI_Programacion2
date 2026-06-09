#pragma once
#include "TipoDeOrden.h"

class TipoDeOrdenArchivo{
private:
    char nombreArchivo[30];

public:
    TipoDeOrdenArchivo();

    int contarRegistros();
    bool guardar(TipoDeOrden registro);
    bool modificar(TipoDeOrden registro, int pos);
    TipoDeOrden leer(int pos);
    int buscarId(int idTipoDeOrden);
};
