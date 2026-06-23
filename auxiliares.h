#pragma once
#include <string>
#include "Medico.h"

using namespace std;

int cargarEnteroValidado(string mensaje, int minimo);
int cargarEnteroValidado(string mensaje, int minimo, int maximo);

std::string cargarCadena();
std::string cargarCadenaValidada(string mensaje, int maximo);

void modificarNombre(Medico &reg);
void modificarApellido (Medico &reg);
void modificarDNI (Medico &reg);
void modificarTelefono (Medico &reg);
void modificarMatricula (Medico &reg);
void modificarEspecialidad (Medico &reg);
void modificarTodo (Medico &reg);




/* PENDIENTES.
1)Solucionar errores de clases en especifico, errores de tipeo, etc (para que compile))
2)Agregar  validaciones para los atributos de las clases
3)Realizar InformesManager.cpp .h ( A)cantidad mensual de ordenes autorizadas y rechazadas. b) cantidad de ordenes medicas por tipo
c) cantidad de ordenes emitidas por medico. d) cantidad de ordenes por especialidad medica. e)Obras sociales con mayor cantidad de
afiliados atendidos

*/

