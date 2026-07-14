#pragma once
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
#include <cstring>

//--- MAI ---

class EspecialidadManager
{
public:
    EspecialidadManager();

    Especialidad cargar();
    void guardarEspecialidad();//crear
    void listarEspecialidad();/// LISTAR TODOS
    void eliminarEspecialidad();
    void altaEspecialidad();
    void listarEspActivos();
    bool listarEspInactivos();
    void modificarEspecialidad();
    void informacionEspecialidad();
    int  mostrarMenuModificar();
    void ejecutarOpcion(int opcion,Especialidad &reg);

private:
    Especialidad crearEspecialidad();
    void mostrarEspecialidad(const Especialidad &reg);///Busca la informacion de 1 especialidad y la muestra
    EspecialidadArchivo _repoEspecialidad;
};
