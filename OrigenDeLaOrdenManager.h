#pragma once

class OrigenDeLaOrdenManager{
    private:
        bool existeId(int id);
        int generarId();

    public:
        void menu();
        void agregar();
        void listarTodos();
        void buscaPorID();
        void eliminar();
};
