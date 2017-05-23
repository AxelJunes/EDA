#include <ctime>
using namespace std;

class Fecha{
	private:
		int dia;
		int hora;
		int minuto;

	public:
		/**
		* Constructor por defecto
		*/
		Fecha(){
			//Fecha actual
			time_t currentTime;
			struct tm *localTime;

			time(&currentTime);                   // Get the current time
			localTime = localtime(&currentTime);

			this->dia = localTime->tm_mday;
			this->hora = 1 + localTime->tm_hour;
			this->minuto = 1 + localTime->tm_min;
		}

		/**
		* Constructor con par�metros
		*/
		Fecha(int dia, int hora, int minuto) {
			this->dia = dia;	
			this->hora = hora;
			this->minuto = minuto;
		}

		//M�todos get

		int getDia() const{
			return this->dia;
		}

		int getHora() const{
			return this->hora;
		}

		int getMinuto() const{
			return this->minuto;
		}

		//M�todos set

		void setDia(int dia) {
			this->dia = dia;
		}

		void setHora(int hora) {
			this->hora = hora;
		}

		void setMinuto(int minuto) {
			this->minuto = minuto;
		}

		// M�todos de clase

		/**
		* Devuelve true si las dos fechas son iguales
		*/
		bool operator==(const Fecha &fecha) const {
			return (this->dia == fecha.dia)
				&& (this->hora == fecha.hora)
				&& (this->minuto == fecha.minuto);
		}
};
