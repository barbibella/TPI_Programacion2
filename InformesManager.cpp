#include <iostream>
#include <cstring>
#include "Informes.h"
#include "InformesManager.h"
#include "auxiliares.h"

//--- MAI ---
using namespace std;
///constructor
InformesManager::InformesManager()
: _repoInformes (){}

// Informe Manager Métodos

  /* METODOS A DESARROLLAR
    --- INFORMES ---
    void ObrasSocialesMasAtendidas();   //BARBI
    void TipoOrdenConMayorRegistros();  //EVE
    void MedicoCantOrdenEmitidas();     //MAI
    void EspecialidadCantOrdenEmitidas(); //MAI
    void OrdenCantAutorizadasMensual();   //EVE
    void OrdenCantRechazadasMensual ();   //EVE
*/

void InformesManager::ObrasSocialesMasAtendidas(){
    int cantOS = archObraSocial.contarRegistros();
    if (cantOS == 0) {
        cout << "No hay Obras Sociales registradas para analizar." << endl;
        return;
    }

    //un vector dinamico de contadores
    int* contadores = new int[cantOS]{};
    // recorremos el archivo de ordenes medicas
    int cantOrdenes = archOrden.contarRegistros();
    for(int i = 0; i < cantOrdenes; i++) {
        OrdenMedica ord = archOrden.leer(i);

        // solo se cuenta las ordenes validas/atendidas
        if(ord.getEstado() == true) {
            int idAfiliado = ord.getIdAfiliado();

            // busca al afiliado en su archivo para saber su Obra Social
            int posAfi = archAfiliado.buscar(idAfiliado);
            if(posAfi >= 0) {
                Afiliado afi = archAfiliado.leer(posAfi);
                int idOS = afi.getIDObraSocial();

                if(idOS > 0 && idOS <= cantOS) {
                    contadores[idOS - 1]++;
                }
            }
        }
    }

    //busca el valor maximo
    int maxAtenciones = 0;
    for(int i = 0; i < cantOS; i++) {
        if(contadores[i] > maxAtenciones) {
            maxAtenciones = contadores[i];
        }
    }
    cout << "--- OBRAS SOCIALES CON MAYOR CANTIDAD DE AFILIADOS ATENDIDOS ---" << endl << endl;
    if(maxAtenciones == 0) {
        cout << "No se registran atenciones medicas en el sistema." << endl;
    }else {
        cout << "Mayor cantidad de atenciones registradas: " << maxAtenciones << endl << endl;
        cout << "Obras Sociales asociadas:" << endl;

        for(int i = 0; i < cantOS; i++) {
            if(contadores[i] == maxAtenciones) {
                //bueca el nombre de la obra social leyendo el registro correspondiente
                ObraSocial os = archObraSocial.leer(i);
                cout << "- ID: " << os.getId() << " | Nombre: " << os.getNombre() << endl;
            }
        }
    }
    delete[] contadores;
}
/*
void InformesManager::TipoOrdenConMayorRegistros(){}

void InformesManager::MedicoCantOrdenEmitidas(){}

void InformesManager::EspecialidadCantOrdenEmitidas(){}

void InformesManager::OrdenCantAutorizadasMensual(){}

void InformesManager::OrdenCantRechazadasMensual(){}
*/
