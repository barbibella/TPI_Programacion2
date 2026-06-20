#pragma once
#include "Persona.h"
#include "auxiliares.h"
#include <cstring>

using namespace std;
// MAI
class Medico: public Persona{
   private:
      int _matricula, _especialidad;

    public:
        Medico();
        Medico(int matricula, int especialidad, string nombre, string apellido, string dni, string telefono, bool estado);

//SETTERS - MAI
    void setMatricula (int matricula);
    void setEspecialidad (int especialidad);

//GETTERS - MAI
    int getMatricula () const;
    string getEspecialidad() const;
};


