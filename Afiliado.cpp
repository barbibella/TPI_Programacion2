#include <iostream>
#include "Afiliado.h"

using namespace std;

void Afiliado::Cargar(int nroAuto){
    Persona::Cargar();
    nroDeAfiliado = nroAuto;
    cout << "SU NUMERO DE AFILIADO ES: " << nroDeAfiliado << endl;
    cout << "ID: " << endl;
    cin>>idObraSocial;
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
