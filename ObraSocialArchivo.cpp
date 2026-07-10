#include <iostream>
#include <cstring>
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"

using namespace std;

ObraSocialArchivo::ObraSocialArchivo() {
    strcpy(nombreArchivo, "ObraSocial.dat");
}

bool ObraSocialArchivo::guardar(ObraSocial reg){
    FILE* p= fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(&reg, sizeof(ObraSocial), 1, p);

    fclose(p);
    return escribio;
}

bool ObraSocialArchivo::modificar(ObraSocial reg, int pos){
    FILE* p=fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(ObraSocial), SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(ObraSocial), 1, p);

    fclose(p);
    return escribio;
}

ObraSocial ObraSocialArchivo::leer(int pos){
    ObraSocial reg;
    FILE* p = fopen(nombreArchivo, "rb");// Abrir para lectura
    if(p ==NULL) return reg;

    fseek(p, pos * sizeof(ObraSocial), SEEK_SET);

    fread(&reg, sizeof(ObraSocial), 1, p);

    fclose(p);
    return reg;
}

int ObraSocialArchivo::leerTodos(ObraSocial vObra[], int cantidad){
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    int result = fread(vObra, sizeof(ObraSocial), cantidad, p);

    fclose(p);
    return result;
}

int ObraSocialArchivo::contarRegistros(){
    FILE* p= fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes/ sizeof(ObraSocial);
}

int ObraSocialArchivo::buscar(int idBuscado){
    ObraSocial reg;
    int pos=0;
    FILE* p= fopen(nombreArchivo, "rb");
    if(p == NULL) return -1;

    while(fread(&reg, sizeof(ObraSocial), 1, p)==1){
        if (reg.getId() == idBuscado) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

void ObraSocialArchivo::listarTodo(){
    ObraSocial reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL){
        cout << "No hay registros cargados todavia." << endl;
        return;
    }

    while (fread(&reg, sizeof(ObraSocial), 1, p) == 1) {
        if (reg.getEstado() == true) {
            reg.Mostrar();
            cout << "-------------------------------" << endl;
        }
    }
    fclose(p);
}

void ObraSocialArchivo::crearObrasSocialesPredeterminadas(){
    if (contarRegistros() > 0) return;

    FILE* p = fopen(nombreArchivo, "wb");
    if (p == NULL) return;

    const char* nombresObras[] = {
        "IOMA", "OSDE", "SWISS MEDICAL", "OSECAC", "GALENO",
        "MEDICUS", "SANCOR SALUD", "UNION PERSONAL", "OSEP", "PAMI"
    };

    ObraSocial reg;
    for (int i = 0; i < 10; i++) {
        reg.setIdObraSocial(i + 1);
        reg.setNombre(nombresObras[i]);
        reg.setEstado(true);
        fwrite(&reg, sizeof(ObraSocial), 1, p);
    }
    fclose(p);
}

bool ObraSocialArchivo::obraSocialActiva(int idBuscado) {
    int cantidad = contarRegistros();

    for (int i = 0; i < cantidad; i++) {
        ObraSocial o = leer(i);

        if (o.getId() == idBuscado) {
            return o.getEstado();
        }
    }
    return false;
}
