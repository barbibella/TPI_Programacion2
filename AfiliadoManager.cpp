#include <iostream>
#include <cstring>
#include <string>
#include "Afiliado.h"
#include "AfiliadoArchivo.h"
#include "AfiliadoManager.h"

using namespace std;

AfiliadoManager::AfiliadoManager() : _repoAfiliado() {}

void AfiliadoManager::Menu(){
    int opcion;
    do{
        system("cls");
        cout << "--- MENU DE AFILIADOS ---" << endl;
        cout << "1. AGREGAR AFILIADO" << endl;
        cout << "2. LISTAR TODOS" << endl;
        cout << "3. LISTAR ACTIVOS" << endl;
        cout << "4. LISTAR INACTIVOS" << endl;
        cout << "5. BUSCAR POR DNI" << endl;
        cout << "6. MODIFICAR AFILIADO" << endl;
        cout << "7. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "8. ALTA DE AFILIADO (RECUPERAR)" << endl;
        cout << "-------------------------" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1: Agregar(); break;
            case 2: ListarTodos(); break;
            case 3: ListarActivos(); break;
            case 4: ListarInactivos(); break;
            case 5: BuscarPorDNI(); break;
            case 6: Modificar(); break;
            case 7: Eliminar(); break;
            case 8: AltaAfiliado(); break;
            case 0: break;
            default: cout << "OPCION INCORRECTA" << endl; system("pause"); break;
        }
        if (opcion != 0 && opcion >= 1 && opcion <= 8) {
            system("pause");
        }
    }while(opcion != 0);
}

Afiliado AfiliadoManager::crearAfiliado(){
    string nombre, apellido, dni, telefono, mail;
    int idObraSocial, nuevoNumero;
    Fecha fNac;

    int cantidad = _repoAfiliado.contarRegistros();
    nuevoNumero = 1000 + cantidad;

    cout << "--- CARGA DE DATOS AFILIADO ---" << endl;
    cout << "SU NUMERO DE AFILIADO ASIGNADO ES: " << nuevoNumero << endl;

    cout << "Ingrese Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese Apellido: ";
    getline(cin, apellido);
    cout << "Ingrese DNI: ";
    cin >> dni;
    cout << "Ingrese Telefono: ";
    cin >> telefono;

    Afiliado reg(nuevoNumero, 0, "", fNac, nombre, apellido, dni, telefono, true);
    reg.Cargar(nuevoNumero);

    return reg;
}

void AfiliadoManager::Agregar(){
    Afiliado obj = crearAfiliado();
    if(_repoAfiliado.guardar(obj)){
        cout << "Afiliado guardado exitosamente." << endl;
    }else{
        cout << "Error al guardar en el archivo" << endl;
    }
}

void AfiliadoManager::ListarTodos(){
    cout << "--- LISTA GENERAL DE AFILIADOS ---" << endl << endl;
    int cantidad = _repoAfiliado.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        Afiliado a = _repoAfiliado.leer(i);
        mostrarAfiliado(a);
    }
}

void AfiliadoManager::ListarActivos(){
    cout << "--- AFILIADOS ACTIVOS ---" << endl << endl;
    int cantidad = _repoAfiliado.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        Afiliado a = _repoAfiliado.leer(i);
        if(a.getEstado() == true){
           mostrarAfiliado(a);
        }
    }
}

bool AfiliadoManager::ListarInactivos(){
    int cantidad = _repoAfiliado.contarRegistros();
    bool hayEliminados = false;

    cout << "--- AFILIADOS DADOS DE BAJA ---" << endl << endl;
    for (int i = 0; i < cantidad; i++){
        Afiliado a = _repoAfiliado.leer(i);
        if(a.getEstado() == false){
           cout << "Nro Afiliado: #" << a.getNroDeAfiliado() << endl;
           cout << "Nombre completo: " << a.getApellido() << ", " << a.getNombre() << endl;
           cout << "DNI: " << a.getDni() << endl;
           cout << "******************************" << endl;
           hayEliminados = true;
        }
    }
    if(!hayEliminados){
        cout << "NO HAY AFILIADOS DADOS DE BAJA" << endl;
    }
    return hayEliminados;
}

void AfiliadoManager::mostrarAfiliado(Afiliado reg){
    cout << "-----------------------------------------" << endl;
    reg.Mostrar();
}

