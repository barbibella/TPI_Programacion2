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
        cout << "===== ORIGEN DE LAS ORDENES MEDICAS =====" << endl;
        cout << "1. LISTAR ORIGEN DE ORDENES MEDICAS" << endl;
        cout << "2. AGREGAR UN ORIGEN" << endl;
        cout << "3. BUSCAR POR ID" << endl;
        cout << "4. ELIMINAR" << endl;
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
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
        system("pause");
    }while(opcion != 0);
}

void OrigenDeLaOrdenManager::listarTodos(){
    OrigenDeLaOrdenArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrigenDeLaOrden reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }
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
