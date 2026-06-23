#pragma once

//---MAI---
//CONSTRUCTOR
class Especialidad {
private:
		int _idEspecialidad;
		char _nombreEspecialidad[25];
		char _descripcionEspecialidad[50];
		int _idFormacion;

	public:
		Especialidad();
		Especialidad(int idEspecialidad, int idFormacion, string nombreEspecialidad, string descripcionEspecialidad);


//SETTERS - MAI
	void setEspecialidad(int idEspecialidad);
	void setNombreEspecialidad(string nombreEspecialidad);
	void setDescripcionEspecialidad(string descripcionEspecialidad);
	void setIdFormacion(int idFormacion);


//GETTERS - MAI
	int getEspecialidad() const;
	string getNombreEspecialidad() const;
	string getDescripcionEspecialidad() const;
	string getFormacion() const;

};
