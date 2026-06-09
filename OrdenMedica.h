#pragma once
#include "Fecha.h"

#include <string>

class OrdenMedica{
private:
    int _idOrden;
    char _dniPaciente[30];
    int _matriculaMedico;
    Fecha _fechaOrden;
    int _tipoOrden;
    int _origen;
    bool _estado;

public:
    OrdenMedica();
    OrdenMedica(int idOrden, std::string dniPaciente, int matriculaMedico, Fecha fechaOrden, int tipoOrden, int origen, bool estado);

    int getIdOrden();
    std::string getDniPaciente();
    int getMatriculaMedico();
    Fecha getFechaOrden();
    int getTipoOrden();
    int getOrigen();
    bool getEstado();

    void setIdOrden (int idOrden);
    void setDniPaciente(std::string dniPaciente);
    void setMatriculaMedico(int matriculaMedico);
    void setFechaOrden(Fecha fechaOrden);
    void setTipoOrden(int tipoOrden);
    void setOrigen(int origen);
    void setEstado(bool estado);

    void cargar();
    void mostrar();
};
