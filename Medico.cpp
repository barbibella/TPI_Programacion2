#include <iostream>
#include "Medico.h"

using namespace std;

void Medico::Cargar() {
    cout << "Ingrese su numero de matricula: " << endl;
//    cin >> _matricula; // Recordá usar los atributos con o sin guion bajo según los declararon en Medico.h
    cout << "Ingrese su ID especialidad: " << endl;
//    cin >> _especialidad;
}

void Medico::Mostrar() {
    if (_estado == true) {
        cout << "Nombre: " << getNombre() << " | Apellido: " << getApellido() << " | DNI: " << getDni() << endl;
//        cout << "La matricula es: " << _matricula << " y su especialidad es: " << _especialidad << endl;
    }
}

