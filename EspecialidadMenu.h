#pragma once
#include "MenuCls.h"
#include "EspecialidadManager.h"

/// ----- MAI -----

class EspecialidadMenu : public Menu
{
    public:EspecialidadMenu();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    private:
        EspecialidadManager _managerEspecialidad;
};

