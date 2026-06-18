#pragma once
#include "ObraSocialArchivo.h"

class ObraSocialManager{
private:
    ObraSocial crearObraSocial();
    void mostrarObraSocial(ObraSocial reg);
    ObraSocialArchivo archivo;
public:
    void Menu();
    void Agregar();
    void ListarTodas();
    void ListarActivas();
    void ListarInactivas();
    void Modificar();
    void Eliminar();
    void AltaObraSocial();
    void BuscarPorID();
};
