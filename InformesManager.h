#pragma once
#include "Informes.h"
#include "auxiliares.h"

//--- MAI ---
class InformesManager{
private:
    /*
    Medico crearMedico();
    void mostrarMedico(const Medico &reg);
    MedicoArchivo _repoMedico;
    */

public:
    InformesManager ();

    void Menu();
    void MenuInformes();

    /*
    --- INFORMES ---
    void ObrasSocialesMasAtendidas();
    void TipoOrdenConMayorRegistros();
    void MedicoCantOrdenEmitidas(); ///MAI
    void EspecialidadCantOrdenEmitidas(); ///MAI
    void OrdenCantAutorizadasMensual();
    void OrdenCantRechazadasMensual ();


    Informes cargar();

    void EjecutarOpcion(int opcion, Informes &reg);
    */
};



