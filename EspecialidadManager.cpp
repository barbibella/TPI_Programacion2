#include <iostream>
#include <cstring>
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include "EspecialidadManager.h"
#include "auxiliares.h"

using namespace std;
//CONSTRUCTOR //--- MAI ---
EspecialidadManager::EspecialidadManager()
: _repoEspecialidad(){
}

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
        cout << "\nNo se encuentran registros en el sistema...\n";
    }
}


void  EspecialidadManager::mostrarEspecialidad(const Especialidad &reg){
    cout << "ID #" << reg.getIdEspecialidad() << endl;
    cout << "Nombre Especialidad: " << reg.getNombreEspecialidad() << endl;
    cout << "Descripcion: " << reg.getDescripcionEspecialidad() << endl;
    cout << "Formacion: " << reg.getFormacion() << endl;

}

///Eliminar Especialidad
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
