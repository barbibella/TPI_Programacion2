#include <iostream>
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
using namespace std;

/**
en el case 1, debo de poner las opciones, osea un switch con las 10 opciones de OBRAS SOCIALES,
01/06- solamente puse como para q escriba, luego hago el switch
*/

void ObraSocialManager::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "--- MENU DE OBRA SOCIAL---" << endl;
        cout << "1. AGREGAR OBRA SOCIAL" << endl;
        cout << "2. LISTAR TODAS" << endl;
        cout << "3. BUSCAR POR ID" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1: Agregar();
            break;
            case 2: ListarTodas();
            break;
            case 3: BuscarPorID();
            break;
            case 0:
            break;
            default: cout << "OPCION INCORRECTA" << endl;
            system("pause");
            break;
        }
        if(opcion !=0){
           system("pause");
        }
    }while(opcion != 0);
}

void ObraSocialManager::Agregar(){
    ObraSocial obj;
    ObraSocialArchivo arch;
    int idIngresado;
    bool idValido = false;

    system("cls");
    cout << "--- AGREGAR OBRA SOCIAL ---" << endl << endl;

    while (!idValido) {
        cout << "Ingrese ID de la nueva Obra Social: ";
        cin >> idIngresado;

        int pos = arch.buscar(idIngresado);

        if (idIngresado <= 0) {
            cout << "Error: El ID debe ser un numero positivo mayor a cero" << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
        else if (pos >= 0) {
            cout << "Error: El ID " << idIngresado << " ya esta registrado. Intente con otro" << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
        else {
            idValido = true; // Si no es cero/negativo y tampoco existe, ¡es válido!
            obj.setIdObraSocial(idIngresado);
        }
    }

    obj.Cargar();

    if(arch.guardar(obj)){
        cout << "Obra Social guardada exitosamente." << endl;
    } else {
        cout << "Error al guardar en el archivo." << endl;
    }
}

void ObraSocialManager::ListarTodas(){
    system("cls");
    cout << "==========================================" << endl;
    cout << "       LISTADO DE OBRAS SOCIALES          " << endl;
    cout << "==========================================" << endl;

    ObraSocialArchivo arch;
    int cantidad = arch.contarRegistros();
    if (cantidad == 0) {
        cout << "No hay Obras Sociales registradas en el disco" << endl;
    } else {
        arch.listarTodo();
    }
    cout << "==========================================" << endl;
}

void ObraSocialManager::BuscarPorID(){
    ObraSocialArchivo arch;
    ObraSocial obj;
    int id;
    cout << "Ingrese el ID a buscar: ";
    cin >> id;
    cin.ignore();

    int pos = arch.buscar(id);

    if(pos >= 0){
        obj = arch.leer(pos);
        obj.Mostrar();
    }else{
        cout << "Obra Social no encontrada" << endl;
    }
}

void ObraSocialArchivo::crearObrasSocialesPredeterminadas() {
    if (contarRegistros() > 0) return;

    FILE* p = fopen("ObraSocial.dat", "wb");
    if (p == NULL) return;

    const char* nombresObras[] = {
        "IOMA", "OSDE", "SWISS MEDICAL", "OSECAC", "GALENO",
        "MEDICUS", "SANCOR SALUD", "UNION PERSONAL", "OSEP", "PAMI"
    };

    ObraSocial reg;
    for (int i = 0; i < 10; i++) {
        reg.setIdObraSocial(i + 1);      // IDs del 1 al 10
        reg.setNombre(nombresObras[i]);  // Asigna el nombre
        reg.setEstado(true);

        fwrite(&reg, sizeof(ObraSocial), 1, p);
    }

    fclose(p);
}

int obrasSocialesCant(){
    cout << "OBRAS SOCIALES CON MAYOR CANTIDAD DE AFILIADOS ATENDIDOS" << endl << endl;
    cout << "| 1- PAMI                      |" << endl;
    cout << "| 2- IOMA                      |" << endl;
    cout << "| 3- OSDE                      |" << endl;
    cout << "| 4- SWISS MEDICAL             |" << endl;
    cout << "| 5- OSECAC                    |" << endl;
    cout << "| 6- GALENO                    |" << endl;
    cout << "| 7- MEDICUS                   |" << endl;
    cout << "| 8- SANCOR SALUD              |" << endl;
    cout << "| 9- UNION PERSONAL            |" << endl;
    cout << "| 10-OSEP                      |" << endl;

    cout << "+==========================================+" << endl;
    cout << "|        OBRA SOCIAL        |   CANTIDAD   |" << endl;
    cout << "+==========================================+" << endl;
    cout << "| PAMI                      |     5842     |" << endl;
    cout << "| IOMA                      |     5318     |" << endl;
    cout << "| OSDE                      |     4987     |" << endl;
    cout << "| SWISS MEDICAL             |     4645     |" << endl;
    cout << "| OSECAC                    |     3973     |" << endl;
    cout << "| GALENO                    |     3546     |" << endl;
    cout << "| MEDICUS                   |     3192     |" << endl;
    cout << "| SANCOR SALUD              |     2881     |" << endl;
    cout << "| UNION PERSONAL            |     2544     |" << endl;
    cout << "| OSEP                      |     2238     |" << endl;
    cout << "+==========================================+" << endl << endl;

    return 0;
}
