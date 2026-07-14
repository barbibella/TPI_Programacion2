#include "auxiliares.h"
#include "Medico.h"
#include "MedicoArchivo.h"
#include "MedicoManager.h"
#include <iostream>
//===MAI===
//se incluyó este apartado para contemplar funciones, constructores y otras cosas necesarias generales. - Mai

std::string cargarCadena(){
    std::string texto;

    if (std::cin.peek() == '\n'){
        std::cin.ignore();
    }

    std::getline(std::cin, texto);

    return texto;
}

std::string cargarCadenaValidada(string mensaje, int maximo){
    string texto;

    do{
        cout << mensaje;
        texto = cargarCadena();

        if(texto.size() >= maximo){
            cout << "Dato invalido" << endl;
        }

    }while(texto.size() >= maximo);

    return texto;
}

int cargarEnteroValidado(string mensaje, int minimo){
 int valor;

    do{
        cout << mensaje;
        cin >> valor;

        if(valor < minimo ){
            cout << "Valor invalido" << endl;
        }

    }while(valor < minimo);

    return valor;
    }

//sobrecarga de funciones
int cargarEnteroValidado(string mensaje, int minimo, int maximo){
    int valor;

    do{
        cout << mensaje;
        cin >> valor;

        if(valor < minimo || valor > maximo){
            cout << "Valor invalido" << endl;
        }

    }while(valor < minimo || valor > maximo);

    return valor;
}


///normaliza textos para poder compararlos entre si
string aMinusculas(string texto){
    for(int i = 0; i < texto.size(); i++){
        if(texto[i] >= 'A' && texto[i] <= 'Z'){
            texto[i] = texto[i] + 32;
        }
    }
    return texto;
}//toma todo el texto que recibe,
//por la cant de carateres que tenga el texto
