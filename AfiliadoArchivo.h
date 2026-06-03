#pragma once
#include "Afiliado.h"

class AfiliadoArchivo{
private:
    char nombreArchivo[30];

public:
    AfiliadoArchivo();

    bool guardar(Afiliado reg);
    bool modificar(Afiliado reg, int pos);
    Afiliado leer(int pos);
    int contarRegistros();
    int buscar(const char* dni);
    void listarTodo();
    Afiliado buscarPorDNI(const char* dni);
};

