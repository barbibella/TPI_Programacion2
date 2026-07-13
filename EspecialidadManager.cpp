#include <iostream>
#include <cstring>
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include "EspecialidadManager.h"
#include "auxiliares.h"

using namespace std;
///CONSTRUCTOR  ESPECIALIDAD //--- MAI ---

EspecialidadManager::EspecialidadManager()
: _repoEspecialidad(){
}
/** =====  A RESOLVER  ======
    Métodos:
        Listar activos
        Listar inactivos
        alta lógica
        En "MODIFICAR": que NO te deje modificar si está dado de baja.
        */

//Agrega una nueva especialidad, la crea y la guarda.
Especialidad  EspecialidadManager::crearEspecialidad(){
    Especialidad regEspecialidad = cargar();
    return regEspecialidad;
}

Especialidad EspecialidadManager::cargar(){
    int idFormacion, idEspecialidad = _repoEspecialidad.getNuevoId();
    string nombreEspecialidad, descripcionEspecialidad;
    cout << "El ID Especialidad es: " << idEspecialidad << endl;

    nombreEspecialidad = cargarCadenaValidada( "Ingrese nombre de la Especialidad: ", 25);

    descripcionEspecialidad = cargarCadenaValidada( "Ingrese descripcion de la Especialidad: ", 50);

    idFormacion = cargarEnteroValidado("Ingrese el tipo de Formacion: 1- Sin Formacion, 2 - Residencia, 3- Concurrencia", 0, 4);

    return Especialidad (idEspecialidad, idFormacion, nombreEspecialidad, descripcionEspecialidad,1);
}

void EspecialidadManager::guardarEspecialidad(){
   Especialidad _regEspecialidad = crearEspecialidad();
    if (_repoEspecialidad.crear(_regEspecialidad)){}
    else {
        cout << "No se pudo guardar" << endl;
    }
}

//Chequea si hay registros, consulta la cant de rgistros q hay asignandolos a una cant
// y dsp los lista por indice i en un ciclo for
void EspecialidadManager::listarEspecialidad(){
     Especialidad _regEspecialidad;

    int _cantidad = _repoEspecialidad.getCantidadRegistros();
    if (_cantidad > 0){

            for (int i = 0; i < _cantidad; i++){
            _regEspecialidad = _repoEspecialidad.leer(i);
            mostrarEspecialidad(_regEspecialidad);

        }
    }
    else {
        cout << "\nNo se encuentran registros en el sistema.\n";
    }
}

///Busca la informacion de 1 especialidad y la muestra
void  EspecialidadManager::mostrarEspecialidad(const Especialidad &reg){
    cout << "ID #" << reg.getIdEspecialidad() << endl;
    cout << "Nombre Especialidad: " << reg.getNombreEspecialidad() << endl;
    cout << "Descripcion: " << reg.getDescripcionEspecialidad() << endl;
    cout << "Formacion: " << reg.getFormacion() << endl;

}

///Eliminar Especialidad - Es la baja lógica de Especialidad.
void EspecialidadManager::eliminarEspecialidad(){
    int idEspecialidad = cargarEnteroValidado("Ingrese el id a eliminar: ", 0, _repoEspecialidad.getCantidadRegistros());

    int _pos = _repoEspecialidad.buscarIdEspecialidad(idEspecialidad);

    if (_pos == -1){
        cout << "El id no existe en el sistema" << endl;
        return;
    }

    Especialidad _regEspecialidad = _repoEspecialidad.leer(_pos);

    mostrarEspecialidad(_regEspecialidad);

    cout << "--------------------------------" << endl;

    if(_regEspecialidad.getEstado() == "Inactivo"){
        cout << "La Especialidad ya esta dada de baja" << endl;
        return;
    }

    bool  _elimina = cargarEnteroValidado("Esta seguro que desea eliminar esta matricula? 1-Si 0-No", 0, 1);

    if (_elimina != 1){
        _elimina = false;
    }

    if(!_elimina){
        cout <<"La matricula no fue dada de baja! "<<endl;
        return;
    }

    _regEspecialidad.setEstado(2);  ///estado 2 es inactivo

    if (_repoEspecialidad.actualizar(_pos, _regEspecialidad)){
        cout << "Actualizado exitosamente!" << endl;
    }
    else {
        cout << "No se pudo actualizar!" << endl;
    }
}

/// ALTA LOGICA ESPECIALIDAD
void EspecialidadManager::altaEspecialidad(){
    int idEspecialidad = cargarEnteroValidado("Ingrese el id a activar: ", 0, _repoEspecialidad.getCantidadRegistros());

    int _pos = _repoEspecialidad.buscarIdEspecialidad(idEspecialidad);
    //pos es posicion = busca el ID que se necesita, en q posicion esta
    if (_pos == -1){  ///lo busca y si no lo encuentra, devuelve el mensaje de no existencia.
        cout << "El id no existe en el sistema" << endl;
        return;
    }

    Especialidad _regEspecialidad = _repoEspecialidad.leer(_pos); //busca la especialidad pedida

    mostrarEspecialidad(_regEspecialidad); //la muestra

    cout << "--------------------------------" << endl;

    if(_regEspecialidad.getEstado() == true ){  //es para que no pueda activar una esp que ya esta activa
        cout << "La Especialidad ya esta dada de alta." << endl;
        return;
    }

    bool  _activa = cargarEnteroValidado("Esta seguro que desea activar esta matricula? 1-Si 0-No", 0, 1);

    if (_activa != 1){ //si el input fue distinto de 1, la variable queda false.
        _activa = false;
    }

    if(!_activa){ //si activa es falso, devuelve el mensaje
        cout <<"La matricula no fue dada de alta! "<<endl;
        return;
    }

    _regEspecialidad.setEstado(true);

    if (_repoEspecialidad.actualizar(_pos, _regEspecialidad)){ //actualizar necesita la posicion dnd se encuentra la especialidad
        cout << "Actualizado exitosamente!" << endl;           //y un registro ya actualizado
    }
    else {
        cout << "No se pudo actualizar!" << endl;
    }
}

