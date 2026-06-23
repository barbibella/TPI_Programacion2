#pragma once

class OrdenMedicaManager{
    private:
        bool existeId(int id);
        int generarId();

    public:
        void menu();

        // Submenus
        void menuListados();
        void menuConsultas();

        // ABM
        void agregar();
        void modificar();
        void eliminar();
        void reactivar();

        // Listados
        void listarTodos();
        void listarActivos();
        void listarInactivos();
        void listarPorFecha();
        void listarPorTipoOrden();
        void listarPorOrigen();

        // Busquedas y consultas
        void buscaPorID();
        void consultarPorDni();
        void consultarPorMedico();
        void consultarPorFecha();
        void consultarPorTipoOrden();
};


