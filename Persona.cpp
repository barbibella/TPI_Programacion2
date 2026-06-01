#include <iostream>
#include "Persona.h"

using namespace std;

void Persona::Cargar(){
    cout << "Buenas, podria ingresar sus datos personales: " << endl;
    cout<<"NOMBRE ";
    //cin.ignore();
    cin.getline(nombre, 30);

    cout << "APELLIDO: ";
    cin.getline(apellido, 30);

    cout << "DNI: ";
    cin >> dni;

    cout << "TELEFONO: ";
    cin >> telefono;
    while (strlen(telefono) <= 5) {
        cout << "El telefono debe tener mas de 5 digitos. Ingrese nuevamente: ";
        cin >> telefono;
    }

    estado = true;

}

void Persona::Mostrar(){
    cout << endl;
    cout << "Usted ingreso: " <<endl;
    cout<<nombre<<" "<<apellido<<endl;
    cout<<"DNI: "<<dni<<endl;
}