//  void listarEspActivos();
///LISTAR ESPECIALIDADES INACTIVAS
bool EspecialidadManager::listarEspInactivos(){
   int _cantidad = _repoEspecialidad.getCantidadRegistros();
    bool _hayEliminados = false;

    cout <<"------Especialidades dadas de baja ------" <<endl;
    for (int i = 0; i < _cantidad; i++){
        Especialidad _regEspecialidad = _repoEspecialidad.leer(i);
        if(_regEspecialidad.getEstado() == false){
           cout << "ID #" <<_regEspecialidad.getIdEspecialidad() <<endl;
           cout << "Nombre de Especialidad: " << _regEspecialidad.getNombreEspecialidad() << endl;
		   cout << "Descripcion: " << _regEspecialidad.getDescripcionEspecialidad() << endl;
           cout << "Formacion: " << _regEspecialidad.getFormacion() << endl;
		   cout<<"******************************"<<endl;

           _hayEliminados = true;
        }
    }
    if(!_hayEliminados){
        cout <<"NO HAY ESPECIALIDADES DADAS DE BAJA" <<endl;
    }
    return _hayEliminados;
}

///LISTAR ESPECIALIDADES ACTIVAS
void EspecialidadManager::listarEspActivos(){
    if (_repoEspecialidad.getCantidadRegistros() > 0){
        int _cantidad = _repoEspecialidad.getCantidadRegistros();

        for (int i = 0; i < _cantidad; i++){
            //va al archivo, lo lee y asigna un objeto a la variable
            //pregunta si el estado es activo y lo muestra
           Especialidad _regEspecialidad = _repoEspecialidad.leer(i);
            if(_regEspecialidad.getEstado() == true){
            mostrarEspecialidad(_regEspecialidad);
                }
            }
        }
    else {
        cout << "\nNo hay registros en el sistema." << endl;
    }
}

///MODIFICAR ESPECIALIDAD
//void modificarEspecialidad();
void EspecialidadManager::modificarEspecialidad(){
    int idEspecialidad, opcion, busqueda, pos;
    string dni;
    bool modifica;

    listarEspActivos();
    cout << "\nIngrese el ID de la especialidad a modificar: ";
    cin >> idEspecialidad;
     pos = _repoEspecialidad.buscarIdEspecialidad(idEspecialidad);

        if (pos == -1){
        cout << "Dato no valido" << endl;
        return;
    }

    Especialidad reg = _repoEspecialidad.leer(pos);
    //se fija si la especialidad está inactiva, si es así, no permite modificarla.
    if (reg.getEstado == false){
        cout<<"No se puede modificar una especialidad inactiva"<< endl;
        return;
    }

    cout << "ESPECIALIDAD A MODIFICAR: " << endl;

    mostrarEspecialidad(reg);

    cout << "--------------------------------" << endl;

    cout << "Esta seguro que quiere cambiar esta especialidad? 1-Si 0-No" << endl;
    cin >> modifica;

    if (modifica != 1){
        modifica = false;
    }

    if (!modifica){
        cout << "No se modifico la especialidad" << endl;
        return;
    }

    system("cls");

    int opcionModificar = mostrarMenuModificar();
    EjecutarOpcion(opcionModificar, reg);

    if (_repoEspecialidad.actualizar(pos, reg)){
            cout << "Guardado exitosamente!" << endl;
        }
        else {
            cout << "No se pudo guardar!" << endl;
        }

}

int EspecialidadManager::mostrarMenuModificar(){
    int opcion;
    do {
    cout << "-------------------------------" << endl;
    cout << "Seleccione opcion a modificar: " << endl;
   		cout << "1 - Nombre Especialidad" << endl;
		cout << "2 - Descripcion Especialidad " << endl;
		cout << "3 - Formacion "  << endl;
		cout << "4 - Todo " << endl;
		cout << "Ingrese una opcion: " ;
    cin >> opcion;
    } while (opcion > 0 ||  opcion < 5);
    return opcion;
}

///INFORMACION ESPECIALIDAD - FALTA!!!
 //void informacionEspecialidad();

 void EspecialidadManager::informacionEspecialidad(){
    if (_repoEspecialidad.getCantidadRegistros()> 0){


        if (_pos == -1){
            cout << "Dato no valido" << endl;
            return;
        }

        _regSocio = _repoSocio.leer(_pos);

        system("cls");

        cout << "\t\tSOCIO " << endl;
        mostrarSocio(_regSocio);
    }
    else {
        cout << "\nNo se encuentran registros en el sistema..." << endl;
    }
}

