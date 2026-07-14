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
    void eliminarEspecialidad();  ///listo!
    void altaEspecialidad(); /// LISTO!
    void listarEspActivos(); /// LISTO!
    bool listarEspInactivos(); ///LISTO!
    void modificarEspecialidad(); ///FALTA!
    void informacionEspecialidad(); /// FALTA!
    int  mostrarMenuModificar();
    void ejecutarOpcion(int opcion,Especialidad &reg);

private:
    Especialidad crearEspecialidad();
    void mostrarEspecialidad(const Especialidad &reg);///Busca la informacion de 1 especialidad y la muestra
    EspecialidadArchivo _repoEspecialidad;
};
