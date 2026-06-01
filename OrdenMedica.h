#pragma once
#include "Fecha.h"

class OrdenMedica{
private:
     int idOrden, matriculaMedico,tipoOrden,origen;
     char dniPaciente[30];
     Fecha _fecha;
     bool estado;

public:
    void Cargar();
        void Mostrar();

};


class OrdenMedicaArchivo{
};
