#include "MedicoModificar.h"
#include "Medico.h"
#include "MedicoArchivo.h"
#include "MedicoManager.h"
#include <iostream>


MedicoModificar::MedicoModificar(Medico &reg)
: _reg(reg)
{
    setCantidadOpciones(6);
}

void MedicoModificar::mostrarOpciones(){
        cout << "-----------------------------------------" << endl;
        cout << "Seleccione opcion a modificar " << endl;
   		cout << "1 - Matricula" << endl;
		cout << "2 - Nombre " << endl;
		cout << "3 - Apellido "  << endl;
		cout << "4 - DNI " << endl;
		cout << "5 - Telefono " << endl;
		cout << "6 - Todo " << endl;
		cout << "-----------------------------------------" << endl;
}

void MedicoModificar::ejecutarOpcion(int opcion){

    switch(opcion){
    case 1:
        modificarMatricula(_reg);
        break;
    case 2:
        modificarNombre(_reg);
        break;
    case 3:
        modificarApellido(_reg);
        break;
    case 4:
        modificarDni(_reg);
        break;
    case 5:
        modificarTelefono(_reg);
        break;
    case 6:
        modificarTodo(_reg);
        break;
    case 0:
        cout << "Saliendo..." << endl;
        break;
    }

}

 ///Modificaciones Medico
void modificarNombre(Medico &reg){
    string nombre;

    nombre = cargarCadenaValidada("Ingrese Nombre: ", 30);

    reg.setNombre(nombre);
}

void modificarApellido(Medico &reg){
    string apellido;

    apellido = cargarCadenaValidada("Ingrese Apellido: ", 30);

    reg.setApellido(apellido);
}

void modificarDni(Medico &reg){
    string dni;

    dni = cargarCadenaValidada("Ingrese DNI: ", 15);

    reg.setDni(dni);
}

void modificarTelefono(Medico &reg){
    string telefono;

    telefono = cargarCadenaValidada("Ingrese telefono: ", 20);

    reg.setTelefono(telefono);
}

void modificarMatricula(Medico &reg){
    int matricula;

    matricula = cargarEnteroValidado("Ingrese Matricula: ", 0, 7);

    reg.setMatricula(matricula);
}

void modificarEspecialidad(Medico &reg){
    int especialidad;

    especialidad = cargarEnteroValidado("Ingrese Especialidad: ", 0, 10 );

    reg.setEspecialidad(especialidad);
}

void modificarTodo(Medico &reg){

    modificarNombre(reg);
    modificarApellido(reg);
    modificarDni(reg);
    modificarTelefono(reg);
    modificarEspecialidad(reg);
    modificarMatricula(reg);

    }
