#pragma once
#include "MedicoArchivo.h"

//--- MAI ---
class MedicoManager{
private:
    Medico crearMedico();
    void mostrarMedico(const Medico &reg);
    MedicoArchivo _repoMedico;

public:
    MedicoManager ();
    void guardarMedico(); //MAI - Funcion "AGREGAR"
    void listarMedicos(); // MAI - listar "TODOS"
    void listarMActivos();
    void listarInactivos();
    void modificarMedico();
    void eliminarMedico(); // MAI - BAJA LOGICA
    void altaMedico();     // MAI - ALTA LOGICA
    void informacionMedico();
    Medico cargar();

};

//FALTA HACER MENU - para mostrar
