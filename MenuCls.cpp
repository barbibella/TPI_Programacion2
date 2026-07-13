#include "MenuCls.h"
#include <cstdio>
#include <iostream>

// --- MAI ---
using namespace std;

Menu::Menu(){
	setCantidadOpciones(0);
}

void Menu::run(){
	int opcion;

	do{
		system("cls"); // borra pantalla
		mostrarOpciones();
		opcion = seleccionarOpcion(); //muestra y toma una opcion y borra todo lo que queda en memoria y solo quede lo que ingrese el usuario.
		ejecutarOpcion(opcion);
        if(opcion != 0){
            system("pause");
        }

	}while(opcion != 0);
}

int Menu::seleccionarOpcion(){
	int opcion;

	do {
		cout << "Ingrese opcion: ";
		cin >> opcion;
		if (cin.fail()){           ///borra lo que queda en memoria y queda solo lo que
            cin.clear();           ///ingreso el usuario
            cin.ignore(10000, '\n');

            cout << "Opcion no correcta " << endl;
            opcion = -1;
            continue;
		};

		if (opcion < 0 || opcion > getCantidadOpciones()){
			cout << "Opcion no correcta " << endl;
		}
	} while (opcion < 0 || opcion > getCantidadOpciones());

	return opcion;
}

void Menu::setCantidadOpciones(int cantidad){
	_cantidadOpciones = cantidad;
}

int Menu::getCantidadOpciones(){
	return _cantidadOpciones;
}
