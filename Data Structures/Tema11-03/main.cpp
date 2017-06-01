// Author: Axel Junestrand

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;

#include "Ipud.h"


#ifndef DOMJUDGE

ifstream in("cola.txt");

auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

#endif

bool resuelve() {

	string inst;
	cin >> inst;
	if (!cin) return false;

	Ipud ipud;
	IdSong song;
	InfoSong songInfo;

	for (; inst != "FIN";) {
		try {
			if (inst == "addSong"){
				cin >> song;
				cin >> songInfo.artista;
				cin >> songInfo.duracion;
				ipud.addSong(song, songInfo.artista, songInfo.duracion);
			}
			if (inst == "addToPlaylist"){
				cin >> song;
				ipud.addToPlaylist(song);
			}
			if (inst == "current"){
				IdSong result = ipud.current();
				cout << "Current " << result << endl;
			}
			if (inst == "play"){
				ipud.play();
			}
			if (inst == "totalTime"){
				cout << "Tiempo total " << ipud.totalTime() << endl;
			}
			if (inst == "recent"){
				int recent;
				cin >> recent;
				cout << "Las " << recent << " mas recientes" << endl;
				auto vec = ipud.recent(recent);
				for (auto p : vec) {
					cout << "\t " << p << endl;
				}
				cout << "----" << endl;
			}
			if (inst == "deleteSong"){
				cin >> song;
				ipud.deleteSong(song);
			}
		}
		catch (invalid_argument e) {
			cout << e.what() << '\n' << "----\n";
		}
		cin >> inst;
	}
	return true;
}

int main() {
	while (resuelve()){};
	return 0;
}