#include <iostream>
#include <cstring>
#include "TipoDeOrden.h"
#include "TipoDeOrdenArchivo.h"

using namespace std;

TipoDeOrdenArchivo::TipoDeOrdenArchivo() {
    strcpy(nombreArchivo, "tipoDeOrden.dat");
}

bool TipoDeOrdenArchivo::guardar(TipoDeOrden registro){
    FILE* pFile;

    pFile = fopen("tipoDeOrden.dat", "ab");

    if (pFile == nullptr){
        return false;
    }

    bool escribio = fwrite(&registro, sizeof(TipoDeOrden), 1, pFile);

    fclose(pFile);

    return escribio;
}

bool TipoDeOrdenArchivo::modificar(TipoDeOrden registro,int pos){
    FILE* pFile;

    pFile = fopen("tipoDeOrden.dat", "rb+");

    if (pFile == nullptr){
        return false;
    }

    fseek(pFile, pos * sizeof(TipoDeOrden), SEEK_SET);

    bool escribio = fwrite(&registro, sizeof(TipoDeOrden), 1, pFile);
    fclose(pFile);
    return escribio;
}

TipoDeOrden TipoDeOrdenArchivo::leer(int pos){
    TipoDeOrden registro;

    FILE* pFile;

    pFile = fopen("tipoDeOrden.dat", "rb");

    if(pFile == nullptr){
        return registro;
    }

    fseek(pFile, pos * sizeof(TipoDeOrden), SEEK_SET);

    fread(&registro, sizeof(TipoDeOrden), 1, pFile);

    fclose(pFile);

    return registro;
}

int TipoDeOrdenArchivo::contarRegistros(){
    FILE* pFile;

    pFile = fopen("tipoDeOrden.dat", "rb");

    fseek(pFile, 0, SEEK_END);

    int bytes = ftell(pFile) / sizeof(TipoDeOrden);

    fclose(pFile);

    return bytes;
}

int TipoDeOrdenArchivo::buscarId(int idTipoDeOrden){
    TipoDeOrden registro;
    int pos=0;
    FILE* pFile;
    pFile = fopen("tipoDeOrden.dat", "rb");

    if(pFile == nullptr){
        return 0;
    }

    while(fread(&registro, sizeof(TipoDeOrden), 1, pFile)==1){
        if(registro.getIdTipoOrden() == idTipoDeOrden){
            fclose(pFile);
        return pos;
        }
        pos++;
    }
    fclose(pFile);
    return 0;
}
