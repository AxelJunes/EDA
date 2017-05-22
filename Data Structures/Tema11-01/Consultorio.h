//----------------------------
// Author: Axel Junestrand
//----------------------------

#include <string>
#include "List.h"
#include "Fecha.h"
#include "TreeMap.h"
using namespace std;

// Definiciones de tipos
typedef string Medico;
typedef string Paciente;

typedef struct{
	Paciente paciente;
	Fecha fecha;
}Cita;

/**
* Clase consultorio
*/
class Consultorio{
	private:
		TreeMap<Medico, List<Cita>> consultas;

	public:
		/**
		* Constructor por defecto
		*/
		Consultorio() {
			this->consultas = *new TreeMap<Medico, List<Cita>>();
		}

		/**
		* Constructor con parámetros
		*/
		Consultorio(TreeMap<Medico, List<Cita>> consultas) {
			this->consultas = consultas;
		}

		// Métodos get
		TreeMap<Medico, List<Cita>> getConsultas(){
			return this->consultas;
		}


		// Métodos set
		void setConsultas(TreeMap<Medico, List<Cita>> consultas) {
			this->consultas = consultas;
		}


		// Métodos de la clase

		/**
		* Da de alta un nuevo médico en el consultorio. Si el médico ya estaba
		* en el consultorio, este no se modifica.
		*/
		void nuevoMedico(Medico m) {
			List<Cita> citas;
			//Si el médico no estaba en el consultorio, lo añadimos con una lista vacía
			if(!this->consultas.contains(m))
				this->consultas.insert(m, citas);
		}

		/**
		* Comprueba si el médico m ya tiene ocupada la fecha f.
		*/
		bool fechaOcupada(Medico m, Fecha f) {
			List<Cita> citas = this->consultas[m];
			bool ocupada = false;

			List<Cita>::ConstIterator it = citas.cbegin();
			while (!ocupada && it != citas.cend()) {
				//Comprobamos si la fecha existe en la lista
				if (it.elem.fecha == f) {
					ocupada = true;
				}
				it.next();
			}
			return ocupada;
		}

		/**
		* El paciente p pide consulta con el médico m para una fecha f.
		*/
		void pideConsulta(Paciente p, Medico m, Fecha f) {
			if (!this->consultas.contains(m)) {
				cout << "Medico no existente" << endl;
				//throw new ExcepcionTAD("Medico no existente");
			}
			else {
				if (fechaOcupada(m, f)) {
					cout << "Fecha ocupada" << endl;
					//throw new ExcepcionTAD("Fecha ocupada");
				}
				else {
					//Creamos la nueva cita
					Cita cita;
					cita.paciente = p;
					cita.fecha = f;
					//Se inserta en la lista de citas
					this->consultas[m].push_back(cita);
				}
			}
		}

		/**
		* Consulta el paciente al que le toca el turno de ser atendido por el
		* médico m. Suponemos que el siguiente paciente es el que tiene una
		* fecha menor.
		*/
		Paciente siguientePaciente(Medico m) {
			if (!this->consultas.contains(m)) {
				cout << "Medico no existente" << endl;
				//throw new ExcepcionTAD("Medico no existente");
			}
			else {
				if (this->consultas[m].empty()) {
					cout << "No hay pacientes" << endl;
					//throw new ExcepcionTAD("Medico no existente");
				}
				else {
					//Devolvemos el siguiente paciente en la lista
					return this->consultas[m].front().paciente;
				}
			}
		}

		/**
		* Elimina el siguiente paciente del médico m. Suponemos que 
		* el siguiente paciente es el que tiene una fecha menor.
		*/
		void atiendeConsulta(Medico m) {
			this->consultas[m].pop_front();
		}

		/**
		* Devuelve la lista de pacientes del médico m que tienen cita el día d.
		* Se supone que el día es un número entero correcto.
		*/
		List<Paciente> listaPacientes(Medico m, int d) {
			//Lista de citas del médico
			List<Cita> citas = this->consultas[m];
			//Lista de pacientes a devolver
			List<Paciente> pacientes;

			List<Cita>::ConstIterator it = citas.cbegin();
			while (it != citas.cend()) {
				//Metemos en la lista de pacientes todos los pacientes
				//que tengan cita ese dia
				if (it.elem.fecha->getDia() == d) {
					pacientes.push_back(it.elem.paciente);
				}
				it.next();
			}
			return pacientes;
		}
};
