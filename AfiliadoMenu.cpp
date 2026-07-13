#include <iostream>
#include <cstdio>
#include "AfiliadoMenu.h"

using namespace std;

AfiliadoMenu::AfiliadoMenu()
{
    setCantidadOpciones(10);
}

void AfiliadoMenu::mostrarOpciones(){
        cout << "--- MENU DE AFILIADOS ---" << endl;
        cout << "1. AGREGAR AFILIADO" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. LISTADOS ORDENADOS..." << endl;
        cout << "6. BUSCAR POR DNI" << endl;
        cout << "7. BUSCAR POR APELLIDO" << endl;
        cout << "8. MODIFICAR AFILIADO" << endl;
        cout << "9. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "10. ALTA DE AFILIADO (RECUPERAR)" << endl;
        cout << "-------------------------" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
}

void AfiliadoMenu::ejecutarOpcion(int opcion){
        switch(opcion){
            case 1: _managerAfiliado.Agregar(); break;
            case 2: _managerAfiliado.ListarTodos(); break;
            case 3: _managerAfiliado.ListarActivos(); break;
            case 4: _managerAfiliado.ListarInactivos(); break;
            case 5: _managerAfiliado.MenuListados(); break;
            case 6: _managerAfiliado.BuscarPorDNI(); break;
            case 7: _managerAfiliado.BuscarPorApellido(); break;
            case 8: _managerAfiliado.Modificar(); break;
            case 9: _managerAfiliado.Eliminar(); break;
            case 10: _managerAfiliado.AltaAfiliado(); break;
            case 0: cout << "Saliendo del menu" << endl; break;
        }
}
