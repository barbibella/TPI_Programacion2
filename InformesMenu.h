#pragma once
#include "Menu.h"
#include "InformesManager.h"

/// ----- MAI -----

class InformesMenu : public Menu
{
    public:InformesMenu();

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    private:
        InformesManager _managerInformes;
};
