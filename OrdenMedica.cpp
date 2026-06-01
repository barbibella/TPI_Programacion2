#include <iostream>
#include "OrdenMedica.h"

using namespace std;

void OrdenMedica::Cargar(){
    cout << "Ingrese el ID de la orden: ";
    cin>>idOrden;
    cout << "Ingrse la matricula del medico: ";
    cin>>matriculaMedico;
    cout << "El tipo de orden: ";
    cin>>tipoOrden;
    cout << "Origen: ";
    cin>>origen;
    cout << "Ingese el DNI del paciente: ";
    cin>>dniPaciente;

}

void OrdenMedica::Mostrar(){
    cout << " La informacion ingresada fue: " << idOrden << matriculaMedico <<tipoOrden <<origen <<dniPaciente;
}
