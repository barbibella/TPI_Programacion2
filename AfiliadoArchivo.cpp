#include <iostream>
#include <cstring>
#include "Afiliado.h"
#include "AfiliadoArchivo.h"

using namespace std;

AfiliadoArchivo::AfiliadoArchivo() {
    strcpy(nombreArchivo, "afiliados.dat");// Aca le asignamos el nombre fisico al archivo
}

bool AfiliadoArchivo::guardar(Afiliado reg){
    FILE* p= fopen("afiliados.dat", "ab"); //Abrir para agregar
    if (p == NULL) return false;

    bool escribio = fwrite(&reg, sizeof(Afiliado), 1, p);

    fclose(p);
    return escribio;
}

bool AfiliadoArchivo::modificar(Afiliado reg, int pos){
    FILE* p=fopen("afiliados.dat", "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);           // Nos movemos a la posicion exacta del registro que queremos cambiar
    bool escribio = fwrite(&reg, sizeof(Afiliado), 1, p); // Sobrescribimos el registro con la nueva informacion

    fclose(p);
    return escribio;
}

Afiliado AfiliadoArchivo::leer(int pos){
    Afiliado reg;
    FILE* p = fopen("afiliados.dat", "rb");// Abrir para lectura
    if(p ==NULL) return reg;

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);

    fread(&reg, sizeof(Afiliado), 1, p);

    fclose(p);
    return reg;
}

int AfiliadoArchivo::contarRegistros(){
    FILE* p= fopen("afiliados.dat", "rb");
    if (p == NULL) return 0;
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes  / sizeof(Afiliado);
}

int AfiliadoArchivo::buscar(const char* dniBuscado){
    Afiliado reg;
    int pos=0;
    FILE* p= fopen("afiliados.dat", "rb");
    if(p == NULL) return -1;

    while(fread(&reg, sizeof(Afiliado), 1, p)==1){
        if(strcmp(reg.getDni(), dniBuscado) == 0){ // strcmp devuelve 0 si las cadenas son iguales
            fclose(p);
        return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

void AfiliadoArchivo::listarTodo(){
    Afiliado reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        cout << "No hay registros cargados todavia" << endl;
        return;
    }

    while (fread(&reg, sizeof(Afiliado), 1, p) == 1) {
        // Solo mostramos si el registro es "valido"
        if (reg.getEstado() == true) {
            reg.Mostrar();
            cout << "-------------------------------" << endl;
        }
    }
    fclose(p);
}

Afiliado AfiliadoArchivo::buscarPorDNI(const char* dniBuscado) {
    Afiliado reg;
    int pos = buscar(dniBuscado);

    if (pos == -1 || pos == -1) {
        reg.setDni("-1");
        return reg;
    }

    FILE* p = fopen("afiliados.dat", "rb");
    if (p == NULL) {
        reg.setDni("-1");
        return reg;
    }

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);
    fread(&reg, sizeof(Afiliado), 1, p);
    fclose(p);

    return reg;
}
