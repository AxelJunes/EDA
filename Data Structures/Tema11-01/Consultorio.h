//----------------------------
// Author: Axel Junestrand
//----------------------------

#include <string>
#include <utility> // pair
#include "List.h"
#include "Fecha.h"
#include "TreeMap.h"
#include "HashMap.h"
using namespace std;

// Definiciones de tipos
typedef string Medico;
typedef string Paciente;

/**
* Clase consultorio
*/
class Consultorio{
	private:
		HashMap<Medico, TreeMap<Paciente, Fecha> > consultas;

	public:
		/**
		* Constructor por defecto
		*/
		Consultorio() {
			this->consultas = *new HashMap<Medico, TreeMap<Paciente, Fecha> >();
		}

		/**
		* Constructor con par�metros
		*/
		Consultorio(HashMap<Medico, TreeMap<Paciente, Fecha> > consultas) {
			this->consultas = consultas;
		}

		// M�todos get
		HashMap<Medico, TreeMap<Paciente, Fecha> > getConsultas() const{
			return this->consultas;
		}


		// M�todos set
		void setConsultas(HashMap<Medico, TreeMap<Paciente, Fecha> > consultas) {
			this->consultas = consultas;
		}


		// M�todos de la clase

		/**
		* Da de alta un nuevo m�dico en el consultorio. Si el m�dico ya estaba
		* en el consultorio, este no se modifica.
		*/
		void nuevoMedico(Medico m) {
			TreeMap<Paciente, Fecha> citas;
			//Si el m�dico no estaba en el consultorio, lo a�adimos con una lista vac�a
			if(!this->consultas.contains(m))
				this->consultas.insert(m, citas);
		}

		/**
		* El paciente p pide consulta con el m�dico m para una fecha f.
		*/
		void pideConsulta(Paciente p, Medico m, Fecha f) {
			if (!this->consultas.contains(m)) {
				cout << "Medico no existente" << endl;
				//throw new ExcepcionTAD("Medico no existente");
			}
			else {
				TreeMap<Paciente, Fecha> &citas = this->consultas[m];
				bool ocupada = false;
				//Iteramos sobre el TreeMap de citas para buscar si ya está ocupada la fecha
				TreeMap<Paciente, Fecha>::ConstIterator it = citas.cbegin();
				while (!ocupada && it != citas.cend()) {
					//Comprobamos si la fecha existe en la lista
					if (it.value() == f) {
						ocupada = true;
					}
					it.next();
				}
				if(ocupada){
					cout << "Fecha ocupada" << endl;
					//throw new ExcepcionTAD("Fecha ocupada");
				}
				else {
					//Creamos la nueva cita con el dia, la hora y el minuto actual
					Paciente paciente;
					Fecha fecha;
					//Se inserta en la lista de citas
					this->consultas[m].insert(paciente, fecha);
				}
			}
		}

		/**
		* Consulta el paciente al que le toca el turno de ser atendido por el
		* m�dico m. Suponemos que el siguiente paciente es el que tiene una
		* fecha menor.
		*/
		Paciente siguientePaciente(Medico m) {
			if (!this->consultas.contains(m)) {
				throw "Medico no existente";
			}
			else {
				if (this->consultas[m].empty()) {
					throw "No hay pacientes";
				}
				else {
					//Devolvemos el siguiente paciente en la lista
					TreeMap<Paciente, Fecha> citas = this->consultas[m];
					TreeMap<Paciente, Fecha>::ConstIterator it = citas.cbegin();
					return it.key();
				}
			}
		}

		/**
		* Elimina el siguiente paciente del m�dico m. Suponemos que 
		* el siguiente paciente es el que tiene una fecha menor.
		*/
		void atiendeConsulta(Medico m) {
			TreeMap<Paciente, Fecha> &citas = this->consultas[m];
			TreeMap<Paciente, Fecha>::ConstIterator it = citas.cbegin();
			this->consultas[m].erase(it.key());
		}

		/**
		* Devuelve la lista de pares paciente,fecha del m�dico m que tienen cita el d�a d.
		* Se supone que el d�a es un n�mero entero correcto.
		*/
		List<pair<Paciente, Fecha> > listaPacientes(Medico m, Fecha f) {
			//Lista de citas del m�dico
			TreeMap<Paciente, Fecha> &citas = this->consultas[m];
			//Lista de pacientes a devolver
			List<pair<Paciente, Fecha> > pacientes;

			TreeMap<Paciente, Fecha>::ConstIterator it = citas.cbegin();
			while (it != citas.cend()) {
				//Metemos en la lista de pacientes todos los pacientes
				//que tengan cita ese dia
				if (it.value().getDia() == f.getDia()) {
					//Declaramos un par con los datos de la cita
					pair<Paciente, Fecha> cita;
					cita.first = it.key();
					cita.second = it.value();
					pacientes.push_back(cita);
				}
				it.next();
			}
			return pacientes;
		}
};
