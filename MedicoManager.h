#pragma once
#include "MedicoArchivo.h"

//--- MAI ---
class MedicoManager{
private:
    Medico crearMedico();
    void mostrarMedico(const Medico &reg);
    MedicoArchivo _repoMedico;

public:
    MedicoManager();

    void Menu();//FALTA AGREGAR URGENTE

    void guardarMedico(); //MAI - Funcion "AGREGAR/CREAR"
    void listarMedicos(); // MAI - listar "TODOS"
    void listarMActivos();
    bool listarInactivos();
    void modificarMedico();
    void eliminarMedico(); // MAI - BAJA LOGICA - ESTA EN MedicoArchivo!!!
    void altaMedico();     // MAI - ALTA LOGICA
    void informacionMedico();
    Medico cargar();

};

//FALTA HACER MENU - para mostrar
