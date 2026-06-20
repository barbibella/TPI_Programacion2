#include <iostream>

using namespace std;

#include "AutorizacionManager.h"
#include "Autorizacion.h"
#include "AutorizacionArchivo.h"

void AutorizacionManager::menu(){

    int opcion;

    do{

        system("cls");

        cout << "===== AUTORIZACIONES =====" << endl;
        cout << "1. LISTAR TODAS LAS AUTORIZACIONES" << endl;
        cout << "2. AGREGAR UNA AUTORIZACION" << endl;
        cout << "3. BUSCAR POR CODIGO UNA AUTORIZACION" << endl;
        cout << "0. SALIR" << endl;
        cout << "OPCION: ";

        cin >> opcion;

        system("cls");

        switch(opcion){

        case 1:
            listarTodos();
            break;

        case 2:
            agregar();
            break;

        case 3:
            buscarPorCodigo();
            break;

        case 0:
            break;

        default:
            cout << "OPCION INCORRECTA" << endl;
            break;
        }

        system("pause");

    }while(opcion != 0);
}

void AutorizacionManager::listarTodos(){

    AutorizacionArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        Autorizacion reg;

        reg = archivo.leer(i);

        reg.Mostrar();
    }
}

void AutorizacionManager::agregar(){

    AutorizacionArchivo archivo;
    Autorizacion reg;

    reg.Cargar();

    if(archivo.guardar(reg)){
        cout << "La autorizacion se guardo correctamente!" << endl;
    }
    else{
        cout << "Error al guardar la autorizacion." << endl;
    }
}

void AutorizacionManager::buscarPorCodigo(){

    AutorizacionArchivo archivo;

    int codigo;

    cout << "Ingrese el codigo de autorizacion: ";
    cin >> codigo;

    int pos = archivo.buscar(codigo);

    if(pos == -1){

        cout << "No existe una autorizacion con ese codigo." << endl;
        return;
    }

    Autorizacion reg;

    reg = archivo.leer(pos);

    reg.Mostrar();
}
