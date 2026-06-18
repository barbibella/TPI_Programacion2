#pragma once
#include <cstring>

class Persona{
  protected:
    char _nombre[30], _apellido[30];
    char _dni[15], _telefono [20];
// el "_" se utiliza para identificar los atributos con mayor facilidad. - Mai
    bool _estado;

  public:
        Persona();
        Persona(string nombre, string apellido, string dni, string telefono, bool estado);

  //SETTERS - Mai
  void setNombre(string nombre);
  void setApellido (string apellido);
  void setDni (string dni);
  void setTelefono (string telefono);
  void setEstado (bool estado=true);

  //GETTERS - Mai
  string getNombre () const;
  string getApellido () const;
  string getDni () const;
  string getTelefono () const;
  bool getEstado () const;
};
