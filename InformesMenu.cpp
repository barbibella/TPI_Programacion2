#include <cstdio>
#include <iostream>
#include "InformesMenu.h"

/// ----- MAI -----

using namespace std;

InformesMenu::InformesMenu()
{
    setCantidadOpciones(6);
}

void InformesMenu::mostrarOpciones(){

        cout << "=== MENU INFORMES ===" << endl;
        cout << "1. OBRAS SOCIALES MAS ATENDIDAS" << endl;
        cout << "2. TIPO DE ORDEN CON MAYOR REGISTROS" << endl;
        cout << "3. CANTIDAD DE ORDENES EMITIDAS POR MEDICO" << endl;
        cout << "4. CANTIDAD DE ORDENES EMITIDAS POR ESPECIALIDAD" << endl;
        cout << "5. CANTIDAD DE ORDENES AUTORIZADAS POR MES" << endl;
        cout << "6. CANTIDAD DE ORDENES RECHAZADAS POR MES " << endl;
        cout << "=========================" << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;

}


void InformesMenu::ejecutarOpcion(int opcion){
    switch(opcion){
            case 1: _managerInformes.ObrasSocialesMasAtendidas(); break;// Informe "obras sociales mas atendidas"
            /*case 2: TipoOrdenConMayorRegistros();
                break;
            case 3: MedicoCantOrdenEmitidas();
                break;
            case 4: EspecialidadCantOrdenEmitidas();
                break;
            case 5: OrdenCantAutorizadasMensual();
                break;
            case 6: OrdenCantRechazadasMensual ();
                break;
            case 0: cout << "Saliendo del menu" << endl;
                break;*/
            }
}

