#include "auxiliares.h"
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
