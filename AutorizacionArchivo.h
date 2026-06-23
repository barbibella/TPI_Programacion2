#pragma once
#include "Autorizacion.h"


class AutorizacionArchivo {

private:
    char nombreArchivo[30];

public:
    AutorizacionArchivo();

    bool guardar(Autorizacion reg);
    bool modificar(Autorizacion reg, int pos);

    Autorizacion leer(int pos);

    int contarRegistros();

    int buscar(int codAutorizacion);

    int proximoCodigo();

    // void listarTodo() no hace falta porque lo tenemos en el manager

};
