#pragma once
#include "Persona.h"
#include "Fecha.h"

class Afiliado: public Persona{
  private:
      int nroDeAfiliado, idObraSocial;
      char email[45];
      Fecha _fechaNacimiento;

  public:
    void Cargar(int nroAuto);
    void Mostrar();


    int getNroDeAfiliado() { return nroDeAfiliado; }
    int getIDObraSocial() { return idObraSocial; }
};
