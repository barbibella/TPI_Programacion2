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
    void Agregar();
    void ListarTodos();
    void ListarActivos();
    bool ListarInactivos();
    void Modificar();
    void Eliminar();
    void AltaAfiliado();
    void BuscarPorDNI();
};
