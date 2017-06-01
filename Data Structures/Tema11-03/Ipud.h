// Author: Axel Junestrand

#include "HashMap.h"
#include "List.h"

//Type declarations

//Song id
typedef string Artista;
typedef string IdSong;
typedef int Duracion;

// Song information
typedef struct {
	Artista a;
	Duracion d;
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
			this->songs = *new HashMap<IdSong, InfoSong>();
			this->playlist = *new List<IdSong>();
			this->played = *new List<IdSong>();
		}

		/**
		* Parameter constructor
		*/
		Ipud(HashMap<IdSong, InfoSong> songs, List<IdSong> playlist, List<IdSong> played) {
			this->songs = songs;
			this->playlist = playlist;
			this->played = played;
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
		void addSong(IdSong s, Artista a, Duracion d) { // O(1)
			if (this->songs.contains(s))
				throw invalid_argument("Ya existe una canci�n con ese nombre!");
			else{
				// Si no hay ning�n error, insertamos la canci�n en el HashMap
				InfoSong info;
				info.a = a;
				info.d = d;
				this->songs.insert(s, info);
			}
		}

		/**
		* A�ade la canci�n S al final de la lista de reproducci�n. Si la canci�n ya se encontraba en la lista,
		* entonces no se a�ade. Si la canci�n no est� en el Ipud se devuelve error.
		*/
		void addToPlaylist(IdSong s) { // O(played.length())
			if (!this->songs.contains(s))
				throw invalid_argument("La canci�n no existe en el iPud!");
			// Si la canci�n existe en el iPud
			bool encontrada = false;
			List<IdSong> &played = this->played;
			// Iteramos sobre la playlist para buscar la canci�n
			List<IdSong>::ConstIterator it = played.cbegin();
			while (!encontrada && it != played.cend()){
				if (it.elem() == s)
					encontrada = true;
				it++;
			}
			if (!encontrada)
				this->playlist.push_back(s);
		}

		/**
		* Devuelve la primera canci�n de la lista de reproducci�n. Si la lista de reproducci�n es vac�a,
		* devuelve un error.
		*/
		IdSong current() { // O(1)
			if (this->playlist.empty())
				throw invalid_argument("No hay canciones en la playlist!");
			return this->playlist.front();
		}

		/**
		* La primera canci�n de la lista de reproducci�n abandona la lista de reproducci�n y se registra como
		* reproducida. Si la lista es vac�a, la acci�n no tiene efecto.
		*/
		//void play() {
		//	if (this->playlist.empty())
		//		return;
		//	// Si la lista de reproducci�n no est� vac�a
		//	this->
		//}

		/**
		* Devuelve la suma de las duraciones de las canciones que integran la lista de reproducci�n actual.
		* Si es vac�a, se devuelve 0.
		*/
		int totalTime() { // O(playlist.length())
			int time = 0;
			List<IdSong> &playlist = this->playlist;
			// Iteramos sobre la playlist para sumar las duraciones
			List<IdSong>::ConstIterator it = playlist.cbegin();
			while (it != playlist.cend()){
				//Buscamos la duraci�n de la canci�n en el HashMap
				int duracion = this->songs.find(it.elem()).value.d;
				time += duracion;
				it++;
			}
			return time;
		}

		/**
		* Obtiene la lista con las N �ltimas canciones que se han reproducido, de la m�s reciente a la m�s antigua.
		* Si el n�mero de canciones reproducidas es menor que N, se devolver�n todas. La lista no tiene repeticiones,
		* de manera que si una canci�n se ha reproducido m�s de una vez, s�lo figurar� la reproducci�n m�s reciente.
		*/
		List<IdSong> recent(int N) { // O(N)
			if (this->played.size() < N)
				return this->played;
			List<IdSong> &played = this->playlist;
			List<IdSong> recent;
			// Iteramos sobre la lista de reproducidas
			List<IdSong>::ConstIterator it = played.cbegin();
			int n = 0;
			while (n < N && it != played.cend()){
				//Metemos en la lista de recientes las canciones por las que pase el iterador
				recent.push_back(it.elem());
				it++;
				//Incrementamos el contador de canciones le�das
				n++;
			}
			return recent;
		}

		/**
		* Elimina todo rastro de la canci�n S del iPud. Si la canci�n no existe, la operaci�n no tiene efecto.
		*/
		void deleteSong(IdSong s) {
			this->songs.erase(s);
		}
};