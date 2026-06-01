#pragma once
#include "Persona.h"

class Medico: public Persona{
   private:
      int matricula, especialidad;

   public:
      void Cargar();
      void Mostrar();


      getMatricula(){ return matricula;}
};