void AfiliadoManager::BuscarPorDNI(){
    string dniBuscado;
    cout << "--- BUSCAR AFILIADO POR DNI ---" << endl << endl;
    cout << "Ingrese el DNI a buscar: ";
    cin >> dniBuscado;

    int pos = _repoAfiliado.buscar(dniBuscado);

    if (pos == -1){
        cout << "El DNI no existe en el sistema" << endl;
        return;
    }

    Afiliado reg = _repoAfiliado.leer(pos);
    system("cls");
    cout << "\t\tAFILIADO ENCONTRADO" << endl;
    mostrarAfiliado(reg);
}

void AfiliadoManager::Modificar(){
    string dniBuscado;
    int modifica;

    cout << "Ingrese el DNI del afiliado a modificar: ";
    cin >> dniBuscado;

    int pos = _repoAfiliado.buscar(dniBuscado);

    if (pos == -1){
        cout << "El DNI no existe en el sistema" << endl;
        return;
    }

    Afiliado reg = _repoAfiliado.leer(pos);
    cout << "AFILIADO A MODIFICAR: " << endl;
    mostrarAfiliado(reg);

    cout << "--------------------------------" << endl;
    cout << "Esta seguro que quiere modificar este afiliado? 1-Si 0-No: ";
    cin >> modifica;

    if (modifica == 1){
        system("cls");
        cout << "--- NUEVOS DATOS DEL AFILIADO ---" << endl;
        int nroFijo = reg.getNroDeAfiliado();
        reg.Cargar(nroFijo);

        if (_repoAfiliado.modificar(reg, pos)){
            cout << "Guardado exitosamente!" << endl;
        } else {
            cout << "No se pudo guardar el cambio." << endl;
        }
    } else {
        cout << "Operacion cancelada." << endl;
    }
}

void AfiliadoManager::Eliminar() {
    string dniBuscado;
    int elimina;

    cout << "--- BAJA LOGICA DE AFILIADO ---" << endl << endl;
    cout << "Ingrese el DNI del afiliado a dar de baja: ";
    cin >> dniBuscado;

    int pos = _repoAfiliado.buscar(dniBuscado);

    if (pos == -1) {
        cout << "No se encontro ningun afiliado con el DNI ingresado" << endl;
        return;
    }

    Afiliado obj = _repoAfiliado.leer(pos);
    mostrarAfiliado(obj);

    if (obj.getEstado() == false) {
        cout << "El afiliado ya esta dado de baja" << endl;
        return;
    }

    cout << "--------------------------------" << endl;
    cout << "Esta seguro que desea eliminar este afiliado? 1-Si 0-No: ";
    cin >> elimina;

    if (elimina == 1) {
        obj.setEstado(false);
        if (_repoAfiliado.modificar(obj, pos)) {
            cout << "Afiliado dado de baja correctamente" << endl;
        } else {
            cout << "No se pudo actualizar el archivo" << endl;
        }
    } else {
        cout << "El afiliado no fue dado de baja." << endl;
    }
}

void AfiliadoManager::AltaAfiliado(){
    int recupera, idRecuperar;
    int alta;

    if(ListarInactivos() == true){
        cout << endl << "Dar de alta un afiliado? 1-Si 0-No: ";
        cin >> recupera;

        if(recupera != 1){
            cout << "Operacion cancelada." << endl;
            return;
        }

        string dniRecuperar;
        cout << "Ingrese el DNI del afiliado a recuperar: ";
        cin >> dniRecuperar;

        int pos = _repoAfiliado.buscar(dniRecuperar);

        if (pos == -1){
            cout << "El DNI no pertenece a ningun registro." << endl;
            return;
        }

        Afiliado reg = _repoAfiliado.leer(pos);
        mostrarAfiliado(reg);

        if(reg.getEstado() == true){
            cout << "El afiliado ya esta de alta en el sistema." << endl;
            return;
        }

        cout << "--------------------------------" << endl;
        cout << "Esta seguro que desea dar de alta este afiliado? 1-Si 0-No: ";
        cin >> alta;

        if(alta == 1){
            reg.setEstado(true);
            if (_repoAfiliado.modificar(reg, pos)){
                cout << "Afiliado reactivado exitosamente!" << endl;
            } else {
                cout << "No se pudo actualizar el archivo." << endl;
            }
        } else {
            cout << "Operacion cancelada." << endl;
        }
    }
}
