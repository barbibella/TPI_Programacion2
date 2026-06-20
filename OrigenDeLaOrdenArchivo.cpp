#include <iostream>
#include <cstring>
#include "OrigenDeLaOrden.h"
#include "OrigenDeLaOrdenArchivo.h"

using namespace std;

OrigenDeLaOrdenArchivo::OrigenDeLaOrdenArchivo() {
    strcpy(nombreArchivo, "origenDeLaOrden.dat");
}

bool OrigenDeLaOrdenArchivo::guardar(OrigenDeLaOrden registro){
    FILE* pFile;

    pFile = fopen("origenDeLaOrden.dat", "ab");

    if (pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&registro, sizeof(OrigenDeLaOrden), 1, pFile);

    fclose(pFile);

    return escribio;
}

bool OrigenDeLaOrdenArchivo::modificar(OrigenDeLaOrden registro,int pos){
    FILE* pFile;

    pFile = fopen("origenDeLaOrden.dat", "rb+");

    if (pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(OrigenDeLaOrden), SEEK_SET);

    bool escribio = fwrite(&registro, sizeof(OrigenDeLaOrden), 1, pFile);
    fclose(pFile);
    return escribio;
}

OrigenDeLaOrden OrigenDeLaOrdenArchivo::leer(int pos){
    OrigenDeLaOrden registro;

    FILE* pFile;

    pFile = fopen("origenDeLaOrden.dat", "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, pos * sizeof(OrigenDeLaOrden), SEEK_SET);

    fread(&registro, sizeof(OrigenDeLaOrden), 1, pFile);

    fclose(pFile);

    return registro;
}

int OrigenDeLaOrdenArchivo::contarRegistros(){
    FILE* pFile;

    pFile = fopen("origenDeLaOrden.dat", "rb");

    fseek(pFile, 0, SEEK_END);

    int bytes = ftell(pFile) / sizeof(OrigenDeLaOrden);

    fclose(pFile);

    return bytes;
}

int OrigenDeLaOrdenArchivo::buscarId(int idOrigen){
    OrigenDeLaOrden registro;
    int pos=0;
    FILE* pFile;
    pFile = fopen("origenDeLaOrden.dat", "rb");

    if(pFile == nullptr){
        return -1;
    }

    while(fread(&registro, sizeof(OrigenDeLaOrden), 1, pFile)==1){
        if(registro.getIdOrigen() == idOrigen){
            fclose(pFile);
        return pos;
        }
        pos++;
    }
    fclose(pFile);
    return -1;
}
