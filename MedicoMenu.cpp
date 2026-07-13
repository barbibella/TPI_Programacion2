#include <cstdio>
#include <iostream>
#include "MedicoMenu.h"

/// ----- MAI -----
using namespace std;

MedicoMenu::MedicoMenu()
{
    setCantidadOpciones(8);
}

void MedicoMenu::mostrarOpciones(){

        cout << "=== MENU MEDICOS ===" << endl;
        cout << "1. AGREGAR MEDICO" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. BUSCAR INFORMACION MEDICO" << endl;
        cout << "6. MODIFICAR MEDICO" << endl;
        cout << "7. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "8. ALTA DE MEDICO (RECUPERAR)" << endl;
        cout << "=========================" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;

}
void MedicoMenu::ejecutarOpcion(int opcion){
    switch(opcion){
            case 1: _managerMedico.guardarMedico();
                break; //AGREGAR
            case 2: _managerMedico.listarMedicos();
                break; //LISTAR TODOS
            case 3: _managerMedico.listarMActivos();
                break;
            case 4: _managerMedico.listarInactivos();
                break;
            case 5: _managerMedico.informacionMedico();
                break; ///Está en MedicoArchivo
            case 6: _managerMedico.modificarMedico();
                break;
            case 7: _managerMedico.eliminarMedico();
                break; // BAJA LOGICA
            case 8: _managerMedico.altaMedico();
                break;    // ALTA LOGICA
            case 0: cout << "Saliendo del menu" << endl;
                break;
            }
}
