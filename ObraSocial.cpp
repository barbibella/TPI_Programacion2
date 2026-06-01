#include <iostream>
#include "Afiliado.h"
#include "ObraSocial.h"

using namespace std;

void ObraSocial::Cargar(){
    cout << "Ingrese su ID: " << endl;
    cin>>idObraSocial;
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
