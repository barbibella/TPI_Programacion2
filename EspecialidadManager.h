#pragma once
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include <cstring>

//--- MAI ---

class EspecialidadManager
{
public:
    EspecialidadManager();

    void Menu();//FALTA AGREGAR URGENTE

    void guardarEspecialidad();//crear
    void listarEspecialidad();// LISTAR
    void modificarEspecialidad();
    void informacionEspecialidad();
    Especialidad cargar();

private:
    Especialidad crearEspecialidad();
    void mostrarEspecialidad(const Especialidad &reg);
    EspecialidadArchivo _repoEspecialidad;
};
