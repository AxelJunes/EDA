// Author: Axel Junestrand

#include "HashMap.h"
#include "List.h"

//Type declarations

//Song id
typedef string IdSong;

// Song information
typedef struct {
	string artista;
	int duracion;
}InfoSong;

/**
* Ipud Class
*/

class Ipud {
	private:
		HashMap<IdSong, InfoSong> songs;
		List<IdSong> playlist;
		List<IdSong> played;

	public:
		/**
		* Default constructor
		*/
		Ipud() {

		}

		/**
		* Parameter constructor
		*/
		Ipud() {

		}

		// Getters and setters

		HashMap<IdSong, InfoSong> getSongs() {
			return this->songs;
		}

		List<IdSong> getPlaylist() {
			return this->playlist;
		}

		List<IdSong> getPlayed() {
			return this->played;
		}

		void setSongs(HashMap<IdSong, InfoSong> songs) {
			this->songs = songs;
		}

		void setPlaylist(List<IdSong> playlist) {
			this->playlist = played;
		}

		void setPlayed(List<IdSong> played) {
			this->played = played;
		}


		// Class methods

		/**
		* A�ade la canci�n S del artista A con duraci�n D al Ipud.
		* Si ya existe una canci�n con el mismo nombre, la operaci�n dar� error.
		*/
		void addSong() {

		}

		/**
		* A�ade la canci�n S al final de la lista de reproducci�n. Si la canci�n ya se encontraba en la lista,
		* entonces no se a�ade. Si la canci�n no est� en el Ipud se devuelve error.
		*/
		void addToPlaylist() {

		}

		/**
		* Devuelve la primera canci�n de la lista de reproducci�n. Si la lista de reproducci�n es vac�a,
		* devuelve un error.
		*/
		InfoSong current() {
			InfoSong c;

			return c;
		}

		/**
		* La primera canci�n de la lista de reproducci�n abandona la lista de reproducci�n y se registra como
		* reproducida. Si la lista es vac�a, la acci�n no tiene efecto.
		*/
		void play() {

		}

		/**
		* Devuelve la suma de las duraciones de las canciones que integran la lista de reproducci�n actual.
		* Si es vac�a, se devuelve 0.
		*/
		int totalTime() {
			return 0;
		}

		/**
		* Obtiene la lista con las N �ltimas canciones que se han reproducido, de la m�s reciente a la m�s antigua.
		* Si el n�mero de canciones reproducidas es menor que N, se devolver�n todas. La lista no tiene repeticiones,
		* de manera que si una canci�n se ha reproducido m�s de una vez, s�lo figurar� la reproducci�n m�s reciente.
		*/
		List<IdSong> recent() {

		}

		void deleteSong() {

		}
};