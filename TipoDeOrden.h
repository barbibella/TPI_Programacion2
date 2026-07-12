#pragma once

class TipoDeOrden {
private:
    int _idTipoOrden;
    char _descripcion[40];
    bool _estado;

public:
    TipoDeOrden();
    TipoDeOrden(int idTipoOrden, std::string descripcion, bool estado);

    int getIdTipoOrden();
    std::string getDescripcion();
    bool getEstado();

    void setIdTipoOrden(int idTipoOrden);
    void setDescripcion(std::string descripcion);
    void setEstado(bool estado);

    void cargar();
    void mostrar();
};
