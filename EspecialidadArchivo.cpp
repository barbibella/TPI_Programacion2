#include <iostream>
#include <cstring>
#include "Especialidad.h"
#include "EspecialidadArchivo.h"
//--- MAI ---
using namespace std;

EspecialidadArchivo::EspecialidadArchivo(string nombreArchivo)
: _nombreArchivo (nombreArchivo){}

bool EspecialidadArchivo::crear (const Especialidad &reg){
FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return result;
    }

bool EspecialidadArchivo::actualizar (int pos, const Especialidad &reg){
FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if (pFile == nullptr){
        return false;
    }
    fseek(pFile, pos*sizeof(Especialidad), SEEK_SET);   //MAI - pone el puntero en la posicion que recibe multiplicado por los bytes que pesa el objeto medico.
    result = fwrite(&reg, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return result;

}

Especialidad EspecialidadArchivo::leer(int pos){
FILE *pFile;
    Especialidad reg;

    reg.setIdEspecialidad(-1);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return reg;
    }
    //abre el archivo, obtiene cuanto pesa cada objeto especialidad y
    //lo multiplica por posicion. SEEK_SET dice donde coloca el puntero, seria
    //al principio.
    fseek(pFile, pos*sizeof(Especialidad), SEEK_SET);
    //lee y determina el tamaño de cada objeto que lee.
    fread(&reg, sizeof(Especialidad), 1, pFile);

    fclose(pFile);

    return reg;
}

int EspecialidadArchivo::leerTodos(Especialidad vEspecialidad[], int cantidad){
FILE *pFile;
    int result;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return 0;
    }

    result = fread(vEspecialidad, sizeof(Especialidad), cantidad, pFile);

    fclose(pFile);

    return result;
}

int EspecialidadArchivo::getCantidadRegistros(){
FILE *pFile;
    int cant;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cant = ftell(pFile) / sizeof(Especialidad); //Mai - obtiene cant bytes del archivo y lo divide por lo que pesa obj Medico. Te dice la cant de registros que tenés

    fclose(pFile);

    return cant;
}

int EspecialidadArchivo::buscarIdEspecialidad(int especialidad){
FILE *pFile;
    Especialidad reg;
    int result = -1, pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return -1;
    }

    while (fread(&reg, sizeof(Especialidad), 1, pFile)){
        if (reg.getIdEspecialidad() == especialidad){
            result = pos;
            break;
        }

        pos++;
    }

    fclose(pFile);

    return result;
}

bool EspecialidadArchivo::existeEspecialidad(int especialidad){
FILE *pFile;
    Especialidad reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return false;
    }

    while(fread(&reg, sizeof(Especialidad), 1, pFile)){
        if(reg.getIdEspecialidad() == especialidad){
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);

    return false;

}

//Metodo ID Incremental: Devuelve un nuevo nro incremental al crear un nuevo ID Especialidad
int EspecialidadArchivo::getNuevoId(){
    return getCantidadRegistros() + 1;
}
