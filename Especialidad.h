#pragma once
#include <cstring>

using namespace std;

//CONSTRUCTOR - MAI
class Especialidad {
private:
		int _idEspecialidad;
		char _nombreEspecialidad[25];
		char _descripcionEspecialidad[50];
		int _idFormacion;
		int _estado;

	public:
		Especialidad();
		Especialidad(int idEspecialidad, int idFormacion, string nombreEspecialidad, string descripcionEspecialidad, int estado);


//SETTERS - MAI
	void setIdEspecialidad(int idEspecialidad);
	void setNombreEspecialidad(string nombreEspecialidad);
	void setDescripcionEspecialidad(string descripcionEspecialidad);
	void setIdFormacion(int idFormacion);
	void setEstado(int estado);


//GETTERS - MAI
	int getIdEspecialidad() const;
	string getNombreEspecialidad() const;
	string getDescripcionEspecialidad() const;
	string getFormacion() const;
	string getEstado() const;

};
