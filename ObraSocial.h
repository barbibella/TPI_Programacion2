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
       // const char* getId() { return id; }
        bool getEstado() { return estado; }
        void setEstado(bool e) { estado = e; }
};
