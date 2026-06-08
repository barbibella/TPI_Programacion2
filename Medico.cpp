#include <iostream>
#include "Medico.h"
using namespace std;


void Medico::Cargar(){
    Persona::Cargar();
    cout << "Ingrese su numero de matricula: " << endl;
    cin>>matricula;
    cout <<"Ingrese su ID especialidad: " << endl;
    cin>>especialidad;
}

void Medico::Mostrar(){
    if(estado == true){
    Persona::Mostrar();
    cout << "La matricula es: " << matricula << " y su especialidad es: " << especialidad << endl;
    }
}

