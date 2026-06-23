#include <iostream>
#include <cstring>
#include "OrdenMedica.h"
#include "OrdenMedicaArchivo.h"
#include "OrdenMedicaManager.h"
#include "TipoDeOrdenArchivo.h"
#include "OrigenDeLaOrdenArchivo.h"

using namespace std;

void OrdenMedicaManager::menu(){
    int opcion;

    do{
        system("cls");
        cout << "===== ORDENES MEDICAS =====" << endl;
        cout << "1. AGREGAR UNA ORDEN" << endl;
        cout << "2. LISTADOS" << endl;
        cout << "3. BUSCAR POR ID" << endl;
        cout << "4. MODIFICAR ORDEN MEDICA" << endl;
        cout << "5. ELIMINAR UNA ORDEN" << endl;
        cout << "6. REACTIVAR UNA ORDEN" << endl;
        cout << "7. CONSULTAS" << endl;
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
                menuListados();
                break;
            case 3:
                buscaPorID();
                break;
            //case 4:
                //modificar();
               // break;
            case 5:
                eliminar();
                break;
            case 6:
                reactivar();
                break;
            case 7:
                menuConsultas();
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

    if(reg.cargar() == false){
        cout << "No se cargo la orden medica." << endl;
        system("pause");
        return;
    }

    if(archivo.guardar(reg)){
        cout << "La orden medica se guardo correctamente!" << endl;
    } else {
        cout << "Error al guardar la orden" << endl;
    }
}

void OrdenMedicaManager::menuListados(){
    int opcion;

    do{
        system("cls");
        cout << "===== LISTADOS =====" << endl;
        cout << "1. LISTAR TODOS" << endl;
        cout << "2. LISTAR ACTIVOS" << endl;
        cout << "3. LISTAR INACTIVOS" << endl;
        cout << "4. LISTAR ORDENADOS POR FECHA" << endl;
        cout << "5. LISTAR ORDENADOS POR TIPO DE ORDEN" << endl;
        cout << "6. LISTAR ORDENADOS POR ORIGEN DE LA ORDEN" << endl;
        cout << "-------------------------" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                listarTodos();
                break;
            case 2:
                listarActivos();
                break;
            case 3:
                listarInactivos();
                break;
            case 4:
                listarPorFecha();
                break;
            case 5:
                listarPorTipoOrden();
               break;
            case 6:
               listarPorOrigen();
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

void OrdenMedicaManager::listarPorFecha(){
    OrdenMedicaArchivo archivo;

    int cantidad = archivo.contarRegistros();

    if(cantidad == 0){
        cout << "No hay ordenes cargadas." << endl;
        system("pause");
        return;
    }

    OrdenMedica *vec = new OrdenMedica[cantidad];

    for(int i = 0; i < cantidad; i++){
        vec[i] = archivo.leer(i);
    }

    for(int i = 0; i < cantidad - 1; i++){
        for(int j = i + 1; j < cantidad; j++){

            Fecha fechaI = vec[i].getFechaOrden();
            Fecha fechaJ = vec[j].getFechaOrden();

            if(fechaJ.getAnio() < fechaI.getAnio() ||
              (fechaJ.getAnio() == fechaI.getAnio() &&
               fechaJ.getMes() < fechaI.getMes()) ||
              (fechaJ.getAnio() == fechaI.getAnio() &&
               fechaJ.getMes() == fechaI.getMes() &&
               fechaJ.getDia() < fechaI.getDia())){

                OrdenMedica aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }

    for(int i = 0; i < cantidad; i++){
        if(vec[i].getEstado()){
            vec[i].mostrar();
        }
    }

    delete[] vec;

    system("pause");
}

void OrdenMedicaManager::listarPorTipoOrden(){
    OrdenMedicaArchivo archivoOrdenes;
    TipoDeOrdenArchivo archivoTipos;

    int cantidadOrdenes = archivoOrdenes.contarRegistros();
    int cantidadTipos = archivoTipos.contarRegistros();

    for(int i=0; i < cantidadTipos; i++){

        TipoDeOrden tipo;

        tipo = archivoTipos.leer(i);

        cout << endl;
        cout << "===== TIPO DE ORDEN: " << tipo.getIdTipoOrden() << " - " << tipo.getDescripcion() << " =====" << endl;

        bool encontro = false;

        for(int j = 0; j < cantidadOrdenes; j++){

            OrdenMedica reg = archivoOrdenes.leer(j);

            if(reg.getEstado() && reg.getTipoOrden() == tipo.getIdTipoOrden()){
                reg.mostrar();
                encontro = true;
            }
        }

        if(!encontro){
            cout << "No hay ordenes de este tipo." << endl;
        }
    }

    system("pause");
}

void OrdenMedicaManager::listarPorOrigen(){
    OrdenMedicaArchivo archivoOrdenes;
    OrigenDeLaOrdenArchivo archivoOrigen;

    int cantidadOrdenes = archivoOrdenes.contarRegistros();
    int cantidadOrigen = archivoOrigen.contarRegistros();


    for(int i=0; i < cantidadOrigen; i++){
        OrigenDeLaOrden origen;

        origen = archivoOrigen.leer(i);

        cout << endl;
        cout << "===== ORIGEN DE LA ORDEN MEDICA: " << origen.getIdOrigen() << " - " << origen.getDescripcion() << " =====" << endl;

        bool encontro = false;

        for(int j = 0; j < cantidadOrdenes; j++){

            OrdenMedica reg;
            reg = archivoOrdenes.leer(j);

            if(reg.getEstado() && reg.getOrigen() == origen.getIdOrigen()){
                reg.mostrar();
                encontro = true;
            }
        }

        if(!encontro){
            cout << "No hay ordenes de este con ese origen." << endl;
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

void OrdenMedicaManager::menuConsultas(){
    int opcion;

    do{
        system("cls");
        cout << "===== CONSULTAS =====" << endl;
        cout << "1. CONSULTA POR PACIENTE" << endl;
        cout << "2. CONSULTA POR MEDICO" << endl;
        cout << "3. CONSULTA ENTRE FECHAS" << endl;
        cout << "4. CONSULTA POR TIPO DE ORDEN" << endl;
        cout << "-------------------------" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
            case 1:
                consultarPorDni();
                break;
            case 2:
                consultarPorMedico();
                break;
            case 3:
                consultarPorFecha();
                break;
           case 4:
                consultarPorTipoOrden();
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

void OrdenMedicaManager::consultarPorDni(){
    OrdenMedicaArchivo archivo;

    string dni;
    bool encontro = false;

    cout << "Ingrese el dni del paciente: " << endl;
    cin >> dni;

    int cantidad = archivo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado() && reg.getDniPaciente() == dni){
            reg.mostrar();
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontro ninguna orden con ese dni" << endl;
    }

    system("pause");
}

void OrdenMedicaManager::consultarPorMedico(){
    OrdenMedicaArchivo archivo;

    int matricula;
    bool encontro = false;

    cout << "Ingrese la matricula del medico: " << endl;
    cin >> matricula;

    int cantidad = archivo.contarRegistros();

    for(int i=0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado() && reg.getMatriculaMedico() == matricula){
            reg.mostrar();
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontro ninguna orden con la matricula del medico" << endl;
    }

    system("pause");
}

void OrdenMedicaManager::consultarPorFecha(){
    OrdenMedicaArchivo archivo;
    Fecha fecha;
    bool encontro = false;

    cout << "Ingrese la fecha que desea consultar: " << endl;
    fecha.Cargar();

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado() &&
           reg.getFechaOrden().getDia() == fecha.getDia() &&
           reg.getFechaOrden().getMes() == fecha.getMes() &&
           reg.getFechaOrden().getAnio() == fecha.getAnio()){
            reg.mostrar();
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontro ninguna orden con esa fecha." << endl;
    }

    system("pause");
}

void OrdenMedicaManager::consultarPorTipoOrden(){
    OrdenMedicaArchivo archivo;
    TipoDeOrdenArchivo archivoTipos;

    int tipo;
    bool encontro = false;

    cout << "Ingrese el id del tipo de orden que desea buscar: " << endl;
    cin >> tipo;

    int cantidad = archivo.contarRegistros();

    TipoDeOrden regTipo = archivoTipos.leer(tipo - 1);

    cout << "===== TIPO DE ORDEN: " << regTipo.getIdTipoOrden() << " - " << regTipo.getDescripcion() << " =====" << endl;

    for(int i=0; i < cantidad; i++){
        OrdenMedica reg;

        reg = archivo.leer(i);

        if(reg.getEstado() && reg.getTipoOrden() == tipo){
            reg.mostrar();
            encontro = true;
        }
    }

    if(!encontro){
        cout << "No se encontro ninguna orden con ese tipo" << endl;
    }

    system("pause");
}

