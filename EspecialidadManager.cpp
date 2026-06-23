#include <iostream>
#include <cstring>
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include "EspecialidadManager.h"
#include "auxiliares.h"

//--- MAI ---

using namespace std;
//CONSTRUCTOR
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

    return Especialidad (idEspecialidad, idFormacion, nombreEspecialidad, descripcionEspecialidad);
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


void mostrarEspecialidad(const Especialidad &reg){
    cout << "ID #" << reg.getEspecialidad() << endl;
    cout << "Nombre Especialidad: " << reg.getNombreEspecialidad() << endl;
    cout << "Descripcion: " << reg.getDescripcionEspecialidad() << endl;
    cout << "Formacion: " << reg.getFormacion() << endl;

}
