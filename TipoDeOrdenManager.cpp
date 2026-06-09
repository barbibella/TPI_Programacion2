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
        cout << "3. ELIMINAR UN TIPO DE ORDEN" << endl;
        cout << "4. MODIFICAR UN TIPO DE ORDEN" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. LISTADOS" << endl;
        cout << "7. CONSULTAS" << endl;
        cout << "0. SALIR" << endl;
        cout << "OPCION: ";

        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                listarTipos();
                break;
            case 2:
                altaTipo();
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

void TipoDeOrdenManager::listarTipos(){
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

void TipoDeOrdenManager::altaTipo(){
    TipoDeOrdenArchivo archivo;

    TipoDeOrden reg;

    reg.cargar();

    if(archivo.guardar(reg)){
        cout << "La orden medica se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar la orden" << endl;
    }


}


