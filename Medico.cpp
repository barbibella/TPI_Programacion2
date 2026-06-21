#include <iostream>
#include "Medico.h"

using namespace std;
//MAI
//CONSTRUCTOR - MAI
Medico::Medico()
:  _matricula(-1), _especialidad(-1), Persona(){}

Medico::Medico(int matricula, int especialidad, string nombre, string apellido, string dni, string telefono, bool estado)
: Persona(nombre, apellido, dni, telefono, estado){
    setMatricula(matricula);
    setEspecialidad(especialidad);

}

//SETTERS - MAI
void Medico::setMatricula(int matricula){
    if (matricula>0) {
            _matricula=matricula;
    }
    else { _matricula= -1 ;
    }
}

void Medico::setEspecialidad(int especialidad){
  if (especialidad>0) {
            _especialidad=especialidad;
    }
    else { _especialidad= -1 ;
    }
}

//GETTERS - MAI
int Medico::getMatricula () const{return _matricula;}
int Medico::getEspecialidad () const{ return _especialidad;}


/* ===< ESPECIALIDADES >===
1 - Medicina clinica
2 - Pediatria
3 - Traumatologia
4 - Oftalmologia
5 - Cirugia
6 - Neumonologia
7 - Cardiologia
8 - Neurologia
9 - Gastroenterologia
10- Ginecologia
*/
