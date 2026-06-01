#include <iostream>
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
using namespace std;

/**
en el case 1, debo de poner las opciones, osea un switch con las 10 opciones de OBRAS SOCIALES,
*/

void ObraSocialManager::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "--- MENU DE OBRA SOCIAL---" << endl;
        cout << "1. AGREGAR OBRA SOCIAL" << endl;
        cout << "2. LISTAR TODAS" << endl;
        cout << "3. BUSCAR POR ID" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");
        cin.ignore();

        switch(opcion){
            case 1: Agregar();
            break;
            case 2: ListarTodas();
            break;
            case 3: BuscarPorID();
            break;
            default: cout << "OPCION INCORRECTA" << endl;
        }
        system("pause");
    }while(opcion != 0);
}

void ObraSocialManager::Agregar(){
    ObraSocial obj;
    ObraSocialArchivo arch;

    obj.Cargar();

    if(arch.guardar(obj)){
        cout << "Obra Social guardada" << endl;
    }else{
        cout << "Errror al abrir el archivo" << endl;
    }
}
void ObraSocialManager::ListarTodas(){
   ObraSocialArchivo arch;
    arch.listarTodo();
}
void ObraSocialManager::BuscarPorID(){
    ObraSocialArchivo arch;
    ObraSocial obj;
    int id;
    cout << "Ingrese el ID a buscar: ";
    cin >> id;
    cin.ignore();

    int pos = arch.buscar(id);

    if(pos >= 0 && pos != 412 && pos != 413){
        obj = arch.leer(pos);
        obj.Mostrar();
    }else{
        cout << "Obra Social no encontrada" << endl;
    }
}

int obrasSocialesCant(){
    cout << "OBRAS SOCIALES CON MAYOR CANTIDAD DE AFILIADOS ATENDIDOS" << endl << endl;

    cout << "+==========================================+" << endl;
    cout << "|        OBRA SOCIAL        |   CANTIDAD   |" << endl;
    cout << "+==========================================+" << endl;
    cout << "| PAMI                      |     5842     |" << endl;
    cout << "| IOMA                      |     5318     |" << endl;
    cout << "| OSDE                      |     4987     |" << endl;
    cout << "| SWISS MEDICAL             |     4645     |" << endl;
    cout << "| OSECAC                    |     3973     |" << endl;
    cout << "| GALENO                    |     3546     |" << endl;
    cout << "| MEDICUS                   |     3192     |" << endl;
    cout << "| SANCOR SALUD              |     2881     |" << endl;
    cout << "| UNION PERSONAL            |     2544     |" << endl;
    cout << "| OSEP                      |     2238     |" << endl;
    cout << "+==========================================+" << endl << endl;

    return 0;
}
