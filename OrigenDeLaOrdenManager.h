#pragma once

class OrigenDeLaOrdenManager{
    private:
        bool existeId(int id);
        int generarId();

    public:
        void menu();
        void agregar();
        void listarTodos();
        void listarActivos();
        void listarInactivos();
        void buscaPorID();
        void modificar();
        void eliminar();
        void reactivar();
};
