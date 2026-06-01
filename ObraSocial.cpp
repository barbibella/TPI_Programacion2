#include <iostream>
#include "Afiliado.h"
#include "ObraSocial.h"

using namespace std;

void ObraSocial::Cargar(){
    cout << "Ingrese su ID: " << endl;
    cin>>idObraSocial;
    cin.ignore();
    cout << "OBRAS SOCIALES DISPONIBLES." << endl;
        cout << "| IOMA                      |" << endl;
        cout << "| OSDE                      |" << endl;
        cout << "| SWISS MEDICAL             |" << endl;
        cout << "| OSECAC                    |" << endl;
        cout << "| GALENO                    |" << endl;
        cout << "| MEDICUS                   |" << endl;
        cout << "| SANCOR SALUD              |" << endl;
        cout << "| UNION PERSONAL            |" << endl;
        cout << "| OSEP                      |" << endl;
    cout << "Ingrese el Nombre de la Obra Social: " << endl;

    cin.getline(nombre, 30);
    estado = true;
}

void ObraSocial::Mostrar(){
    cout << "ID: " << idObraSocial << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Estado: " << (estado ? "Activo" : "Inactivo") << endl;
}
