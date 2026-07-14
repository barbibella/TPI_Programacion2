#pragma once
#include <string>


using namespace std;

int cargarEnteroValidado(string mensaje, int minimo);
int cargarEnteroValidado(string mensaje, int minimo, int maximo);

std::string cargarCadena();
std::string cargarCadenaValidada(string mensaje, int maximo);
std::string aMinusculas(string texto);///funcion pasa a texto solo para hacer comparaciones





/* PENDIENTES.

3)Realizar InformesManager .cpp y .h
  A)cantidad mensual de ordenes autorizadas y rechazadas.
  b) cantidad de ordenes medicas por tipo
  c) cantidad de ordenes emitidas por medico.
  d) cantidad de ordenes por especialidad medica.
  e)Obras sociales con mayor cantidad de afiliados atendidos

*/

