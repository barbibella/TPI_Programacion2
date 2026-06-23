#include <iostream>

using namespace std;

#include "AutorizacionManager.h"
#include "Autorizacion.h"
#include "AutorizacionArchivo.h"
#include "OrdenMedicaArchivo.h"
#include "OrdenMedica.h"




void AutorizacionManager::menu(){

    int opcion;

    do{

        system("cls");

        cout << "===== AUTORIZACIONES =====" << endl;
        cout << "1. LISTAR TODAS LAS AUTORIZACIONES" << endl;
        cout << "2. AGREGAR UNA AUTORIZACION" << endl;
        cout << "3. BUSCAR POR CODIGO UNA AUTORIZACION" << endl;
        cout << "4.LISTAR AUTORIZACIONES POR ESTADO. " << endl;
        cout << "5.CONSULTAR AUTORIZACIONES PORCENTAJE COBERTURA" << endl;
        cout << "6.CONSULTAR POR NRO DE ORDEN" << endl;
        cout << "7.CONSULTAR AUTORIZACIONES APROBADAS Y RECHAZADAS POR ANIO" << endl;
        cout << "8.Prueba de validaciones" << endl;
        cout << "0. SALIR" << endl;
        cout << "OPCION: ";

        cin >> opcion;

        system("cls");

        switch(opcion){

        case 1:
            listarTodos();
            break;

        case 2:
            agregar();
            break;

        case 3:
            buscarPorCodigo();
            break;
        case 4:
            listarPorEstado();
            break;
        case 5:
            listarPorCobertura();
            break;
        case 6:
            listarPorOrdenMedica();
            break;
        case 7:
            CantidadMensualAprobadoRechazado();
        case 8:

            break;

        case 0:
            break;

        default:
            cout << "OPCION INCORRECTA" << endl;
            break;
        }

        system("pause");

    }while(opcion != 0);
}

void AutorizacionManager::listarTodos(){

    AutorizacionArchivo archivo;

    int cantidad = archivo.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        Autorizacion reg;

        reg = archivo.leer(i);

        reg.Mostrar();
    }
}

void AutorizacionManager::agregar(){

    AutorizacionArchivo archivo;
    Autorizacion reg;

    reg.Cargar();

    if(archivo.guardar(reg)){
        cout << "La autorizacion se guardo correctamente!" << endl;
    }
    else{
        cout << "Error al guardar la autorizacion." << endl;
    }
}

void AutorizacionManager::buscarPorCodigo(){

    AutorizacionArchivo archivo;

    int codigo;

    cout << "Ingrese el codigo de autorizacion: ";
    cin >> codigo;

    int pos = archivo.buscar(codigo);

    if(pos == -1){

        cout << "No existe una autorizacion con ese codigo." << endl;
        return;
    }

    Autorizacion reg;

    reg = archivo.leer(pos);

    reg.Mostrar();
}


void AutorizacionManager::listarPorEstado(){

    int opcion;

    cout << "============================" << endl;
    cout << "1 - APROBADAS" << endl;
    cout << "2 - RECHAZADAS" << endl;
    cout << "ingrese la opcion: ";
    cin >> opcion;

    bool estadoBuscado;

    switch(opcion){

    case 1:
        estadoBuscado = true;
        break;

    case 2:
        estadoBuscado = false;
        break;

    default:
        cout << "Vuelva a ingresar la opcion" << endl;
        return;
    }

    AutorizacionArchivo arch;
    Autorizacion reg;

    int cantidad = arch.contarRegistros();

    for(int i = 0; i < cantidad; i++){

        reg = arch.leer(i);

        if(reg.getAprobada() == estadoBuscado){

            reg.Mostrar();
            cout << endl;
        }
    }
}


 void AutorizacionManager::listarPorCobertura() {

float CoberturaBuscada;
bool Encontrado=false;

cout << "INGRESE EL PORCENTAJE DE LA COBERTURA (1 AL 100):";
cin >> CoberturaBuscada;
cout << endl;

while(CoberturaBuscada<1||CoberturaBuscada>100) {
cout << "USTED INGRESO UN PORCENTAJE DE COBERTURA ERRONEO" << endl;
cout << "INGRESE NUEVAMENTE EL PORCENTAJE DE COBERTURA(1 AL 100):" ;
cin >>CoberturaBuscada;
}

AutorizacionArchivo arch;
Autorizacion reg;

int cantidad=arch.contarRegistros();

for(int i=0;i<cantidad;i++){
reg=arch.leer(i);
if(reg.getPorcentajeCobertura()==CoberturaBuscada){
reg.Mostrar();
cout << endl;
Encontrado=true;
}
}

if(Encontrado==false){
cout << "NO SE ENCONTRARON AUTORIZACION CON ESA COBERTURA" << endl;

}

 }

void AutorizacionManager::listarPorOrdenMedica(){

int nuOrden;
bool Encontrado=false;


cout << "INGRESE EL NUMERO DE ORDEN " << endl;
cin >> nuOrden;

AutorizacionArchivo arch;
Autorizacion reg;

int cantidad=arch.contarRegistros();
for(int i=0;i<cantidad;i++){
reg=arch.leer(i);
if(reg.getIdOrden()==nuOrden){
reg.Mostrar();
cout << endl;
Encontrado=true;
}

}

if(Encontrado==false){
cout << "NO SE ENCONTRARON AUTORIZACIONES CON ESE ID DE ORDEN";

}

}

void AutorizacionManager::CantidadMensualAprobadoRechazado()
{
    int aprobadas[12] = {0};
    int rechazadas[12] = {0};

    Autorizacion reg;
    AutorizacionArchivo arch;

    int anio;

    cout << "INGRESE EL ANIO A CONSULTAR: ";
    cin >> anio;

    int cantidad = arch.contarRegistros();

    for(int i = 0; i < cantidad; i++)
    {
        reg = arch.leer(i);

        if(reg.getFechaAutorizacion().getAnio() == anio)
        {
            int mes = reg.getFechaAutorizacion().getMes();

            if(reg.getAprobada())
            {
                aprobadas[mes - 1]++;
            }
            else
            {
                rechazadas[mes - 1]++;
            }
        }
    }

    const char *meses[12] =
    {
    "ENERO",
    "FEBRERO",
    "MARZO",
    "ABRIL",
    "MAYO",
    "JUNIO",
    "JULIO",
    "AGOSTO",
    "SEPTIEMBRE",
    "OCTUBRE",
    "NOVIEMBRE",
    "DICIEMBRE"
    };

    cout << endl;
    cout << "INFORME DEL ANIO " << anio << endl;
    cout << "==========================" << endl;

    for(int i = 0; i < 12; i++)
    {
        cout << meses[i] << endl;
        cout << "Aprobadas: " << aprobadas[i] << endl;
        cout << "Rechazadas: " << rechazadas[i] << endl;
        cout << endl;
    }

    }



