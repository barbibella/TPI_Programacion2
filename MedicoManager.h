#pragma once
#include "Medico.h"
#include "MedicoArchivo.h"
#include "auxiliares.h"
///MAI PC
//--- MAI ---
class MedicoManager{
private:
    Medico crearMedico();
    void mostrarMedico(const Medico &reg);
    MedicoArchivo _repoMedico;

public:
    MedicoManager ();

    void Menu();//FALTA AGREGAR URGENTE

    void guardarMedico(); //MAI - Funcion "AGREGAR"
    void listarMedicos(); // MAI - listar "TODOS"
    void listarMActivos();
    void listarInactivos();
    void modificarMedico();
    void eliminarMedico(); // MAI - BAJA LOGICA
    void altaMedico();     // MAI - ALTA LOGICA
    void informacionMedico();  // Mostrar 1 medico por DNI
    Medico cargar();
    int mostrarMenuModificar();
    void EjecutarOpcion(int opcion,const Medico &reg);

};

/*
//FALTA HACER MENU - para mostrar
  FALTA ELIMINAR: void eliminarMedico(); (BAJA LÓGICA)
  FALTA BUSCAR POR MATRICULA
  FALTA void eliminarMedico();
  No entiendo qué funcion es informacionMedico, es mostrarMedico??
  En Especialidad Falta:
    void informacionEspecialidad();

*/
