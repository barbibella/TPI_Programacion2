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
        cout << "1. LISTAR TODAS LAS ORDENES" << endl;
        cout << "2. AGREGAR UNA ORDEN" << endl;
        cout << "3. BUSCAR POR ID UNA ORDEN" << endl;
        cout << "4. ELIMINAR UNA ORDEN" << endl;
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

void OrdenMedicaManager::listarTodos(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado()){
            reg.mostrar();
        }
    }
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
        cout << "No existe una orden con ese ID." << endl;
        return;
    }

    OrdenMedica reg = archivo.leer(pos);

    if(!reg.getEstado()){
        cout << "La orden ya se encuentra dada de baja." << endl;
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
            cout << "Orden dada de baja correctamente." << endl;
        }
        else{
            cout << "Error al actualizar la orden." << endl;
        }
    }
    else{
        cout << "Operacion cancelada." << endl;
    }
}

