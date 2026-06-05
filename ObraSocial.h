#pragma once

class ObraSocial{
    private:
        int idObraSocial;
        char nombre[30];
        bool estado;
    public:
        void Cargar();
        void Mostrar();

        int getId() { return idObraSocial; }
        void setNombre(const char* n);
        void setIdObraSocial(int id);
        void setEstado(bool e);
        bool getEstado() { return estado; }
};
