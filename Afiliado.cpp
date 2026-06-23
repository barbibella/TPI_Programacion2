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
: _nroDeAfiliado(-1), _idObraSocial(-1), Persona() {
    strcpy(_email, "");
}

Afiliado::Afiliado(int nroAfiliado, int idObra, string mail, Fecha fechaNac,
                   string nombre, string apellido, string dni, string telefono, bool estado)
: Persona(nombre, apellido, dni, telefono, estado) {
    _nroDeAfiliado = nroAfiliado;
    _idObraSocial = idObra;
    strcpy(_email, mail.c_str());
    _fechaNacimiento = fechaNac;
}

void Afiliado::Cargar(int nroAuto){
    _nroDeAfiliado = nroAuto;
    ObraSocialArchivo archObraSocial;
    ObraSocialManager managerObraSocial;
    bool idValido = false;

    while (!idValido) {
        cout << "Ingrese ID de Obra Social (o 0 para ver las Obras disponibles): ";
        cin >> _idObraSocial;

        if (_idObraSocial == 0) {
            system("cls");
            managerObraSocial.ListarTodas();
            system("pause");
            system("cls");

            cout << "--- ASIGNAR OBRA SOCIAL ---" << endl;
            cout << "Paciente: " << _apellido << ", " << _nombre << " (Nro: " << _nroDeAfiliado << ")" << endl << endl;
        } else {
            if (_idObraSocial >= 1 && _idObraSocial <= 10){
                int posObra = archObraSocial.buscar(_idObraSocial);

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
    cin >> _email;
    while (strlen(_email) <= 5 || strchr(_email, '@') == NULL) {
        cout << "Mail invalido (Debe tener mas de 5 letras y contener '@'). Ingrese nuevamente: ";
        cin >> _email;
    }
    _fechaNacimiento.Cargar();
}

void Afiliado::Mostrar(){
    if(_estado == true){
       cout << "Nombre: " << getNombre() << endl;
        cout << "Apellido: " << getApellido() << endl;
        cout << "DNI: " << getDni() << endl;
        cout << "Telefono: " << getTelefono() << endl;

        cout << "AFILIADO: #" << _nroDeAfiliado
             << " | ID Obra Social: " << _idObraSocial
             << " | MAIL: " << _email << endl;

        if (getEstado() == false) {
        cout << "DADO DE BAJA";
        }
         cout << endl << "-----------------------------------------" << endl;
    }
}

int Afiliado::getNroDeAfiliado() const {
    return _nroDeAfiliado;
}

int Afiliado::getIDObraSocial() const {
    return _idObraSocial;
}

void Afiliado::setIdObraSocial(int id) {
    _idObraSocial = id;
}
