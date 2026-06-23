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
        cout << "===== TIPO DE ORDEN MEDICA =====" << endl;
        cout << "1. AGREGAR UN TIPO DE ORDEN" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. MODIFICAR UN TIPO DE ORDEN" << endl;
        cout << "7. ELIMINAR UN TIPO DE ORDEN" << endl;
        cout << "8. REACTIVAR UN TIPO DE ORDEN" << endl;
        cout << "-------------------------" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                agregar();
                break;
            case 2:
                listarTodos();
                break;
            case 3:
                listarActivos();
                break;
            case 4:
                listarInactivos();
                break;
            case 5:
                buscaPorID();
                break;
            case 6:
                modificar();
                break;
            case 7:
                eliminar();
                break;
            case 8:
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

void TipoDeOrdenManager::listarTodos(){
    TipoDeOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        TipoDeOrden reg;

        reg = archivo.leer(i);
        reg.mostrar();
    }

    system("pause");
}

void TipoDeOrdenManager::listarActivos(){
    TipoDeOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        TipoDeOrden reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
}

void TipoDeOrdenManager::listarInactivos(){
    TipoDeOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        TipoDeOrden reg;

        reg = archivo.leer(i);

        if(!reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
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

void TipoDeOrdenManager::modificar(){
    TipoDeOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID del tipo de orden a modificar: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un tipo de orden con ese ID." << endl;
        system("pause");
        return;
    }

     TipoDeOrden reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El tipo de orden esta dado de baja. No se puede modificar" << endl;
        system("pause");
        return;
    }

    cout << "DATOS ACTUALES:" << endl;
    reg.mostrar();

    cout << endl;
    char confirma;
    cout << "Esta seguro que desea modificar este tipo de orden? (S/N): ";
    cin >> confirma;

    if(confirma != 'S' && confirma != 's'){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << "Nueva descripcion: ";
    reg.cargar();

    reg.setIdTipoOrden(id); // Mantiene el mismo ID

    if(archivo.modificar(reg, pos)){
        cout << "Tipo de orden modificado correctamente" << endl;
    }
    else{
        cout << "Error al modificar" << endl;
    }

    system("pause");
}

