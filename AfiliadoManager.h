#pragma once
#include "AfiliadoArchivo.h"
#include "Afiliado.h"

class AfiliadoManager {
private:
    Afiliado crearAfiliado();
    void mostrarAfiliado(Afiliado reg);

    AfiliadoArchivo _repoAfiliado;

public:
    AfiliadoManager();

    void Menu();
    void MenuListados();
    void Agregar();
    void ListarTodos();
    void ListarActivos();
    bool ListarInactivos();
    void ListarOrdenadoPorApellido();
    void ListarOrdenadoPorDNI();
    void ListarOrdenadoPorObraSocial();
    void Modificar();
    void Eliminar();
    void AltaAfiliado();
    void BuscarPorDNI();
    void BuscarPorApellido();
};
