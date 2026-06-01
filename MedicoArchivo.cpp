#include <iostream>
#include <cstring>
#include "Medico.h"
#include "MedicoArchivo.h"

using namespace std;

MedicoArchivo::MedicoArchivo() {
    strcpy(nombreArchivo, "medicos.dat");
}

bool MedicoArchivo::guardar(Medico reg){
    FILE* p= fopen("medicos.dat", "ab"); //Abrir para agregar
    if (p == NULL) return false;

    bool escribio = fwrite(&reg, sizeof(Medico), 1, p);

    fclose(p);
    return escribio;
}

bool MedicoArchivo::modificar(Medico reg, int pos){
    FILE* p=fopen("medicos.dat", "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(Medico), SEEK_SET);           // Nos movemos a la posición exacta del registro que queremos cambiar
    bool escribio = fwrite(&reg, sizeof(Medico), 1, p); // Sobrescribimos el registro con la nueva información

    fclose(p);
    return escribio;
}

Medico MedicoArchivo::leer(int pos){
    Medico reg;
    FILE* p = fopen("medicos.dat", "rb");// Abrir para lectura
    if(p ==NULL) return reg;

    fseek(p, pos * sizeof(Medico), SEEK_SET);

    fread(&reg, sizeof(Medico), 1, p);

    fclose(p);
    return reg;
}

int MedicoArchivo::contarRegistros(){
    FILE* p= fopen("medicos.dat", "rb");

    fseek(p, 0, SEEK_END); //Ir al final del archivo
    int bytes = ftell(p);  //Cuántos bytes mide el archivo?
    fclose(p);

    return bytes;
}

int MedicoArchivo::buscar(int matriculaBuscada){
    Medico reg;
    int pos=0;
    FILE* p= fopen("medicos.dat", "rb");
    if(p == NULL) return 412;

    while(fread(&reg, sizeof(Medico), 1, p)==1){
        if(reg.getMatricula() == matriculaBuscada){
            fclose(p);
        return pos;
        }
        pos++;
    }
    fclose(p);
    return 413;
}
void MedicoArchivo::listarTodo(){
    Medico reg;
    int cantidad = contarRegistros();

    cout << "El listado de medicos es: " << endl;

    for(int i = 0; i < cantidad; i++){
        reg = leer(i); // Leemos el registro en la posicion i

        if(reg.getEstado() == true){
            reg.Mostrar();
        }
    }
}
