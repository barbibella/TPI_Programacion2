#include <iostream>
#include <cstring>
#include "Afiliado.h"
#include "AfiliadoArchivo.h"

using namespace std;

AfiliadoArchivo::AfiliadoArchivo() {
    strcpy(nombreArchivo, "afiliados.dat");
}

bool AfiliadoArchivo::guardar(Afiliado reg){
    FILE* p = fopen(nombreArchivo, "ab");
    if (p == NULL) return false;

    bool escribio = fwrite(&reg, sizeof(Afiliado), 1, p);

    fclose(p);
    return escribio;
}

bool AfiliadoArchivo::modificar(Afiliado reg, int pos){
    FILE* p = fopen(nombreArchivo, "rb+");
    if (p == NULL) return false;

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);
    bool escribio = fwrite(&reg, sizeof(Afiliado), 1, p);

    fclose(p);
    return escribio;
}

Afiliado AfiliadoArchivo::leer(int pos){
    Afiliado reg;
    FILE* p = fopen(nombreArchivo, "rb");
    if(p == NULL) return reg;

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);
    fread(&reg, sizeof(Afiliado), 1, p);

    fclose(p);
    return reg;
}

int AfiliadoArchivo::leerTodos(Afiliado vAfiliado[], int cantidad){
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    int result = fread(vAfiliado, sizeof(Afiliado), cantidad, p);
    fclose(p);
    return result;
}

int AfiliadoArchivo::contarRegistros(){
    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) return 0;

    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);///el paso total del archivo en bytes
    fclose(p);
    return bytes / sizeof(Afiliado);///la cantidad exacta de resgistros guardados
}

int AfiliadoArchivo::buscar(string dniBuscado){
    Afiliado reg;
    int pos = 0;
    FILE* p = fopen(nombreArchivo, "rb");
    if(p == NULL) return -1;

    while(fread(&reg, sizeof(Afiliado), 1, p) == 1){
        // .c_str() para comparar el string con el char[] de Persona
         if(reg.getDni() == dniBuscado){
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
        if (reg.getEstado() == true) {
            reg.Mostrar();
            cout << "-------------------------------" << endl;
        }
    }
    fclose(p);
}

Afiliado AfiliadoArchivo::buscarPorDNI(string dniBuscado) {
    Afiliado reg;
    int pos = buscar(dniBuscado);

    if (pos == -1) {
        reg.setDni("-1");
        return reg;
    }

    FILE* p = fopen(nombreArchivo, "rb");
    if (p == NULL) {
        reg.setDni("-1");
        return reg;
    }

    fseek(p, pos * sizeof(Afiliado), SEEK_SET);
    fread(&reg, sizeof(Afiliado), 1, p);
    fclose(p);

    return reg;
}
