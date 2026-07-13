#include <cstdio>
#include <iostream>
#include "EspecialidadMenu.h"

/// ----- MAI -----
using namespace std;

EspecialidadMenu::EspecialidadMenu()
{
    setCantidadOpciones(8);
}

void EspecialidadMenu::mostrarOpciones(){

        cout << "=== MENU ESPECIALIDAD ===" << endl;
        cout << "1. AGREGAR ESPECIALIDAD" << endl;    //guardarEspecialidad
        cout << "2. LISTAR TODAS" << endl;
        cout << "3. LISTAR ACTIVAS" << endl;
        cout << "4. LISTAR INACTIVAS" << endl;
        cout << "5. BUSCAR INFORMACION ESPECIALIDAD" << endl;
        cout << "6. MODIFICAR ESPECIALIDAD" << endl;
        cout << "7. ELIMINAR ESPECIALIDAD " << endl; /// BAJA LÓGICA
        cout << "8. ALTA DE ESPECIALIDAD (RECUPERAR)" << endl;
        cout << "=========================" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;

}

void EspecialidadMenu::ejecutarOpcion(int opcion){
     switch(opcion){
            case 1: _managerEspecialidad.guardarEspecialidad();
             break; //AGREGAR
            case 2: _managerEspecialidad.listarEspecialidad();
            break; //LISTAR TODOS
//            case 3: _managerEspecialidad.listarEspActivos(); ///FALTA HACER
 //           break;  /// copiar de medicos el metodo acá y luego cambiar variables
//            case 4: _managerEspecialidad.listarEspInactivos(); ///FALTA HACER
//            break; /// copiar de medicos el metodo acá y luego cambiar variables
//            case 5: _managerEspecialidad.informacionEspecialidad();
//            break;
//            case 6: _managerEspecialidad.modificarEspecialidad();
            break;
            case 7: _managerEspecialidad.eliminarEspecialidad();
            break;
 //           case 8: _managerEspecialidad.altaEspecialidad();  /// FALTA HACER ALTA LOGICA
 //           break;
            case 0: break;
            default: cout << "OPCION INCORRECTA" << endl; system("pause");
                    break;
            }
}
