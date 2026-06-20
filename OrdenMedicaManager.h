#pragma once

class OrdenMedicaManager{
    private:
        bool existeId(int id);
        int generarId();

    public:
        void menu();
        void agregar();
        void listarTodos();
        void buscaPorID();
        void eliminar();
        void reactivar();
};


