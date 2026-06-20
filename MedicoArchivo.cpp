#include <iostream>
#include <cstring>
#include "Medico.h"
#include "MedicoArchivo.h"
//--- MAI ---
using namespace std;

MedicoArchivo::MedicoArchivo(string nombreArchivo)
: _nombreArchivo (nombreArchivo){}

bool MedicoArchivo::crear (const Medico &reg){
FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "ab");

    if (pFile == nullptr){
        return false;
    }

    result = fwrite(&reg, sizeof(Medico), 1, pFile);

    fclose(pFile);

    return result;
    }

bool MedicoArchivo::actualizar (int pos, const Medico &reg){
FILE *pFile;
    bool result;

    pFile = fopen(_nombreArchivo.c_str(), "rb+");

    if (pFile == nullptr){
        return false;
    }
    fseek(pFile, pos*sizeof(Medico), SEEK_SET);   //MAI - pone el puntero en la posicion que recibe multiplicado por los bytes que pesa el objeto medico.
    result = fwrite(&reg, sizeof(Medico), 1, pFile);

    fclose(pFile);

    return result;

}

Medico MedicoArchivo::leer(int pos){
FILE *pFile;
    Medico reg;

    reg.setMatricula(-1);

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return reg;
    }

    fseek(pFile, pos*sizeof(Medico), SEEK_SET);

    fread(&reg, sizeof(Medico), 1, pFile);

    fclose(pFile);

    return reg;
}

int MedicoArchivo::leerTodos(Medico vMedico[], int cantidad){
FILE *pFile;
    int result;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return 0;
    }

    result = fread(vMedico, sizeof(Medico), cantidad, pFile);

    fclose(pFile);

    return result;
}

int MedicoArchivo::getCantidadRegistros(){
FILE *pFile;
    int cant;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    cant = ftell(pFile) / sizeof(Medico); //Mai - obtiene cant bytes del archivo y lo divide por lo que pesa obj Medico. Te dice la cant de registros que tenés

    fclose(pFile);

    return cant;
}

int MedicoArchivo::buscarMatricula(int matricula){
FILE *pFile;
    Medico reg;
    int result = -1, pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return -1;
    }

    while (fread(&reg, sizeof(Medico), 1, pFile)){
        if (reg.getMatricula() == matricula){
            result = pos;
            break;
        }

        pos++;
    }

    fclose(pFile);

    return result;
}

bool MedicoArchivo::existeMatricula(int matricula){
FILE *pFile;
    Medico reg;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if(pFile == nullptr){
        return false;
    }

    while(fread(&reg, sizeof(Medico), 1, pFile)){
        if(reg.getMatricula() == matricula){
            fclose(pFile);
            return true;
        }
    }

    fclose(pFile);

    return false;

}

int MedicoArchivo::buscarDni(std::string dni){
    FILE *pFile;
    Medico reg;
    int result = -1, pos = 0;

    pFile = fopen(_nombreArchivo.c_str(), "rb");

    if (pFile == nullptr){
        return -1;
    }

    while (fread(&reg, sizeof(Medico), 1, pFile)){
        if (reg.getDni() == dni){
            result = pos;
            break;
        }

        pos++;
    }

    fclose(pFile);

    return result;
}
