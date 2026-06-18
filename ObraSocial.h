#pragma once
#include <string>

class ObraSocial{
    private:
        int idObraSocial;
        char nombre[30];
        bool estado;
    public:
        ObraSocial();
        ObraSocial(int id, std::string nom, bool est);

        void Cargar();
        void Mostrar();

        int getId() const;
        std::string getNombre()const;
        bool getEstado() const;

        void setNombre(std::string n);
        void setIdObraSocial(int id);
        void setEstado(bool e);
};
