//----------------------------
// Author: Axel Junestrand
//----------------------------

#include <iostream>
#include <string>
#include <utility> // pair
#include "HashMap.h"
#include "List.h"
#include "TreeMap.h"
#include "Fecha.h"
using namespace std;

// Definiciones de tipos
typedef string Medico;
typedef string Paciente;

/**
* Clase consultorio
*/
class Consultorio{
	private:
		HashMap<Medico, TreeMap<Fecha, Paciente> > consultas;

	public:
		/**
		* Constructor por defecto
		*/
		Consultorio() {
			this->consultas = *new HashMap<Medico, TreeMap<Fecha, Paciente> >();
		}

		/**
		* Constructor con parametros
		*/
		Consultorio(HashMap<Medico, TreeMap<Fecha, Paciente> > consultas) {
			this->consultas = consultas;
		}

		// Metodos get
		HashMap<Medico, TreeMap<Fecha, Paciente> > getConsultas() const{
			return this->consultas;
		}


		// Metodos set
		void setConsultas(HashMap<Medico, TreeMap<Fecha, Paciente> > consultas) {
			this->consultas = consultas;
		}


		// Metodos de la clase

		/**
		* Da de alta un nuevo medico en el consultorio. Si el medico ya estaba
		* en el consultorio, este no se modifica.
		*/
		void nuevoMedico(Medico m) {
			TreeMap<Fecha, Paciente> citas;
			//Si el medico no estaba en el consultorio, lo anadimos con una lista vacia
			if(!this->consultas.contains(m))
				this->consultas.insert(m, citas);
		}

		/**
		* El paciente p pide consulta con el medico m para una fecha f.
		*/
		void pideConsulta(Paciente p, Medico m, Fecha f) {
			if (!this->consultas.contains(m)) {
				throw ExcepcionTAD("Medico no existente");
			}
			else {
				TreeMap<Fecha, Paciente> &citas = this->consultas[m];
				//Comprobamos si la fecha está en el TreeMap
				if(citas.contains(f)){
					throw ExcepcionTAD("Fecha ocupada");
				}
				else {
					//Se inserta en la lista de citas
					this->consultas[m].insert(f, p);
				}
			}
		}

		/**
		* Consulta el paciente al que le toca el turno de ser atendido por el
		* medico m. Suponemos que el siguiente paciente es el que tiene una
		* fecha menor.
		*/
		Paciente siguientePaciente(Medico m) {
			if (!this->consultas.contains(m)) {
				throw ExcepcionTAD("Medico no existente");
			}
			else {
				if (this->consultas[m].empty()) {
					throw ExcepcionTAD("No hay pacientes");
				}
				else {
					//Devolvemos el siguiente paciente en la lista
					TreeMap<Fecha, Paciente> &citas = this->consultas[m];
					TreeMap<Fecha, Paciente>::ConstIterator it = citas.cbegin();
					return it.value();
				}
			}
		}

		/**
		* Elimina el siguiente paciente del medico m. Suponemos que 
		* el siguiente paciente es el que tiene una fecha menor.
		*/
		void atiendeConsulta(Medico m) {
			TreeMap<Fecha, Paciente> &citas = this->consultas[m];
			if(citas.empty())
				throw ExcepcionTAD("No hay pacientes");
			TreeMap<Fecha, Paciente>::ConstIterator it = citas.cbegin();
			this->consultas[m].erase(it.key());
		}

		/**
		* Devuelve la lista de pares paciente,fecha del m�dico m que tienen cita el dia d.
		* Se supone que el dia es un numero entero correcto.
		*/
		List<pair<Paciente, Fecha> > listaPacientes(Medico m, Fecha f) {
			//Lista de citas del medico
			TreeMap<Fecha, Paciente> &citas = this->consultas[m];
			//Lista de pacientes a devolver
			List<pair<Paciente, Fecha> > pacientes;

			TreeMap<Fecha, Paciente>::ConstIterator it = citas.cbegin();
			while (it != citas.cend()) {
				//Metemos en la lista de pacientes todos los pacientes
				//que tengan cita ese dia
				if (it.key().getDia() == f.getDia()) {
					//Declaramos un par con los datos de la cita
					pair<Paciente, Fecha> cita;
					cita.first = it.value();
					cita.second = it.key();
					pacientes.push_back(cita);
				}
				it.next();
			}
			return pacientes;
		}
};
