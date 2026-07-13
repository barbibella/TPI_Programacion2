#include <iostream>
#include <cstring>
#include "Medico.h"
#include "MedicoArchivo.h"
#include "MedicoManager.h"
#include "auxiliares.h"
#include "EspecialidadManager.h"

//--- MAI ---
using namespace std;
///constructor
MedicoManager::MedicoManager()
: _repoMedico (){}

// Manager Métodos

Medico MedicoManager::crearMedico(){
    Medico reg;
    reg = cargar();
    return reg;

    }

Medico MedicoManager::cargar(){
    int matricula, especialidad;
    string nombre, apellido, dni, telefono;
    bool existe;
    nombre = cargarCadenaValidada("Ingrese nombre: ", 29);
    apellido = cargarCadenaValidada("Ingrese apellido: ", 29);
    dni = cargarCadenaValidada("Ingrese DNI: ", 14);
    telefono = cargarCadenaValidada("Ingrese numero de telefono: ", 19);

    do{
        matricula = cargarEnteroValidado("Ingrese matricula: ",1);
        existe = _repoMedico.existeMatricula(matricula);
        if (existe){
            cout <<"Esa matricula ya se encuentra registrada"<<endl;
        }
    }while (existe);

    especialidad = cargarEnteroValidado("1 - Medicina clinica\n2 - Pediatria\n3 - Traumatologia\n4 - Oftalmologia\n5 - Cirugia\n6 - Neumonologia\n7 - Cardiologia\n8 - Neurologia\n9 - Gastroenterologia\n10- Ginecologia", 0, 11);
    return Medico(matricula, especialidad, nombre, apellido, dni, telefono, 1);
}

// MAI - guardarMedico es la funcion agregar O CREAR.
void MedicoManager::guardarMedico(){
    Medico reg = crearMedico();
    if (_repoMedico.crear(reg)){
        cout << "Se guardo exitosamente." << endl;
    }
    else {
        cout << "No se pudo guardar." << endl;
    }
}

// MAI - listar "todos"
void MedicoManager::listarMedicos(){
    int cantidad = _repoMedico.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++){
        Medico m= _repoMedico.leer(i); // metodo para mostrar medico. Asignar el registro de la 1er pos a el obj medico y desp lo muestra
        mostrarMedico(m);
    }
}


// MAI - listar Activos
void MedicoManager::listarMActivos(){
    int cantidad = _repoMedico.getCantidadRegistros();

    for (int i = 0; i < cantidad; i++){
        Medico m = _repoMedico.leer(i);
        if(m.getEstado() == true){
           mostrarMedico(m);
        }
    }
}

//MAI - listar Inactivos
bool MedicoManager::listarInactivos(){ ////agregue esta funcion

    int cantidad = _repoMedico.getCantidadRegistros();
    bool hayEliminados = false;

    cout <<"------Medicos dados de baja ------" <<endl;
    for (int i = 0; i < cantidad; i++){
        Medico m = _repoMedico.leer(i);
        if(m.getEstado() == false){
           cout << "Matricula #" <<m.getMatricula() <<endl;
           cout << "Nombre: " << m.getNombre() << endl;
		   cout << "Apellido: " << m.getApellido() << endl;
		   cout << "DNI: " << m.getDni() << endl;

		   cout<<"******************************"<<endl;

           hayEliminados = true;
        }
    }
    if(!hayEliminados){
        cout <<"NO HAY MEDICOS DADOS DE BAJA" <<endl;
    }
    return hayEliminados;
}

void MedicoManager::mostrarMedico(const Medico &reg){
        cout << "-----------------------------------------" << endl;
		cout << "Matricula" << reg.getMatricula() << endl;
		cout << "Nombre: " << reg.getNombre() << endl;
		cout << "Apellido: " << reg.getApellido() << endl;
		cout << "DNI: " << reg.getDni() << endl;
		cout << "Telefono: " << reg.getTelefono() << endl;
		cout << "Estado: " << reg.getEstado() << endl;

}

void MedicoManager::modificarMedico(){
    int matricula, opcion, busqueda, pos;
    string dni;
    bool modifica;

    do {
        cout << "Como busca el medico? 1- Matricula 2- Dni ";
        cin >> busqueda;
    } while (busqueda == 1 && busqueda == 2);

    if (busqueda == 1){
        cout << "Ingrese matricula del medico a modificar: ";
        cin >> matricula;
        pos = _repoMedico.buscarMatricula(matricula);
    }
    else if (busqueda == 2){
        cout << "Ingrese DNI del medico a modificar: ";
        cin >> dni;
        pos = _repoMedico.buscarDni(dni);
    }

    if (pos == -1){
        cout << "Dato no valido" << endl;
        return;
    }

    Medico reg = _repoMedico.leer(pos);
     //se fija si el medico está inactivo, si es así, no permite modificarlo.
    if (reg.getEstado() == false){
        cout<<"No se puede modificar un medico inactivo"<< endl;
        return;
    }

    cout << "MEDICO A MODIFICAR: " << endl;

    mostrarMedico(reg);

    cout << "--------------------------------" << endl;

    cout << "Esta seguro que quiere cambiar este medico? 1-Si 0-No" << endl;
    cin >> modifica;

    if (modifica != 1){
        modifica = false;
    }

    if (!modifica){
        cout << "No se modifico el medico" << endl;
        return;
    }

    system("cls");

    int opcionModificar = mostrarMenuModificar();
    EjecutarOpcion(opcionModificar, reg);

    if (_repoMedico.actualizar(pos, reg)){
            cout << "Guardado exitosamente!" << endl;
        }
        else {
            cout << "No se pudo guardar!" << endl;
        }

}

