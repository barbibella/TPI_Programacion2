#include <iostream>
#include <cstring>
#include <string>
#include "ObraSocial.h"
#include "Afiliado.h"
#include "AfiliadoArchivo.h"
#include "AfiliadoManager.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
#include "Fecha.h"
 ///nekiscfnskcfsndocfnsncfsodnsdknf
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
        cout << "5. LISTADOS ORDENADOS..." << endl;
        cout << "6. BUSCAR POR DNI" << endl;
        cout << "7. BUSCAR POR APELLIDO" << endl;
        cout << "8. MODIFICAR AFILIADO" << endl;
        cout << "9. ELIMINAR (BAJA LOGICA)" << endl;
        cout << "10. ALTA DE AFILIADO (RECUPERAR)" << endl;
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
            case 5: MenuListados(); break;
            case 6: BuscarPorDNI(); break;
            case 7: BuscarPorApellido(); break;
            case 8: Modificar(); break;
            case 9: Eliminar(); break;
            case 10: AltaAfiliado(); break;
            case 0: break;
            default: cout << "OPCION INCORRECTA" << endl; system("pause"); break;
        }
        if (opcion != 0 && opcion != 5 && opcion >= 1 && opcion <= 10) {
            system("pause");
        }
    }while(opcion != 0);
}

void AfiliadoManager::MenuListados(){
    int opcion;

    do{
        system("cls");
        cout << "--- SUBMENU DE LISTADOS ORDENADOS ---" << endl;
        cout << "1. ORDENADOS POR APELLIDO" << endl;
        cout << "2. ORDENADOS POR DNI" << endl;
        cout << "3. ORDENADOS POR OBRA SOCIAL" << endl;
        cout << "-------------------------------------" << endl;
        cout << "0. VOLVER AL MENU DE AFILIADOS" << endl;
        cout << "OPCION: ";
        cin >> opcion;

        system("cls");

        switch(opcion){
            case 1: ListarOrdenadoPorApellido(); break;
            case 2: ListarOrdenadoPorDNI(); break;
            case 3: ListarOrdenadoPorObraSocial(); break;
            case 0: break;
            default:
                cout << "OPCION INCORRECTA" << endl;
                break;
        }

        if(opcion != 0 && opcion >= 1 && opcion <= 3){
            system("pause");
        }

    }while(opcion != 0);
}

Afiliado AfiliadoManager::crearAfiliado() {
    string nombre, apellido, dni, telefono, mail;
    int idObraSocial, nuevoNumero;
    Fecha fNac;

    int cantidad = _repoAfiliado.contarRegistros();
    nuevoNumero = 1000 + cantidad;

    cout << "--- NUEVA ALTA DE AFILIADO ---" << endl << endl;
    cout << "Ingrese Nombre: ";
    cin >> nombre;
     while (nombre.size() >= 30 || nombre.size() < 2){
        cout << "Error: El nombre debe tener entre 2 y 29 caracteres. Ingrese nuevamente: ";
        cin >> nombre;}
    cout << "Ingrese Apellido: ";
    cin >> apellido;
    while (apellido.size() >= 30 || apellido.size() < 2) {
        cout << "Error: El apellido debe tener entre 2 and 29 caracteres. Ingrese nuevamente: ";
        cin >> apellido;}
    cout << "Ingrese DNI: ";
    cin >> dni;
    while (dni.size() >= 15 || dni.size() < 7) {
        cout << "Error: DNI invalido (debe tener entre 7 y 14 caracteres). Ingrese nuevamente: ";
        cin >> dni;}
    cout << "SU NUMERO DE AFILIADO ES: " << nuevoNumero << endl;
    cout << "Ingrese Telefono: ";
    cin >> telefono;
    while (telefono.size() >= 20 || telefono.size() < 4) {
        cout << "Error: Telefono fuera de rango. Ingrese nuevamente: ";
        cin >> telefono;}

    ObraSocialArchivo archObraSocial;
    ObraSocialManager managerObraSocial;

   bool idValido = false;
    while(!idValido) {
        cout << "Ingrese ID de Obra Social (o 0 para ver codigos disponibles): ";
        cin >> idObraSocial;

        if (idObraSocial == 0) {
            system("cls");
            managerObraSocial.ListarTodas();
            system("pause");
            system("cls");

            cout << "--- NUEVA ALTA DE AFILIADO ---" << endl << endl;
            cout << "Paciente: " << apellido << ", " << nombre << " (Nro: " << nuevoNumero << ")" << endl << endl;
        }else {
            if (archObraSocial.buscar(idObraSocial) >= 0) {
                idValido = true;
            } else {
                cout << "Error: El ID ingresado no existe. Intente de nuevo." << endl;
                system("pause");
                cout << "--------------------------------------------------" << endl;
            }
        }
    }

    cout << "MAIL: ";
    cin >> mail;
        while (mail.size() <= 5 || mail.find('@') == string::npos) {
        cout << "Mail invalido (Debe tener mas de 5 letras y contener '@'). Ingrese nuevamente: ";
        cin >> mail;}
    fNac.Cargar();
    Afiliado nuevoAfiliado(nuevoNumero, idObraSocial, mail, fNac, nombre, apellido, dni, telefono, true);
    ///es un constructor para pasarle los datos de forma nativa a la clase padre Persona

    return nuevoAfiliado;
}

