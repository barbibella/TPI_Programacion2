#include <iostream>
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
*/

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
    fecha.Mostrar();  // Mostrar*/

    return 0;
}
