#pragma once
#include "Informes.h"
#include "auxiliares.h"
#include "ObraSocialArchivo.h"
#include "AfiliadoArchivo.h"
#include "OrdenMedicaArchivo.h"

//--- MAI ---
class InformesManager{
private:
    /*
    Medico crearMedico();
    void mostrarMedico(const Medico &reg);
    MedicoArchivo _repoMedico;
    */
    ObraSocialArchivo archObraSocial;
    AfiliadoArchivo archAfiliado;
    OrdenMedicaArchivo archOrden;

public:
    InformesManager ();

    void Menu();
    void MenuInformes();



    void ObrasSocialesMasAtendidas();
   /* --- INFORMES ---
    void TipoOrdenConMayorRegistros();
    void MedicoCantOrdenEmitidas(); ///MAI
    void EspecialidadCantOrdenEmitidas(); ///MAI
    void OrdenCantAutorizadasMensual();
    void OrdenCantRechazadasMensual ();


    Informes cargar();

    void EjecutarOpcion(int opcion, Informes &reg);
    */
};