void AfiliadoManager::Agregar(){
    Afiliado obj = crearAfiliado();
    if(_repoAfiliado.guardar(obj)){///se guarda el afi. en el disco rigido
        cout << "Afiliado guardado exitosamente." << endl;
    }else{
        cout << "Error al guardar en el archivo" << endl;
    }
}

void AfiliadoManager::ListarTodos(){
    cout << "--- LISTA GENERAL DE AFILIADOS ---" << endl << endl;
    int cantidad = _repoAfiliado.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        Afiliado obj = _repoAfiliado.leer(i);
        obj.Mostrar();
    }
}

void AfiliadoManager::ListarActivos(){
    cout << "--- AFILIADOS ACTIVOS ---" << endl << endl;
    int cantidad = _repoAfiliado.contarRegistros();
    for (int i = 0; i < cantidad; i++){
        Afiliado obj = _repoAfiliado.leer(i);
        if(obj.getEstado() == true){///filtro condicinal
           obj.Mostrar();
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
    cout << "AFILIADO ENCONTRADO" << endl;
    mostrarAfiliado(reg);
}

void AfiliadoManager::BuscarPorApellido(){
   string apellidoBuscado;
    bool encontro = false;

    cout << "--- BUSCAR AFILIADO POR APELLIDO ---" << endl << endl;
    cout << "Ingrese el apellido a buscar: ";
    cin >> apellidoBuscado;

    int cantidad = _repoAfiliado.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        Afiliado obj = _repoAfiliado.leer(i);

        if(obj.getApellido() == apellidoBuscado) {
            mostrarAfiliado(obj);
            encontro = true;
        }
    }
    if(!encontro){
        cout << "No se encontraron pacientes con el apellido: " << apellidoBuscado << endl;
    }
    cout << endl;
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
            if (_repoAfiliado.modificar(reg, pos)){///se guarda en su pos original
                cout << "Afiliado reactivado exitosamente!" << endl;
            } else {
                cout << "No se pudo actualizar el archivo." << endl;
            }
        } else {
            cout << "Operacion cancelada." << endl;
        }
    }
}

void AfiliadoManager::ListarOrdenadoPorApellido() {
    int cantidad = _repoAfiliado.contarRegistros();
    if (cantidad == 0) {
        cout << "No hay afiliados registrados." << endl;
        return;
    }

    /// 1. se crea el vector dinamico en RAM y pasamos los datos del archivo
    Afiliado* vAfiliados = new Afiliado[cantidad];
    _repoAfiliado.leerTodos(vAfiliados, cantidad);

    /// 2. algoritmo de Burbujeo por Apellido
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (vAfiliados[j].getApellido() > vAfiliados[j + 1].getApellido()) {
                Afiliado aux = vAfiliados[j];
                vAfiliados[j] = vAfiliados[j + 1];
                vAfiliados[j + 1] = aux;
            }
        }
    }

    /// 3.  se lista el vector ya ordenado
    cout << "--- AFILIADOS ORDENADOS POR APELLIDO ---" << endl << endl;
    for (int i = 0; i < cantidad; i++) {
        mostrarAfiliado(vAfiliados[i]);
    }
    delete[] vAfiliados;
}

void AfiliadoManager::ListarOrdenadoPorDNI() {
    int cantidad = _repoAfiliado.contarRegistros();
    if (cantidad == 0) {
        cout << "No hay afiliados registrados." << endl;
        return;
    }

    Afiliado* vAfiliados = new Afiliado[cantidad];
    _repoAfiliado.leerTodos(vAfiliados, cantidad);

    /// burbujeo por DNI (Como es string, compara caracter por caracter correctamente)
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (vAfiliados[j].getDni() > vAfiliados[j + 1].getDni()) {
                Afiliado aux = vAfiliados[j];
                vAfiliados[j] = vAfiliados[j + 1];
                vAfiliados[j + 1] = aux;
            }
        }
    }

    cout << "--- AFILIADOS ORDENADOS POR DNI ---" << endl << endl;
    for (int i = 0; i < cantidad; i++) {
        mostrarAfiliado(vAfiliados[i]);
    }

    delete[] vAfiliados;
}

void AfiliadoManager::ListarOrdenadoPorObraSocial() {
    int cantidad = _repoAfiliado.contarRegistros();
    if (cantidad == 0) {
        cout << "No hay afiliados registrados." << endl;
        return;
    }

    Afiliado* vAfiliados = new Afiliado[cantidad];
    _repoAfiliado.leerTodos(vAfiliados, cantidad);

    ///burbujeo por ID Obra Social (Comparacion de enteros)
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (vAfiliados[j].getIDObraSocial() > vAfiliados[j + 1].getIDObraSocial()) {
                Afiliado aux = vAfiliados[j];
                vAfiliados[j] = vAfiliados[j + 1];
                vAfiliados[j + 1] = aux;
            }
        }
    }

    cout << "--- AFILIADOS ORDENADOS POR ID OBRA SOCIAL ---" << endl << endl;
    for (int i = 0; i < cantidad; i++) {
        mostrarAfiliado(vAfiliados[i]);
    }

    delete[] vAfiliados;
}
