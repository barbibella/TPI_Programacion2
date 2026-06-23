#include "auxiliares.h"
#include <iostream>
#include "Medico.h"
//===MAI===
//se incluyó este apartado para contemplar funciones, constructores y otras cosas necesarias generales. - Mai

std::string cargarCadena(){
    std::string texto;

    if (std::cin.peek() == '\n'){
        std::cin.ignore();
    }

    std::getline(std::cin, texto);

    return texto;
}
std::string cargarCadenaValidada(string mensaje, int maximo){
    string texto;

    do{
        cout << mensaje;
        texto = cargarCadena();

        if(texto.size() >= maximo){
            cout << "Dato invalido" << endl;
        }

    }while(texto.size() >= maximo);

    return texto;
}

int cargarEnteroValidado(string mensaje, int minimo){
 int valor;

    do{
        cout << mensaje;
        cin >> valor;

        if(valor < minimo ){
            cout << "Valor invalido" << endl;
        }

    }while(valor < minimo);

    return valor;
    }
//sobrecarga de funciones
int cargarEnteroValidado(string mensaje, int minimo, int maximo){
    int valor;

    do{
        cout << mensaje;
        cin >> valor;

        if(valor < minimo || valor > maximo){
            cout << "Valor invalido" << endl;
        }

    }while(valor < minimo || valor > maximo);

    return valor;
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

void modificarDNI(Medico &reg){
    string dni;

    dni = cargarCadenaValidada("Ingrese DNI: ", 15);

    reg.setDNI(dni);
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
