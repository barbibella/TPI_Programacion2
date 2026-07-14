#include <iostream>
#include "InformesManager.h"
#include "OrdenMedica.h"
#include "OrdenMedicaArchivo.h"
#include "ObraSocial.h"
#include "Afiliado.h"
#include "AfiliadoArchivo.h"
#include "AfiliadoManager.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"
#include "Medico.h"
#include "MedicoArchivo.h"
#include "Especialidad.h"
#include "EspecialidadArchivo.h"

using namespace std;

//constructor
InformesManager::InformesManager(){}
//BARBI
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
//EVE
void InformesManager::TipoOrdenConMayorRegistros(){}



///MAI
///Cantidad de ordenes emitidas por Medico
//esta funcion toma informacion de la clase OrdenMedicaArchivo y de Medico
void InformesManager::MedicoCantOrdenEmitidas(){
    OrdenMedicaArchivo archivoOrden;
    MedicoArchivo archivoMedico;

    int cantOrdenes = archivoOrden.contarRegistros();
    int cantMedicos = archivoMedico.getCantidadRegistros();

    if(cantOrdenes <= 0 || cantMedicos <=0){
        cout << "No hay datos suficientes para generar el informe. "<< endl;
        return;
    }

    int *contador = new int[cantMedicos];//inicializa un vector dinamico,
                                          // por lo que pide asignacion de memoria.

    for ( int i=0; i < cantMedicos; i++){
            contador[i]=0;
    }

    for (int i=0; i < cantOrdenes; i++){
            OrdenMedica regOrden = archivoOrden.leer(i);

        int matricula = regOrden.getMatriculaMedico();
        int posMedico = archivoMedico.buscarMatricula(matricula);

        if(posMedico!=-1){
            contador[posMedico]++;
        }
    }

    cout << "Cantidad de ordenes emitidas por médico: "<< endl;
    for (int i=0; i < cantMedicos; i++){
            Medico regMedico = archivoMedico.leer(i);

            cout<< "Nombre y Apellido: " <<regMedico.getNombre()<<" "<< regMedico.getApellido()<<endl;
            cout<< "Matricula #: "<< regMedico.getMatricula()<<endl;
            cout<< "Cantidad de ordenes: "<< contador[i]<< endl;
    }

    delete[] contador; //libera la memoria dinamica pedida anteriormente
}


///MAI
///Cantidad de ordenes emitidas por Especialidad
void InformesManager::EspecialidadCantOrdenEmitidas(){
    OrdenMedicaArchivo archivoOrden;
    MedicoArchivo archivoMedico;
    EspecialidadArchivo archivoEspecialidad;

    int cantOrdenes = archivoOrden.contarRegistros();
    int cantEspecialidades = archivoEspecialidad.getCantidadRegistros();

     if(cantOrdenes <= 0 || cantEspecialidades <=0){
        cout << "No hay datos suficientes para generar el informe. "<< endl;
        return;
    }

    int *contador = new int[cantEspecialidades]; //inicializa un vector dinamico,
    for ( int i=0; i < cantEspecialidades; i++){
            contador[i]=0;
    }

    for (int i=0; i < cantOrdenes; i++){
            OrdenMedica regOrden = archivoOrden.leer(i);

        int matricula = regOrden.getMatriculaMedico();
        int posMedico = archivoMedico.buscarMatricula(matricula);

        if(posMedico!=-1){
            Medico regMedico = archivoMedico.leer(posMedico);
            int idEspecialidad = regMedico.getEspecialidad();
            int posEspecialidad = archivoEspecialidad.buscarIdEspecialidad(idEspecialidad);

            if(posEspecialidad !=-1){
                    contador[posEspecialidad]++;
            }
        }
    }

    cout <<  "Cantidad de ordenes por especialidad: "<< endl;
    for(int i=0; i< cantEspecialidades; i++){
            Especialidad regEspecialidad = archivoEspecialidad.leer(i);
            cout <<"Especialidad: " << regEspecialidad.getNombreEspecialidad()<<endl;
            cout<<"Cantidad de ordenes emitidas: "<< contador[i]<< endl;
    }

    delete[] contador; //libera la memoria dinamica pedida anteriormente

}




// FALTA
void InformesManager::OrdenCantAutorizadasMensual(){}
// FALTA
void InformesManager::OrdenCantRechazadasMensual(){}


