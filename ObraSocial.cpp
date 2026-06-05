#include <iostream>
#include "Afiliado.h"
#include "ObraSocial.h"

using namespace std;

void ObraSocial::Cargar(){
    cout << "--- AGREGAR OBRA SOCIAL ---" << endl << endl;
    cout << "Ingrese su ID: " << endl;
    cin>>idObraSocial;
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
void ObraSocial::setNombre(const char* n){
    strcpy(nombre, n);
    }
void ObraSocial::setEstado(bool e){
    estado = e;
    }
