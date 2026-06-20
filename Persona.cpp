#include <iostream>
#include <cstring>
#include "Persona.h"

using namespace std;

Persona::Persona() {
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_dni, "");
    strcpy(_telefono, "");
    _estado = false;
}

Persona::Persona(string nombre, string apellido, string dni, string telefono, bool estado) {
    strcpy(_nombre, nombre.c_str());
    strcpy(_apellido, apellido.c_str());
    strcpy(_dni, dni.c_str());
    strcpy(_telefono, telefono.c_str());
    _estado = estado;
}

void Persona::setNombre(string nombre) {
    strcpy(_nombre, nombre.c_str());
}

void Persona::setApellido(string apellido) {
    strcpy(_apellido, apellido.c_str());
}

void Persona::setDni(string dni) {
    strcpy(_dni, dni.c_str());
}

void Persona::setTelefono(string telefono) {
    strcpy(_telefono, telefono.c_str());
}

void Persona::setEstado(bool estado) {
    _estado = estado;
}

string Persona::getNombre() const {return _nombre; }
string Persona::getApellido() const {return _apellido; }
string Persona::getDni() const {return _dni; }
string Persona::getTelefono() const {return _telefono; }
bool Persona::getEstado() const {return _estado; }
