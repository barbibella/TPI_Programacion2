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

    void setDia(int d){
        if(d>=1 && d<=31) {
            dia=d;
        }
        else{
            dia=0;
        }
    }
    void setMes(int m){
        if(m>0 && m<=12){
                mes=m;
        }
        else{
            m=0;
        }
    }
    void setAnio(int a){
        if(a>=ANIOACTUAL && a<=ANIOFIN){
                anio=a;
        }
    }

    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}
};

