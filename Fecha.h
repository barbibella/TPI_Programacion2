#pragma once

const int ANIOACTUAL=1900;
const int ANIOFIN=2026;

class Fecha{
    private:
            int dia, mes, anio;

    public:
    Fecha(int dia=0, int mes=0, int anio=0);

    bool validarFecha(int d, int m, int a);
    void Cargar();
    void Mostrar();

    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    int getDia();
    int getMes();
    int getAnio();
};

