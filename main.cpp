#include <iostream>
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
#include "AfiliadoManager.h"
#include "OrdenMedicaManager.h"
#include "TipoDeOrdenManager.h"
#include "OrigenDeLaOrdenManager.h"
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
        cout << "--------------------------------------------------" << endl;
        cout << " 0. SALIR DEL SISTEMA" << endl;
        cout << "==================================================" << endl;
        cout << " OPCION: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                AfiliadoManager am;
                am.Menu();
                break;
            }
            case 2: {
                ObraSocialManager osm;
                osm.Menu();
                break;
            }
            case 3: {
                OrdenMedicaManager omm;
                omm.menu();
                break;
            }
            case 4: {
                TipoDeOrdenManager tom;
                tom.menu();
                break;
            }
            case 5: {
                OrigenDeLaOrdenManager oom;
                oom.menu();
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
/**#include <iostream>
#include "Fecha.h"
#include "Persona.h"
#include "Medico.h"
#include "Afiliado.h"
#include "OrdenMedica.h"
#include "AfiliadoManager.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"

using namespace std;
/**
El Gestor de Pacientes y Coberturas (Afiliados y Obras Sociales)
Archivos a cargo: Afiliado.h/.cpp, AfiliadoArchivo.h/.cpp, AfiliadoManager.h/.cpp,
ObraSocial.h/.cpp, ObraSocialArchivo.h/.cpp, y ObraSocialManager.h/.cpp


int main()
{
    AfiliadoManager manager;
    manager.Menu();
 /*
    ObraSocialArchivo archObra;
    archObra.crearObrasSocialesPredeterminadas();
    ObraSocialManager manager1;
    manager1.Menu();

  Fecha fecha;      // Crear objeto
   Persona persona;
   Medico medico;
   Afiliado afiliado;
   OrdenMedica ordenm;

    persona.Cargar();   // Llamar método
    persona.Mostrar();  // Mostrar
    cout << endl;
    cout << endl;
    cout << endl;
    medico.Cargar();
   // medico.Mostrar();
    cout << endl;
    cout << endl;
    cout << endl;
    afiliado.Cargar();   // Llamar método
    afiliado.Mostrar();
    cout << endl;
    cout << endl;
    cout << endl;
    ordenm.Cargar();   // Llamar método
    ordenm.Mostrar();
    cout << endl;
    cout << endl;
    cout << endl;
    fecha.Cargar();   // Llamar método
    fecha.Mostrar();  // Mostrar

    return 0;
}
*/
