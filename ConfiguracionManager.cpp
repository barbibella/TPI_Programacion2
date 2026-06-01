/**#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "ConfiguracionManager.h"
#include "ObraSocialArchivo.h"
#include "MedicoArchivo.h"
#include "AfiliadoArchivo.h"

using namespace std;

/**
EN MENU PRINCIPAL DEBEMOS DE AGREGAR
case 5: // (O el numero de caso que corresponda a Configuracion)
    ConfiguracionManager configManager;
    configManager.Menu();
    break;


void ConfiguracionManager::Menu() {
    int opcion;
    do {
        system("cls");
        cout << " MENU CONFIGURACION" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 1 - REALIZAR COPIA DE SEGURIDAD (BACKUP)" << endl;
        cout << " 2 - RESTAURAR COPIA DE SEGURIDAD" << endl;
        cout << " 3 - EXPORTAR DATOS A TEXTO (CSV)" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 0 - VOLVER AL MENU PRINCIPAL" << endl;
        cout << endl;
        cout << " OPCION: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:MenuBackup();
                break;
            case 2:MenuRestaurar();
                break;
            case 3:MenuExportarCSV();
                break;
            case 0:
                break;
            default:
                cout << "Opcion incorrecta. Intente de nuevo." << endl;
                system("pause");
                break;
        }
    } while(opcion != 0);
}

// -------------------------------------------------------------------------
// SUBMENÚ: REALIZAR COPIA DE SEGURIDAD
// -------------------------------------------------------------------------
void ConfiguracionManager::MenuBackup() {
    int opcion;
    system("cls");
    cout << " REALIZAR COPIA DE SEGURIDAD" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 1 - AFILIADOS" << endl;
    cout << " 2 - MEDICOS" << endl;
    cout << " 3 - OBRAS SOCIALES" << endl;
    cout << " 7 - TODOS LOS ARCHIVOS" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 0 - VOLVER" << endl;
    cout << endl;
    cout << " OPCION: ";
    cin >> opcion;
    cin.ignore();

    if (opcion >= 1 && opcion <= 3) {
        realizarBackup(opcion);
    } else if (opcion == 7) {
        realizarBackup(1);
        realizarBackup(2);
        realizarBackup(3);
        cout << "Resguardo completado con exito." << endl;
        system("pause");
    }
}

// -------------------------------------------------------------------------
// SUBMENÚ: RESTAURAR COPIA DE SEGURIDAD (Con código de confirmación)
// -------------------------------------------------------------------------
void ConfiguracionManager::MenuRestaurar() {
    int opcion;
    system("cls");
    cout << " RESTAURAR COPIA DE SEGURIDAD" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 1 - AFILIADOS" << endl;
    cout << " 2 - MEDICOS" << endl;
    cout << " 3 - OBRAS SOCIALES" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 0 - VOLVER" << endl;
    cout << endl;
    cout << " OPCION: ";
    cin >> opcion;
    cin.ignore();

    if (opcion >= 1 && opcion <= 3) {
        srand(time(0));
        int codigoGenerado = rand() % 90000 + 10000;
        int codigoUsuario;

        cout << "ADVERTENCIA! Se sobreescribiran los datos activos." << endl;
        cout << "Para confirmar ingrese el siguiente codigo: " << codigoGenerado << endl;
        cout << "CODIGO: ";
        cin >> codigoUsuario;
        cin.ignore();

        if (codigoUsuario == codigoGenerado) {
            restaurarBackup(opcion);
        } else {
            cout << "Codigo incorrecto. Restauracion cancelada." << endl;
            system("pause");
        }
    }
}

// -------------------------------------------------------------------------
// LÓGICA DE BACKUPS (Copiar binarios de una carpeta a otra)
// -------------------------------------------------------------------------
void ConfiguracionManager::realizarBackup(int tipoArchivo) {
    string origen, destino;

    // Identificamos las rutas según la opción
    if (tipoArchivo == 1) { origen = "datos/Afiliado.dat"; destino = "backups/Afiliado.bkp"; }
    if (tipoArchivo == 2) { origen = "datos/Medico.dat"; destino = "backups/Medico.bkp"; }
    if (tipoArchivo == 3) { origen = "datos/ObraSocial.dat"; destino = "backups/ObraSocial.bkp"; }

    // Truco clásico de C++ para copiar un archivo binario completo:
    ifstream src(origen, ios::binary);
    ofstream dst(destino, ios::binary);

    if (src.good() && dst.good()) {
        dst << src.rdbuf(); // Copia todo el búfer de un viaje
        cout << "Backup generado con exito para: " << origen << endl;
    } else {
        cout << "No se pudo realizar el backup. Verifique las carpetas 'datos' y 'backups'." << endl;
    }
    src.close();
    dst.close();
    system("pause");
}

void ConfiguracionManager::restaurarBackup(int tipoArchivo) {
    string origen, destino;
    if (tipoArchivo == 1) { origen = "backups/Afiliado.bkp"; destino = "datos/Afiliado.dat"; }
    if (tipoArchivo == 2) { origen = "backups/Medico.bkp"; destino = "datos/Medico.dat"; }
    if (tipoArchivo == 3) { origen = "backups/ObraSocial.bkp"; destino = "datos/ObraSocial.dat"; }

    ifstream src(origen, ios::binary);
    ofstream dst(destino, ios::binary);

    if (src.good() && dst.good()) {
        dst << src.rdbuf();
        cout << "Base de datos restaurada desde el archivo de respaldo." << endl;
    } else {
        cout << "No se encontro el archivo de copia .bkp correspondiente." << endl;
    }
    src.close();
    dst.close();
    system("pause");
}

// -------------------------------------------------------------------------
// SUBMENÚ: EXPORTACIÓN A TEXTO PLANO (CSV)
// -------------------------------------------------------------------------
void ConfiguracionManager::MenuExportarCSV() {
    int opcion;
    system("cls");
    cout << " EXPORTAR ARCHIVOS CSV" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 1 - OBRAS SOCIALES" << endl;
    cout << " 2 - AFILIADOS (Completar luego)" << endl;
    cout << "----------------------------------------" << endl;
    cout << " 0 - VOLVER" << endl;
    cout << endl;
    cout << " OPCION: ";
    cin >> opcion;
    cin.ignore();

    switch(opcion) {
        case 1:
            exportarObrasSociales();
            break;
        case 2:
            // Aquí llamarían a exportarAfiliados(); cuando lo tengan desarrollado
            break;
    }
}

// -------------------------------------------------------------------------
// LÓGICA DE EXPORTACIÓN A CSV (Transformar Binario a Texto separado por comas)
// -------------------------------------------------------------------------
void ConfiguracionManager::exportarObrasSociales() {
    // Abrimos el binario original para leer registros
    FILE* p = fopen("datos/ObraSocial.dat", "rb");
    if (p == NULL) {
        cout << "\n[ERROR] No se pudo leer el archivo binario ObraSocial.dat" << endl;
        system("pause");
        return;
    }

    // Creamos el archivo de salida .csv usando ofstream
    ofstream archivoCSV("obrassociales.csv");

    // 1. Grabamos la fila de títulos (Cabecera)
    archivoCSV << "idObraSocial,nombre,estado\n";

    // Reemplazar por tu estructura/clase real de ObraSocial:
    // ObraSocial reg;
    // while(fread(&reg, sizeof(ObraSocial), 1, p) == 1) {
    //     // 2. Volcamos las propiedades separadas por comas
    //     archivoCSV << reg.getIdObraSocial() << ","
    //                << reg.getNombre() << ","
    //                << reg.getEstado() << "\n";
    // }

    fclose(p);
    archivoCSV.close();
    cout << "\n[OK] Archivo 'obrassociales.csv' generado correctamente." << endl;
    system("pause");
}
*/
