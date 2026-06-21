#pragma once
#include <cstring>
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
    int buscar(std::string dni);
    void listarTodo();
    Afiliado buscarPorDNI(std::string dni);
    int leerTodos(Afiliado vAfiliado[], int cantidad);
};
