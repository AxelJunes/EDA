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
		* Añade la canción S del artista A con duración D al Ipud.
		* Si ya existe una canción con el mismo nombre, la operación dará error.
		*/
		void addSong() {

		}

		/**
		* Añade la canción S al final de la lista de reproducción. Si la canción ya se encontraba en la lista,
		* entonces no se añade. Si la canción no está en el Ipud se devuelve error.
		*/
		void addToPlaylist() {

		}

		/**
		* Devuelve la primera canción de la lista de reproducción. Si la lista de reproducción es vacía,
		* devuelve un error.
		*/
		InfoSong current() {
			InfoSong c;

			return c;
		}

		/**
		* La primera canción de la lista de reproducción abandona la lista de reproducción y se registra como
		* reproducida. Si la lista es vacía, la acción no tiene efecto.
		*/
		void play() {

		}

		/**
		* Devuelve la suma de las duraciones de las canciones que integran la lista de reproducción actual.
		* Si es vacía, se devuelve 0.
		*/
		int totalTime() {
			return 0;
		}

		/**
		* Obtiene la lista con las N últimas canciones que se han reproducido, de la más reciente a la más antigua.
		* Si el número de canciones reproducidas es menor que N, se devolverán todas. La lista no tiene repeticiones,
		* de manera que si una canción se ha reproducido más de una vez, sólo figurará la reproducción más reciente.
		*/
		List<IdSong> recent() {

		}

		void deleteSong() {

		}
};