/**#pragma once

class ConfiguracionManager{
    public:
        void Menu();
    private:
        void MenuBackup();
    void MenuRestaurar();
    void MenuExportarCSV();

    // Métodos logicos para Backups
    void realizarBackup(int tipoArchivo);
    void restaurarBackup(int tipoArchivo);

    // Métodos logicos para Exportacion
    void exportarAfiliados();
    void exportarMedicos();
    void exportarObrasSociales();
};
*/
