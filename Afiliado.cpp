#include <iostream>
#include "Afiliado.h"
#include "ObraSocialArchivo.h"
#include <iostream>
#include <cstring>
#include "Afiliado.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"

using namespace std;

Afiliado::Afiliado()
: nroDeAfiliado(-1), idObraSocial(-1), Persona() {
    strcpy(email, "");
}

Afiliado::Afiliado(int nroAfiliado, int idObra, string mail, Fecha fechaNac,
                   string nombre, string apellido, string dni, string telefono, bool estado)
: Persona(nombre, apellido, dni, telefono, estado) {
    nroDeAfiliado = nroAfiliado;
    idObraSocial = idObra;
    strcpy(email, mail.c_str());
    _fechaNacimiento = fechaNac;
}

void Afiliado::Cargar(int nroAuto){
    nroDeAfiliado = nroAuto;
    ObraSocialArchivo archObraSocial;
    ObraSocialManager managerObraSocial;
    bool idValido = false;

    while (!idValido) {
        cout << "Ingrese ID de Obra Social (o 0 para ver las Obras disponibles): ";
        cin >> idObraSocial;

        if (idObraSocial == 0) {
            system("cls");
            managerObraSocial.ListarTodas();
            system("pause");
            system("cls");

            cout << "--- ASIGNAR OBRA SOCIAL ---" << endl;
            cout << "Paciente: " << _apellido << ", " << _nombre << " (Nro: " << nroDeAfiliado << ")" << endl << endl;
        } else {
            if (idObraSocial >= 1 && idObraSocial <= 10){
                int posObra = archObraSocial.buscar(idObraSocial);

                if (posObra >= 0) {
                    idValido = true;
                } else {
                    cout << "Error: El ID ingresado no existe. Intente de nuevo" << endl;
                    system("pause");
                }
            }
        }
    }
    cout << "MAIL: ";
    cin >> email;
    while (strlen(email) <= 5 || strchr(email, '@') == NULL) {
        cout << "Mail invalido (Debe tener mas de 5 letras y contener '@'). Ingrese nuevamente: ";
        cin >> email;
    }
    _fechaNacimiento.Cargar();
}

void Afiliado::Mostrar(){
    if(_estado == true){
       cout << "Nombre: " << getNombre() << endl;
        cout << "Apellido: " << getApellido() << endl;
        cout << "DNI: " << getDni() << endl;
        cout << "Telefono: " << getTelefono() << endl;

        cout << "AFILIADO: #" << nroDeAfiliado
             << " | ID Obra Social: " << idObraSocial
             << " | MAIL: " << email << endl;

        if (getEstado() == false) {
        cout << " ❌ [DADO DE BAJA]";
        }
         cout << endl << "-----------------------------------------" << endl;
    }
}

int Afiliado::getNroDeAfiliado() const {
    return nroDeAfiliado;
}

int Afiliado::getIDObraSocial() const {
    return idObraSocial;
}

void Afiliado::setIdObraSocial(int id) {
    idObraSocial = id;
}
