#include <iostream>
#include <cstring>
#include "ObraSocial.h"
#include "ObraSocialArchivo.h"
#include "ObraSocialManager.h"

using namespace std;

ObraSocialArchivo::ObraSocialArchivo() {
    strcpy(nombreArchivo, "ObraSocial.dat");// Aca le asignamos el nombre físico al archivo
}

bool ObraSocialArchivo::guardar(ObraSocial reg){
    FILE* p= fopen("ObraSocial.dat", "ab"); //Abrir para agregar
    if (p == NULL) return false;

    bool escribio = fwrite(&reg, sizeof(ObraSocial), 1, p);

    fclose(p);
    return escribio;
}

bool ObraSocialArchivo::modificar(ObraSocial reg, int pos){
    FILE* p=fopen("ObraSocial.dat", "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(ObraSocial), SEEK_SET);           // Nos movemos a la posicion exacta del registro que queremos cambiar
    bool escribio = fwrite(&reg, sizeof(ObraSocial), 1, p); // Sobrescribimos el registro con la nueva información

    fclose(p);
    return escribio;
}

ObraSocial ObraSocialArchivo::leer(int pos){
    ObraSocial reg;
    FILE* p = fopen("ObraSocial.dat", "rb");// Abrir para lectura
    if(p ==NULL) return reg;

    fseek(p, pos * sizeof(ObraSocial), SEEK_SET);

    fread(&reg, sizeof(ObraSocial), 1, p);

    fclose(p);
    return reg;
}

int ObraSocialArchivo::contarRegistros(){
    FILE* p= fopen("ObraSocial.dat", "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END); //Ir al final del archivo
    int bytes = ftell(p);  //Cuantos bytes mide el archivo?
    fclose(p);             // ftell te dice en que bytes esta el cursor

    return bytes/ sizeof(ObraSocial);
}

int ObraSocialArchivo::buscar(int idBuscado){
    ObraSocial reg;
    int pos=0;
    FILE* p= fopen("ObraSocial.dat", "rb");
    if(p == NULL) return 412;

    while(fread(&reg, sizeof(ObraSocial), 1, p)==1){
        if (reg.getId() == idBuscado) {
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return 413;
}

void ObraSocialArchivo::listarTodo(){
    ObraSocial reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        cout << "No hay registros cargados todavia." << endl;
        return;
    }

    while (fread(&reg, sizeof(ObraSocial), 1, p) == 1) {
        // Solo mostramos si el registro es "valido"
        if (reg.getEstado() == true) {
            reg.Mostrar();
            cout << "-------------------------------" << endl;
        }
    }
    fclose(p);
}
