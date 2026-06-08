#pragma once

class ObraSocial{
    private:
        int idObraSocial;
        char nombre[30];
        bool estado;
    public:
        void Cargar();
        void Mostrar();

        int getId();
        void setNombre(const char* n);
        void setIdObraSocial(int id);
        void setEstado(bool e);
        bool getEstado();
};
