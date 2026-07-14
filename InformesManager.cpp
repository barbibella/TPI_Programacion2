#include <iostream>
#include "InformesManager.h"
#include "OrdenMedica.h"
#include "OrdenMedicaArchivo.h"
#include "Medico.h"
#include "MedicoArchivo.h"
#include "Especialidad.h"
#include "EspecialidadArchivo.h"

using namespace std;

//constructor
InformesManager::InformesManager(){}
//BARBI
void InformesManager::ObrasSocialesMasAtendidas(){}
//BARBI
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


