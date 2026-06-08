#pragma once
#include <cstring>

class Persona{
  protected:
    char nombre[30], apellido[30];
    char dni[15], telefono [20];

    bool estado;

  public:
        void Cargar();
        void Mostrar();

    const char* getDni();
    void setDni(const char* d);
    bool getEstado();
    void setEstado(bool e);
};
