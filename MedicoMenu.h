#pragma once
#include "MenuCls.h"
#include "MedicoManager.h"

/// ----- MAI -----

class MedicoMenu : public Menu
{
    public:MedicoMenu();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    private:
        MedicoManager _managerMedico;
};
