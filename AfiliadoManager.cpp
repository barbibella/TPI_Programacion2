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
            default: cout << "OPCION INCORRECTA" << endl;

        }
        system("pause");
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
    AfiliadoArchivo arch;
    arch.listarTodo();
}
void AfiliadoManager::BuscarPorDNI(){
    AfiliadoArchivo arch;
    char dni[15];
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

    // 1. Buscamos la posicion del afiliado en el archivo binario
    int pos = arch.buscar(dni);

    // Verificamos si existe (asumiendo tus codigos de error 412 y 413)
    if (pos >= 0 && pos != 412 && pos != 413) {

        // 2. Leemos el registro completo de esa posicion
        Afiliado obj = arch.leer(pos);

        // 3. Controlamos si ya estaba dado de baja previamente
        if (obj.getEstado() == false) {
            cout << "El afiliado ya se encuentra dado de baja en el sistema." << endl;
            return;
        }

        // 4. Le mostramos los datos al usuario para que confirme que es la persona correcta
        cout << "Se borrara el siguiente registro:" << endl;
        obj.Mostrar();

        char confirmacion;
        cout << "Estas seguro de que quieres eliminar el afiliado? (S/N): ";
        cin >> confirmacion;

        if (confirmacion == 'S' || confirmacion == 's') {
            // 5. Cambiamos el estado a false (baja logica)
            obj.setEstado(false);

            // 6. Impactamos el cambio en el disco usando funcion modificar
            if (arch.modificar(obj, pos)) {
                cout << "Afiliado dado de baja correctamente." << endl;
            } else {
                cout << "No se pudo actualizar el archivo." << endl;
            }
        } else {
            cout << "Operacion cancelada por el usuario." << endl;
        }

    } else {
        cout << "No se encontro ningun afiliado con el DNI ingresado." << endl;
    }
}