int MedicoManager::mostrarMenuModificar(){
    int opcion;
    do {
    cout << "-------------------------------" << endl;
    cout << "Seleccione opcion a modificar " << endl;
   		cout << "1 - Matricula" << endl;
		cout << "2 - Nombre " << endl;
		cout << "3 - Apellido "  << endl;
		cout << "4 - DNI " << endl;
		cout << "5 - Telefono " << endl;
		cout << "6 - Todo " << endl;
		cout << "Ingrese una opcion: " ;
    cin >> opcion;
    } while (opcion > 0 ||  opcion < 7);
    return opcion;
}

void MedicoManager::EjecutarOpcion(int opcion,Medico &reg){
    do{

    switch(opcion){
    case 1:
        modificarMatricula(reg);
        break;
    case 2:
        modificarNombre(reg);
        break;
    case 3:
        modificarApellido(reg);
        break;
    case 4:
        modificarDni(reg);
        break;
    case 5:
        modificarTelefono(reg);
        break;
    case 6:
        modificarTodo(reg);
        break;
    case 0:
        cout << "Saliendo..." << endl;
        break;
    }
    } while (opcion != 0);
}
void MedicoManager::eliminarMedico(){   // MAI - DAR DE BAJA LOGICA

    int matricula;
    bool elimina;

    cout << "Ingrese matricula del medico a eliminar: ";
    cin >> matricula;

    int pos = _repoMedico.buscarMatricula(matricula);

    if (pos == -1){
        cout << "La matricula no existe en el sistema" << endl;
        return;
    }

    Medico reg = _repoMedico.leer(pos);

    mostrarMedico(reg);

    cout << "--------------------------------" << endl;

    if(reg.getEstado() == false){
        cout << "El medico ya esta dado de baja" << endl;
        return;
    }

    cout << "Esta seguro que desea eliminar este medico? 1-Si 0-No" << endl;
    cin >> elimina;

    if (elimina != 1){
        elimina = false;
    }

    if(!elimina){
        cout <<"El medico no fue dado de baja! "<<endl;
        return;
    }

    reg.setEstado(false);  ///estado 2 es inactivo

    if (_repoMedico.actualizar(pos, reg)){
        cout << "actualizado exitosamente!" << endl;
    }
    else {
        cout << "No se pudo actualizar!" << endl;
    }
}

void MedicoManager::altaMedico(){  //=MAI= ALTA LOGICA

    int id,recupera;
    bool alta;


    if(listarInactivos()==true){
    cout << "Ingrese matricula a recuperar: ";
    cin >> id;

    cout << "Dar de alta el medico ? 1-Si 0-No" << endl;
    cin >> recupera;

        if(!recupera){
        cout <<"El medico no fue recuperado! "<<endl;
        return;
        }

    int pos = _repoMedico.buscarMatricula(id);

    if (pos == -1){
        cout << "La matricula no existe en el sistema" << endl;
        return;
    }

    Medico reg = _repoMedico.leer(pos);

    mostrarMedico(reg);

    cout << "--------------------------------" << endl;

    if(reg.getEstado() == true){
        cout << "El medico ya esta dado de alta" << endl;
        return;
    }

    cout << "Esta seguro que desea dar el alta a este medico? 1-Si 0-No" << endl;
    cin >> alta;

    if(!alta){
        cout <<"El medico no fue dado de alta! "<<endl;
        return;
    }

    reg.setEstado(true);  ///estado 1 es activo

    if (_repoMedico.actualizar(pos, reg)){
        cout << "actualizado exitosamente!" << endl;
    }
    else {
        cout << "No se pudo actualizar!" << endl;
    }
    }
}

void MedicoManager::informacionMedico(){
    int matricula, opcion, busqueda, pos;
    string dni;
    bool modifica;

    do {
        cout << "Como busca el medico? 1- Matricula 2- Dni ";
        cin >> busqueda;
    } while (busqueda == 1 && busqueda == 2);

    if (busqueda == 1){
        cout << "Ingrese matricula a mostrar: ";
        cin >> matricula;
        pos = _repoMedico.buscarMatricula(matricula);
    }
    else if (busqueda == 2){
        cout << "Ingrese DNI a mostrar: ";
        cin >> dni;
        pos = _repoMedico.buscarDni(dni);
    }

    if (pos == -1){
        cout << "El registro no existe en el sistema" << endl;
        return;
    }

    Medico reg = _repoMedico.leer(pos);

    system("cls");

    cout << "\t\tMEDICO " << endl;
    mostrarMedico(reg);

}

