#include <iostream>
#include "Afiliado.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"

using namespace std;

void Afiliado::Cargar(int nroAuto){
    Persona::Cargar();
    nroDeAfiliado = nroAuto;
    ObraSocialArchivo archObraSocial;
    ObraSocialManager managerObraSocial;
    cout << "SU NUMERO DE AFILIADO ES: " << nroDeAfiliado << endl;
    bool idValido = false;

    while (!idValido) {
        cout << "Ingrese ID de Obra Social (o 0 para ver codigos disponibles): ";
        cin >> idObraSocial;

        if (idObraSocial == 0) {
            system("cls");
            managerObraSocial.ListarTodas();
            system("pause");
            system("cls");

            cout << "--- ASIGNAR OBRA SOCIAL ---" << endl;
            cout << "Paciente: " << apellido << ", " << nombre << " (Nro: " << nroDeAfiliado << ")" << endl << endl;
        } else {
            int posObra = archObraSocial.buscar(idObraSocial);

            if (posObra >= 0) {
                idValido = true;
            } else {
                cout << "Error: El ID ingresado no existe. Intente de nuevo" << endl;
                system("pause");
            }
        }
    }
    cout << "MAIL: "<< endl;
    cin>>email;
    while (strlen(email) <= 5 || strchr(email, '@') == NULL) {
        cout << "Mail invalido (Debe tener mas de 5 letras y contener '@'). Ingrese nuevamente: ";
        cin >> email;
    }
    _fechaNacimiento.Cargar();
}

void Afiliado::Mostrar(){
    if(estado == true){
    Persona::Mostrar();
    cout << "AFILIADO: " << nroDeAfiliado
         << ", ID: " << idObraSocial
         << " Y MAIL: " << email << endl;
    }
}
