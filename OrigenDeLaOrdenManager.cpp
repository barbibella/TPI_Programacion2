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
        cout << "1. LISTAR DE DONDE PUEDE VENIR CADA ORDEN MEDICA" << endl;
        cout << "2. AGREGAR UN ORIGEN" << endl;
        cout << "3. ELIMINAR UN ORIGEN" << endl;
        cout << "4. MODIFICAR UN ORIGEN" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "0. SALIR" << endl;
        cout << "OPCION: ";

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                listarOrigenes();
                break;
            case 2:
                altaOrigen();
                break;
            /* case 3:
                bajaOrden();
                break;
            case 4:
                modificarOrden();
                break;
            case 5:
                buscarPorId();
                break; */
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }
        system("pause");
    }while(opcion != 0);
}

void OrigenDeLaOrdenManager::listarOrigenes(){
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

void OrigenDeLaOrdenManager::altaOrigen(){
    OrigenDeLaOrdenArchivo archivo;

    OrigenDeLaOrden reg;

    reg.cargar();

    if(archivo.guardar(reg)){
        cout << "La orden medica se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar la orden" << endl;
    }


}


