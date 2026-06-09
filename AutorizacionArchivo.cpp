#include <cstring>
#include <iostream>

using namespace std;

#include "AutorizacionArchivo.h"



//////cons


AutorizacionArchivo::AutorizacionArchivo(){
    strcpy(nombreArchivo, "autorizaciones.dat");
}



bool AutorizacionArchivo::guardar(Autorizacion reg){

    FILE* p = fopen(nombreArchivo, "ab");

    if(p == NULL){
return false;
}

    bool escribio = fwrite(&reg, sizeof(Autorizacion), 1, p);

    fclose(p);

    return escribio;
}

bool AutorizacionArchivo::modificar(Autorizacion reg, int pos){

    FILE* p = fopen(nombreArchivo, "rb+");

    if(p == NULL) return false;

    fseek(p, pos * sizeof(Autorizacion), SEEK_SET);

    bool escribio = fwrite(&reg, sizeof(Autorizacion), 1, p);

    fclose(p);

    return escribio;
}

Autorizacion AutorizacionArchivo::leer(int pos){

    Autorizacion reg;

    FILE* p = fopen(nombreArchivo, "rb");

    if(p == NULL) return reg;

    fseek(p, pos * sizeof(Autorizacion), SEEK_SET);

    fread(&reg, sizeof(Autorizacion), 1, p);

    fclose(p);

    return reg;
}






///////////contar reg






///////////// buscar por cod Auto





/////////////////listar todo







