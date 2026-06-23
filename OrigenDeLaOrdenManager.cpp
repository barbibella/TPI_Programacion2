#include <iostream>
#include <cstring>
#include "OrigenDeLaOrden.h"
#include "OrigenDeLaOrdenArchivo.h"
#include "OrigenDeLaOrdenManager.h"

using namespace std;

void OrigenDeLaOrdenManager::menu(){
    int opcion;

    do{
        system("cls");
        cout << "===== ORIGEN DE LA ORDEN MEDICA =====" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. MODIFICAR" << endl;
        cout << "7. ELIMINAR" << endl;
        cout << "8. REACTIVAR" << endl;
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

void OrigenDeLaOrdenManager::agregar(){
    OrigenDeLaOrdenArchivo archivo;
    OrigenDeLaOrden reg;

    reg.setIdOrigen(generarId());
    reg.cargar();

    if(archivo.guardar(reg)){
        cout << "El origen se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar" << endl;
    }
}

void OrigenDeLaOrdenManager::listarTodos(){
    OrigenDeLaOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrigenDeLaOrden reg;

        reg = archivo.leer(i);
        reg.mostrar();
    }

    system("pause");
}

void OrigenDeLaOrdenManager::listarActivos(){
    OrigenDeLaOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrigenDeLaOrden reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
}

void OrigenDeLaOrdenManager::listarInactivos(){
    OrigenDeLaOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        OrigenDeLaOrden reg;

        reg = archivo.leer(i);

        if(!reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
}

int OrigenDeLaOrdenManager::generarId(){
    OrigenDeLaOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    return cantidad + 1;
}

void OrigenDeLaOrdenManager::buscaPorID(){
    OrigenDeLaOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un origen de ordenes con ese ID" << endl;
        return;
    }

    OrigenDeLaOrden reg = archivo.leer(pos);
    reg.mostrar();
}

void OrigenDeLaOrdenManager::eliminar(){
    OrigenDeLaOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un origen con ese ID" << endl;
        return;
    }

    OrigenDeLaOrden reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El origen ya se encuentra dada de baja" << endl;
        return;
    }

    reg.mostrar();

    cout << endl;
    char opcion;
    cout << "Esta seguro que desea dar de baja este origen? (S/N): ";
    cin >> opcion;

    if(opcion == 'S' || opcion == 's'){
        reg.setEstado(false);

        if(archivo.modificar(reg, pos)){
            cout << "Orden dada de baja correctamente" << endl;
        }
        else{
            cout << "Error al actualizar el origen" << endl;
        }
    }
    else{
        cout << "Operacion cancelada" << endl;
    }
}

void OrigenDeLaOrdenManager::reactivar(){
    OrigenDeLaOrdenArchivo archivo;

    int id;

    cout << "Ingrese el ID del origen de la orden: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un origen de orden con ese ID" << endl;
        return;
    }

    OrigenDeLaOrden reg = archivo.leer(pos);

    if(reg.getEstado()){
        cout << "El origen de la orden ya se encuentra activo" << endl;
        return;
    }

    reg.setEstado(true);

    if(archivo.modificar(reg, pos)){
        cout << "Origen reactivado correctamente" << endl;
    } else {
        cout << "Error  al reactivar el orgien de la orden" << endl;
    }
}

void OrigenDeLaOrdenManager::modificar(){
    OrigenDeLaOrdenArchivo archivo;

    int id;
    cout << "Ingrese el ID a modificar: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe un origen de la orden con ese ID." << endl;
        system("pause");
        return;
    }

     OrigenDeLaOrden reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "El origen de la orden esta dado de baja. No se puede modificar" << endl;
        system("pause");
        return;
    }

    cout << "DATOS ACTUALES:" << endl;
    reg.mostrar();

    cout << endl;
    char confirma;
    cout << "Esta seguro que desea modificarlo? (S/N): ";
    cin >> confirma;

    if(confirma != 'S' && confirma != 's'){
        cout << "Operacion cancelada." << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << "Nueva descripcion: ";
    reg.cargar();

    reg.setIdOrigen(id);

    if(archivo.modificar(reg, pos)){
        cout << "Origen de la orden modificado correctamente" << endl;
    }
    else{
        cout << "Error al modificar" << endl;
    }

    system("pause");
}

