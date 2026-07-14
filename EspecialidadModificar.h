#pragma once
#include <string>
#include <iostream>
#include "Especialidad.h"
#include "MenuCls.h"

class EspecialidadModificar : public Menu{

public:
    EspecialidadModificar(Especialidad &reg); //constructor

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    private:
        Especialidad &_reg;
};

void modificarNombreEspecialidad(Especialidad &reg);
void modificarDescripcion (Especialidad &reg);
void modificarFormacion (Especialidad &reg);
void modificarTodo (Especialidad &reg);

