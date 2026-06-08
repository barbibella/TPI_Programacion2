#include <iostream>
#include <cstring>
#include "Afiliado.h"
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"

using namespace std;

void ObraSocial::Cargar(){
    cin.ignore();

    cout << "Ingrese el Nombre de la Obra Social: ";
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
void ObraSocial::setNombre(const char* n){
    strcpy(nombre, n);
    }
void ObraSocial::setEstado(bool e){
    estado = e;
    }
int ObraSocial::getId(){
    return idObraSocial;
    }
bool ObraSocial::getEstado(){
    return estado;
    }
