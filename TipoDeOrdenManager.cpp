#include <iostream>
#include <cstring>
#include "TipoDeOrden.h"
#include "TipoDeOrdenArchivo.h"
#include "TipoDeOrdenManager.h"

using namespace std;

void TipoDeOrdenManager::menu(){
    int opcion;

    do{
        system("cls");
        cout << "===== TIPOS DE ORDENES =====" << endl;
        cout << "1. LISTAR TODOS LOS TIPOS DE ORDENES" << endl;
        cout << "2. AGREGAR UN TIPO DE ORDEN" << endl;
        cout << "3. BUSCAR POR ID" << endl;
        cout << "4. ELIMINAR UN TIPO DE ORDEN" << endl;
        cout << "5. REACTIVAR UN TIPO DE ORDEN" << endl;
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
                buscaPorID();
                break;
            case 4:
                eliminar();
                break;
            case 5:
                reactivar();
                break;
            case 0:
                cout << "Saliendo.." << endl;
                break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                system("pause");
                break;
        }
    }while(opcion != 0);
}

void TipoDeOrdenManager::listarTodos(){
    TipoDeOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        TipoDeOrden reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }
}

void TipoDeOrdenManager::agregar(){
    TipoDeOrdenArchivo archivo;
    TipoDeOrden reg;

    reg.setIdTipoOrden(generarId());
    reg.cargar();

    if(archivo.guardar(reg)){
        cout << "El tipo de orden se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar el tipo de orden" << endl;
    }
}

int TipoDeOrdenManager::generarId(){
    TipoDeOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    return cantidad + 1;
}

void TipoDeOrdenManager::buscaPorID(){
    TipoDeOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID: " << endl;
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un tipo de orden con ese ID" << endl;
        return;
    }

    TipoDeOrden reg = archivo.leer(pos);
    reg.mostrar();
}

void TipoDeOrdenManager::eliminar(){
    TipoDeOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un tipo de orden con ese ID" << endl;
        return;
    }

    TipoDeOrden reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El tipo de orden ya se encuentra dado de baja" << endl;
        return;
    }

    reg.mostrar();

    cout << endl;
    char opcion;
    cout << "Esta seguro que desea dar de baja este tipo de orden? (S/N): ";
    cin >> opcion;

    if(opcion == 'S' || opcion == 's'){
        reg.setEstado(false);

        if(archivo.modificar(reg, pos)){
            cout << "Tipo de orden dado de baja correctamente" << endl;
        }
        else{
            cout << "Error al actualizar el tipo de orden" << endl;
        }
    }
    else{
        cout << "Operacion cancelada" << endl;
    }
}

void TipoDeOrdenManager::reactivar(){
    TipoDeOrdenArchivo archivo;

    int id;

    cout << "Ingrese el id del tipo de orden: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un tipo de orden con ese ID" << endl;
        return;
    }

    TipoDeOrden reg = archivo.leer(pos);

    if(reg.getEstado()){
        cout << "El tipo de orden ya se encuentra activo" << endl;
        return;
    }

    reg.setEstado(true);

    if(archivo.modificar(reg, pos)){
        cout << "Tipo de orden reactivado correctamente" << endl;
    } else {
        cout << "Error  al reactivar el tipo de orden" << endl;
    }
}

