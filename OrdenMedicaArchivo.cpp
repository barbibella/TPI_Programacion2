#include <iostream>
#include <cstring>
#include "OrdenMedica.h"
#include "OrdenMedicaArchivo.h"

using namespace std;

OrdenMedicaArchivo::OrdenMedicaArchivo() {
    strcpy(nombreArchivo, "ordenMedica.dat");
}

bool OrdenMedicaArchivo::guardar(OrdenMedica registro){
    FILE* pFile;

    pFile = fopen("ordenMedica.dat", "ab");

    if (pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&registro, sizeof(OrdenMedica), 1, pFile);

    fclose(pFile);

    return escribio;
}

bool OrdenMedicaArchivo::modificar(OrdenMedica registro,int pos){
    FILE* pFile;

    pFile = fopen("ordenMedica.dat", "rb+");

    if (pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(OrdenMedica), SEEK_SET);

    bool escribio = fwrite(&registro, sizeof(OrdenMedica), 1, pFile);
    fclose(pFile);
    return escribio;
}

OrdenMedica OrdenMedicaArchivo::leer(int pos){
    OrdenMedica registro;

    FILE* pFile;

    pFile = fopen("ordenMedica.dat", "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, pos * sizeof(OrdenMedica), SEEK_SET);

    fread(&registro, sizeof(OrdenMedica), 1, pFile);

    fclose(pFile);

    return registro;
}

int OrdenMedicaArchivo::contarRegistros(){
    FILE* pFile;
    pFile = fopen("ordenMedica.dat", "rb");

    if(pFile == nullptr){
        return -1;
    }

    fseek(pFile, 0, SEEK_END);

    int cantidad = ftell(pFile) / sizeof(OrdenMedica);

    fclose(pFile);

    return cantidad;
}

int OrdenMedicaArchivo::buscarId(int idOrden){
    OrdenMedica registro;
    int pos=0;

    FILE* pFile;
    pFile = fopen("ordenMedica.dat", "rb");

    if(pFile == nullptr){
        return -1;
    }

    while(fread(&registro, sizeof(OrdenMedica), 1, pFile)==1){
        if(registro.getIdOrden() == idOrden){
            fclose(pFile);
        return pos;
        }
        pos++;
    }

    fclose(pFile);
    return 0;
}
