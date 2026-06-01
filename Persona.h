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

    const char* getDni() { return dni; }
    void setDni(const char* d) { strcpy(dni, d); }
    bool getEstado() { return estado; }
    void setEstado(bool e) { estado = e; }
};
