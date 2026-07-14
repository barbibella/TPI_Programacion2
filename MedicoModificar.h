#pragma once
#include <string>
#include <iostream>
#include "Medico.h"
#include "MenuCls.h"

class MedicoModificar : public Menu{

public:
    MedicoModificar(Medico &reg); //constructor

    void mostrarOpciones();
    void ejecutarOpcion(int opcion);

    private:
        Medico &_reg;
};

void modificarNombre(Medico &reg);
void modificarApellido (Medico &reg);
void modificarDni (Medico &reg);
void modificarTelefono (Medico &reg);
void modificarMatricula (Medico &reg);
void modificarEspecialidad (Medico &reg);
void modificarTodo (Medico &reg);
