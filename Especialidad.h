#pragma once
#include "Persona.h"
#include "Medico.h"


/*

IdEspecialidad int
cargar () void
mostrar () void
getIdEspecialidad () int
*/


class Especialidad : public Medico {
private:
		int _IdEspecialidad;

	public:
		Especialidad();
		Especialidad(int IdEspecialidad);


//SETTERS - MAI
	void setEspecialidad(int _IdEspecialidad);


//GETTERS - MAI
	int getEspecialidad() const;

};
