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
	bool played;
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
		* Añade la canción S del artista A con duración D al Ipud.
		* Si ya existe una canción con el mismo nombre, la operación dará error.
		*/
		void addSong(IdSong s, Artista a, Duracion d) { // O(1)
			if (this->songs.contains(s))
				throw invalid_argument("Ya existe una canción con ese nombre!");
			else{
				// Si no hay ningún error, insertamos la canción en el HashMap
				InfoSong info;
				info.a = a;
				info.d = d;
				info.played = false; // Se inicializa la canción como no reproducida
				this->songs.insert(s, info);
			}
		}

		/**
		* Añade la canción S al final de la lista de reproducción. Si la canción ya se encontraba en la lista,
		* entonces no se añade. Si la canción no está en el Ipud se devuelve error.
		*/
		void addToPlaylist(IdSong s) { // O(played.length())
			if (!this->songs.contains(s))
				throw invalid_argument("La canción no existe en el iPud!");
			// Si la canción existe en el iPud
			bool encontrada = false;
			List<IdSong> &played = this->played;
			// Iteramos sobre la playlist para buscar la canción
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
		* Devuelve la primera canción de la lista de reproducción. Si la lista de reproducción es vacía,
		* devuelve un error.
		*/
		IdSong current() { // O(1)
			if (this->playlist.empty())
				throw invalid_argument("No hay canciones en la lista");
			return this->playlist.front();
		}

		/**
		* La primera canción de la lista de reproducción abandona la lista de reproducción y se registra como
		* reproducida. Si la lista es vacía, la acción no tiene efecto.
		*/
		void play() {
			if (this->playlist.empty())
				return;
			// Si la lista de reproducción no está vacía
			if (!this->songs.at(this->playlist.front()).played){
				// Si la canción no estaba ya en la lista de reproducidas
				this->played.push_back(this->playlist.front());
				// Ponemos la canción como ya reproducida
				InfoSong info;
				info.a = this->songs.at(this->playlist.front()).a;
				info.d = this->songs.at(this->playlist.front()).d;
				info.played = true;
				// Insertamos otra vez la canción para actualizarla
				this->songs.insert(this->playlist.front(), info);
				// La quitamos de la playlist
				this->playlist.pop_front();
			}
			else{
				// Si la canción estaba en la lista de reproducidas
				List<IdSong> &played = this->played;
				// Iteramos sobre la playlist para sumar las duraciones
				List<IdSong>::Iterator it = played.begin();
				while (it != played.end()){
					if (it.elem() == this->playlist.front()){
						this->playlist.erase(it);
						this->playlist.pop_front();
						// Añadimos la canción a la lista de reproducidas
						this->played.push_back(it.elem());
					}
					it++;
				}
			}
		}

		/**
		* Devuelve la suma de las duraciones de las canciones que integran la lista de reproducción actual.
		* Si es vacía, se devuelve 0.
		*/
		int totalTime() { // O(playlist.length())
			int time = 0;
			List<IdSong> &playlist = this->playlist;
			// Iteramos sobre la playlist para sumar las duraciones
			List<IdSong>::ConstIterator it = playlist.cbegin();
			while (it != playlist.cend()){
				//Buscamos la duración de la canción en el HashMap
				int duracion = this->songs.at(it.elem()).d;
				time += duracion;
				it++;
			}
			return time;
		}

		/**
		* Obtiene la lista con las N últimas canciones que se han reproducido, de la más reciente a la más antigua.
		* Si el número de canciones reproducidas es menor que N, se devolverán todas. La lista no tiene repeticiones,
		* de manera que si una canción se ha reproducido más de una vez, sólo figurará la reproducción más reciente.
		*/
		List<IdSong> recent(int N) { // O(N)
			if (this->played.size() < N)
				return this->played;
			List<IdSong> &played = this->played;
			List<IdSong> recent;
			// Iteramos sobre la lista de reproducidas
			List<IdSong>::ConstIterator it = played.cbegin();
			int n = 0;
			while (n < N && it != played.cend()){
				//Metemos en la lista de recientes las canciones por las que pase el iterador
				recent.push_front(it.elem());
				it++;
				//Incrementamos el contador de canciones leídas
				n++;
			}
			return recent;
		}

		/**
		* Elimina todo rastro de la canción S del iPud. Si la canción no existe, la operación no tiene efecto.
		*/
		void deleteSong(IdSong s) {
			this->songs.erase(s);

			this->played.erase(s);
			this
		}
};