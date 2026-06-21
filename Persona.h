#pragma once
#include <string>

class Persona {
  protected:
    char _nombre[30], _apellido[30];
    char _dni[15], _telefono[20];
    bool _estado;

  public:
    Persona();
    Persona(std::string nombre, std::string apellido, std::string dni, std::string telefono, bool estado);

    // SETTERS
    void setNombre(std::string nombre);
    void setApellido(std::string apellido);
    void setDni(std::string dni);
    void setTelefono(std::string telefono);
    void setEstado(bool estado = true);

    // GETTERS
    std::string getNombre() const;
    std::string getApellido() const;
    std::string getDni() const;
    std::string getTelefono() const;
    bool getEstado() const;
};

