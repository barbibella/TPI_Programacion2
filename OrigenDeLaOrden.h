#pragma once

#include <string>

class OrigenDeLaOrden {
private:
    int _idOrigen;
    char _descripcion[30];
    bool _estado;

public:
    OrigenDeLaOrden();
    OrigenDeLaOrden(int idOrigen, std::string descripcion, bool estado);

    int getIdOrigen();
    std::string getDescripcion();
    bool getEstado();

    void setIdOrigen(int idOrigen);
    void setDescripcion(std::string descripcion);
    void setEstado(bool estado);

    void cargar();
    void mostrar();
};
