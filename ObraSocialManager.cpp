#include <iostream>
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
using namespace std;

/**
en el case 1, debo de poner las opciones, osea un switch con las 10 opciones de OBRAS SOCIALES,
*/

//Auxiliar privado creador
ObraSocial ObraSocialManager::crearObraSocial(){
    string nombre;
    int idIngresado;
    bool idValido = false;

    cout << "--- CARGA DE OBRA SOCIAL ---" << endl << endl;

    while (!idValido) {
        cout << "Ingrese ID de la nueva Obra Social: ";
        cin >> idIngresado;

        int pos = archivo.buscar(idIngresado);

        if (idIngresado <= 0) {
            cout << "Error: El ID debe ser un numero positivo mayor a cero" << endl;
        } else if (pos >= 0) {
            cout << "Error: El ID " << idIngresado << " ya esta registrado." << endl;
        } else {
            idValido = true;
        }
    }

    ObraSocial reg;
    reg.setIdObraSocial(idIngresado);
    reg.Cargar(); // Pide el nombre
    return reg;
}

void ObraSocialManager::mostrarObraSocial(ObraSocial reg){
    cout << "-----------------------------------------" << endl;
    reg.Mostrar();
}

void ObraSocialManager::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "--- MENU DE OBRAS SOCIALES ---" << endl;
        cout << "1. AGREGAR OBRA SOCIAL" << endl;
        cout << "2. LISTAR TODAS" << endl;
        cout << "3. LISTAR ACTIVAS" << endl;
        cout << "4. LISTAR INACTIVAS" << endl;
        cout << "5. BUSCAR POR ID" << endl;
        cout << "6. MODIFICAR OBRA SOCIAL" << endl;
        cout << "7. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "8. RECONECTAR OBRA SOCIAL (ALTA)" << endl;
        cout << "------------------------------" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1: Agregar(); break;
            case 2: ListarTodas(); break;
            case 3: ListarActivas(); break;
            case 4: ListarInactivas(); break;
            case 5: BuscarPorID(); break;
            case 6: Modificar(); break;
            case 7: Eliminar(); break;
            case 8: AltaObraSocial(); break;
            case 0: break;
            default: cout << "OPCION INCORRECTA" << endl; system("pause"); break;
        }
        if(opcion !=0){
           system("pause");
        }
    }while(opcion != 0);
}

void ObraSocialManager::Agregar(){
    ObraSocial obj = crearObraSocial();
    if(archivo.guardar(obj)){
        cout << "Obra Social guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar en el archivo." << endl;
    }
}

void ObraSocialManager::ListarTodas(){
    int cantidad = archivo.contarRegistros();
    if (cantidad == 0) {
        cout << "No hay Obras Sociales registradas." << endl;
    } else {
        for (int i = 0; i < cantidad; i++){
            ObraSocial o = archivo.leer(i);
            mostrarObraSocial(o);
        }
    }
}

void ObraSocialManager::ListarActivas(){
    int cantidad = archivo.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        ObraSocial o = archivo.leer(i);
        if(o.getEstado() == true) mostrarObraSocial(o);
    }
}

bool ObraSocialManager::ListarInactivas(){
    int cantidad = archivo.contarRegistros();
    bool hayBajas = false;
    cout << "--- OBRAS SOCIALES DADAS DE BAJA ---" << endl;
    for (int i = 0; i < cantidad; i++){
        ObraSocial o = archivo.leer(i);
        if(o.getEstado() == false){
            cout << "ID: " << o.getId() << " - Nombre: " << o.getNombre() << endl;
            hayBajas = true;
        }
    }
    if(!hayBajas) cout << "NO HAY OBRAS SOCIALES INACTIVAS." << endl;
    return hayBajas;
}

void ObraSocialManager::BuscarPorID(){
    int id;
    cout << "Ingrese el ID a buscar: ";
    cin >> id;

    int pos = archivo.buscar(id);

    if(pos >= 0){
        ObraSocial obj = archivo.leer(pos);
        mostrarObraSocial(obj);
    }else{
        cout << "Obra Social no encontrada." << endl;
    }
}

void ObraSocialManager::Modificar(){
    int id, modifica;
    cout << "Ingrese el ID de la Obra Social a modificar: ";
    cin >> id;

    int pos = archivo.buscar(id);
    if (pos == -1){
        cout << "El ID no existe." << endl;
        return;
    }
    ObraSocial reg = archivo.leer(pos);
    mostrarObraSocial(reg);

    cout << "Desea modificar esta Obra Social? 1-Si 0-No: ";
    cin >> modifica;

    if (modifica == 1){
        reg.Cargar(); /// Modifica el nombre
        if (archivo.modificar(reg, pos)) cout << "¡Guardado exitosamente!" << endl;
        else cout << "Error al guardar." << endl;
    }
}

void ObraSocialManager::Eliminar(){
    int id, elimina;
    cout << "Ingrese el ID de la Obra Social a dar de baja: ";
    cin >> id;

    int pos = archivo.buscar(id);
    if (pos == -1){
        cout << "El ID no existe." << endl;
        return;
    }

    ObraSocial reg = archivo.leer(pos);
    if(reg.getEstado() == false){
        cout << "Ya se encuentra dada de baja." << endl;
        return;
    }

    mostrarObraSocial(reg);
    cout << "Seguro que desea eliminarla? 1-Si 0-No: ";
    cin >> elimina;

    if(elimina == 1){
        reg.setEstado(false);
        if(archivo.modificar(reg, pos)) cout << "Dada de baja con exito." << endl;
    }
}

void ObraSocialManager::AltaObraSocial(){
    if(ListarInactivas()){
        int id, alta;
        cout << endl << "Ingrese ID a reactivar: ";
        cin >> id;

        int pos = archivo.buscar(id);
        if(pos == -1) return;

        ObraSocial reg = archivo.leer(pos);
        if(reg.getEstado() == true){
            cout << "Ya esta activa." << endl;
            return;
        }

        cout << "Confirmar Alta? 1-Si 0-No: ";
        cin >> alta;

        if(alta == 1){
            reg.setEstado(true);
            archivo.modificar(reg, pos);
            cout << "¡Reactivada!" << endl;
        }
    }
}

