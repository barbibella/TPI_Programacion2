#include "EspecialidadModificar.h"
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include "EspecialidadManager.h"
#include "auxiliares.h"
#include <iostream>


EspecialidadModificar::EspecialidadModificar(Especialidad &reg)
: _reg(reg)
{
    setCantidadOpciones(4);
}

void EspecialidadModificar::mostrarOpciones(){
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione opcion a modificar: " << endl;
   		cout << "1 - Nombre Especialidad " << endl;
		cout << "2 - Descripcion " << endl;
		cout << "3 - Formacion "  << endl;
		cout << "4 - Todo " << endl;
		cout << "-----------------------------------------" << endl;
}



void EspecialidadModificar::ejecutarOpcion(int opcion){

    switch(opcion){
    case 1:
        modificarNombreEspecialidad(_reg);
        break;
    case 2:
        modificarDescripcion(_reg);
        break;
    case 3:
        modificarFormacion(_reg);
        break;
    case 4:
        modificarTodo(_reg);
        break;
    case 0:
        cout << "Saliendo..." << endl;
        break;
    }

}

 ///Modificaciones Especialidad
void modificarNombreEspecialidad(Especialidad &reg){
    string nombre;

    nombre = cargarCadenaValidada("Ingrese Nombre: ", 30);

    reg.setNombreEspecialidad(nombre);
}

void modificarDescripcion(Especialidad &reg){
    string descripcion;

    descripcion = cargarCadenaValidada("Ingrese Descripcion: ", 150);

    reg.setDescripcionEspecialidad(descripcion);
}

void modificarFormacion(Especialidad &reg){
    int idFormacion;

    idFormacion = cargarEnteroValidado("Ingrese el tipo de Formacion: 1- Sin Formacion, 2 - Residencia, 3- Concurrencia", 0, 4);

    reg.setIdFormacion(idFormacion);
}



void modificarTodo(Especialidad &reg){

    modificarNombreEspecialidad(reg);
    modificarDescripcion(reg);
    modificarFormacion(reg);

    }
