/*
AHORA ESTO ESTA EN MenuPrincipalManager.

#include <iostream>
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
#include "AfiliadoManager.h"
#include "OrdenMedicaManager.h"
#include "TipoDeOrdenManager.h"
#include "OrigenDeLaOrdenManager.h"
#include "AutorizacionManager.h"
// #include "InformeManager.h"

using namespace std;

int main() {
    ObraSocialArchivo archObra;
    archObra.crearObrasSocialesPredeterminadas();

    // (Si tienen funciones similares para predeterminar Tipos de Orden o Origenes, las llamas aca)

    int opcion;
    do {
        system("cls");
        cout << "==================================================" << endl;
        cout << "       SISTEMA DE GESTION DE ORDENES MEDICAS      " << endl;
        cout << "==================================================" << endl;
        cout << " 1. GESTION DE AFILIADOS" << endl;
        cout << " 2. GESTION DE OBRAS SOCIALES" << endl;
        cout << " 3. GESTION DE ORDENES MEDICAS" << endl;
        cout << " 4. GESTION DE TIPOS DE ORDEN" << endl;
        cout << " 5. GESTION DE ORIGENES DE LA ORDEN" << endl;
        cout << " 6. GESTION DE AUTORIZACIONES" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " 0. SALIR DEL SISTEMA" << endl;
        cout << "==================================================" << endl;
        cout << " OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1:{
                AfiliadoManager am;
                am.Menu();
                break;
            }
            case 2:{
                ObraSocialManager osm;
                osm.Menu();
                break;
            }
            case 3:{
                OrdenMedicaManager omm;
                omm.menu();
                break;
            }
            case 4:{
                TipoDeOrdenManager tom;
                tom.menu();
                break;
            }
            case 5:{
                OrigenDeLaOrdenManager oom;
                oom.menu();
                break;
            }
            case 6: {
            AutorizacionManager aut;
            aut.menu();
            break;



            }
            case 0:
                cout << endl << "Gracias por usar el sistema. Saliendo..." << endl;
                break;
            default:
                cout << endl << "OPCION INCORRECTA. Intente nuevamente" << endl;
                system("pause");
                break;
        }
    } while (opcion != 0);

    return 0;
}



*/

#include "MenuPrincipalManager.h"

int main(){

    MenuPrincipalManager menu;
    menu.menu();

    return 0;
}











