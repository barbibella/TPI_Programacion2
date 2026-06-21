#include <iostream>
#include <cstring>
#include "OrdenMedica.h"
#include "OrdenMedicaArchivo.h"
#include "OrdenMedicaManager.h"

using namespace std;

void OrdenMedicaManager::menu(){
    int opcion;

    do{
        system("cls");
        cout << "===== ORDENES MEDICAS =====" << endl;
        cout << "1. AGREGAR UNA ORDEN" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. MODIFICAR ORDEN MEDICA" << endl;
        cout << "7. ELIMINAR UNA ORDEN" << endl;
        cout << "8. REACTIVAR UNA ORDEN" << endl;
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

void OrdenMedicaManager::agregar(){
    OrdenMedicaArchivo archivo;
    OrdenMedica reg;

    reg.setIdOrden(generarId());
    reg.cargar();

    if(archivo.guardar(reg)){
        cout << "La orden medica se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar la orden" << endl;
    }


}

void OrdenMedicaManager::listarTodos(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);
        reg.mostrar();
    }

    system("pause");
}

void OrdenMedicaManager::listarActivos(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
}

void OrdenMedicaManager::listarInactivos(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(!reg.getEstado()){
            reg.mostrar();
        }
    }

    system("pause");
}

int OrdenMedicaManager::generarId(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    return cantidad + 1;
}

void OrdenMedicaManager::buscaPorID(){
    OrdenMedicaArchivo archivo;

    int id;
    cout << "Ingrese el ID: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe una orden con ese ID." << endl;
        return;
    }

    OrdenMedica reg = archivo.leer(pos);
    reg.mostrar();
}

void OrdenMedicaManager::eliminar(){
    OrdenMedicaArchivo archivo;

    int id;
    cout << "Ingrese el ID: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe una orden con ese ID" << endl;
        return;
    }

    OrdenMedica reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "La orden ya se encuentra dada de baja" << endl;
        return;
    }

    reg.mostrar();

    cout << endl;
    char opcion;
    cout << "Esta seguro que desea dar de baja esta orden? (S/N): ";
    cin >> opcion;

    if(opcion == 'S' || opcion == 's'){
        reg.setEstado(false);

        if(archivo.modificar(reg, pos)){
            cout << "Orden dada de baja correctamente" << endl;
        }
        else{
            cout << "Error al actualizar la orden" << endl;
        }
    }
    else{
        cout << "Operacion cancelada" << endl;
    }
}

void OrdenMedicaManager::reactivar(){
    OrdenMedicaArchivo archivo;

    int id;

    cout << "Ingrese el ID de la orden: ";
    cin >> id;

    int pos = archivo.buscarId(id);

    if(pos == -1){
        cout << "No existe una orden con ese ID" << endl;
        return;
    }

    OrdenMedica reg = archivo.leer(pos);

    if(reg.getEstado()){
        cout << "La orden ya se encuentra activa" << endl;
        return;
    }

    reg.setEstado(true);

    if(archivo.modificar(reg,pos)){
        cout << "Orden reactivada correctamente" << endl;
    } else {
        cout << "Error  al reactivar la orden" << endl;
    }
}
