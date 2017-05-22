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
			this->dia = 0;
			this->hora = 0;
			this->minuto = 0;
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

		int getDia() {
			return this->dia;
		}

		int getHora() {
			return this->hora;
		}

		int getMinuto() {
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