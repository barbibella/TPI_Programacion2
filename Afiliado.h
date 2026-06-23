#pragma once
#include <string>
#include "Persona.h"
#include "Fecha.h"

class Afiliado: public Persona {
  private:
      int _nroDeAfiliado;
      int _idObraSocial;
      char _email[45];
      Fecha _fechaNacimiento;

  public:
    Afiliado();
    Afiliado(int nroAfiliado, int idObra, std::string mail, Fecha fechaNac,
             std::string nombre, std::string apellido, std::string dni, std::string telefono, bool estado);

    void Cargar(int nroAuto);
    void Mostrar();

    int getNroDeAfiliado() const;
    int getIDObraSocial() const;
    void setIdObraSocial(int id);
};
