#pragma once
#include "ObraSocialArchivo.h"

class ObraSocialManager{
private:
    ObraSocialArchivo archivo;
public:
    void Menu();
    void Mostar();
    void Agregar();
    void ListarTodas();
    void BuscarPorID();
};
