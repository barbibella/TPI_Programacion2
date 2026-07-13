#include <iostream>
#include <cstdio>
#include "ObraSocialMenu.h"

using namespace std;

ObraSocialMenu::ObraSocialMenu()
{
    setCantidadOpciones(8);
}

void ObraSocialMenu::mostrarOpciones(){
        cout << "--- MENU DE OBRAS SOCIALES ---" << endl;
        cout << "1. AGREGAR OBRA SOCIAL" << endl;
        cout << "2. LISTAR TODAS" << endl;
        cout << "3. LISTAR ACTIVAS" << endl;
        cout << "4. LISTAR INACTIVAS" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. MODIFICAR OBRA SOCIAL" << endl;
        cout << "7. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "8. RECONECTAR OBRA SOCIAL (ALTA)" << endl;
        cout << "------------------------------" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
}

void ObraSocialMenu::ejecutarOpcion(int opcion){
        switch(opcion){
            case 1: _managerObraSocial.Agregar(); break;
            case 2: _managerObraSocial.ListarTodas(); break;
            case 3: _managerObraSocial.ListarActivas(); break;
            case 4: _managerObraSocial.ListarInactivas(); break;
            case 5: _managerObraSocial.BuscarPorID(); break;
            case 6: _managerObraSocial.Modificar(); break;
            case 7: _managerObraSocial.Eliminar(); break;
            case 8: _managerObraSocial.AltaObraSocial(); break;
            case 0: cout << "Saliendo del menu" << endl; system("pause"); break;
        }
}
