#pragma once
#include "fecha.h"


class Autorizacion {

private:

    int idOrden;
    int codAutorizacion;
    Fecha fechaAutorizacion;
    float porcentajeCobertura;
    bool aprobada;
    char observaciones[100];
    bool _estado;

public:
    Autorizacion();
    int getIdOrden();
    int getCodAutorizacion();
    Fecha getFechaAutorizacion();
    float getPorcentajeCobertura();
    bool getAprobada();
    const char* getObservaciones();
    bool getEstado();
    void setIdOrden(int id);
    void setCodAutorizacion(int cod);
    void setFechaAutorizacion(Fecha fecha);
    void setPorcentajeCobertura(float porcentaje);
    void setAprobada(bool estado);
    void setObservaciones(const char* obs);
    void setEstado(bool estado);
    void Mostrar();
    void Cargar();













};
