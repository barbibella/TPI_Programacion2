#include <iostream>
#include <cstring>
#include "Afiliado.h"
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"

using namespace std;

ObraSocial::ObraSocial() : idObraSocial(-1), estado(false) {
    strcpy(nombre, "");
}

void ObraSocial::Cargar(){
    cout << "Ingrese el Nombre de la Obra Social: ";
    cin.ignore();
    cin.getline(nombre, 30);
    estado = true;
}

void ObraSocial::Mostrar(){
    cout << "ID: " << idObraSocial << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
}

void ObraSocial::setIdObraSocial(int id){
    idObraSocial = id;
    }
void ObraSocial::setNombre(std::string n){
    strcpy(nombre, n.c_str());
    }
void ObraSocial::setEstado(bool e){
    estado = e;
    }
int ObraSocial::getId()const{
    return idObraSocial;
    }
std::string ObraSocial::getNombre() const {
    return nombre;
}
bool ObraSocial::getEstado()const{
    return estado;
    }
