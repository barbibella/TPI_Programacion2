#include <iostream>
#include "Afiliado.h"
#include "AfiliadoArchivo.h"
#include "AfiliadoManager.h"

using namespace std;

void AfiliadoManager::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "--- MENU DE AFILIADOS ---" << endl;
        cout << "1. AGREGAR AFILIADO" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. BUSCAR POR DNI" << endl;
        cout << "4. ELIMINAR" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1: Agregar();
            break;
            case 2: ListarTodos();
            break;
            case 3: BuscarPorDNI();
            break;
            case 4: Eliminar();
            break;
            case 0:
            break;
            default: cout << "OPCION INCORRECTA" << endl;
            system("pause");
            break;
        }
        if (opcion != 0 && opcion >= 1 && opcion <= 4) {
            system("pause");
        }
    }while(opcion != 0);
}
void AfiliadoManager::Agregar(){
    Afiliado obj;
    AfiliadoArchivo arch;

    int cantidad = arch.contarRegistros();
    int nuevoNumero = 1000 + cantidad;

    obj.Cargar(nuevoNumero);

    if(arch.guardar(obj)){
        cout << "Afiliado guardado" << endl;
    }else{
        cout << "Errror al abrir el archivo" << endl;
    }
}
void AfiliadoManager::ListarTodos(){
    cout << "--- LISTA DE AFILIADO ---" << endl << endl;
    AfiliadoArchivo arch;
    arch.listarTodo();
}
void AfiliadoManager::BuscarPorDNI(){
    AfiliadoArchivo arch;
    char dni[15];
    cout << "--- BUSCAR AFILIADO POR DNI ---" << endl << endl;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dni;

    int pos = arch.buscar(dni);

    if(pos >= 0){
        Afiliado obj = arch.leer(pos);
        obj.Mostrar();
    }else{
        cout << "Afiliado no encontrado" << endl;
    }
}

void AfiliadoManager::Eliminar() {
    system("cls");
    AfiliadoArchivo arch;
    char dni[15];

    cout << "--- BAJA LOGICA DE AFILIADO ---" << endl << endl;
    cout << "Ingrese el DNI del afiliado a dar de baja: ";
    cin >> dni;

    int pos = arch.buscar(dni);

    if (pos >= 0) {
        Afiliado obj = arch.leer(pos);

        if (obj.getEstado() == false){
            cout << "El afiliado ya se encuentra dado de baja en el sistema" << endl;
            return;
        }

        cout << "Se borrara el siguiente registro:" << endl;
        obj.Mostrar();

        char confirmacion;
        cout << "Estas seguro de que quieres eliminar el afiliado? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            obj.setEstado(false);

            if (arch.modificar(obj, pos)){
                cout << "Afiliado dado de baja correctamente" << endl;
            }else {
                cout << "No se pudo actualizar el archivo" << endl;
            }
        }else {
            cout << "Operacion cancelada por el usuario" << endl;
        }

    }else {
        cout << "No se encontro ningun afiliado con el DNI ingresado" << endl;
    }
}
