// Author: Axel Junestrand

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
// Author: Axel Junestrand
#include "Ipud.h"
using namespace std;

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
				cin >> songInfo.a;
				cin >> songInfo.d;
				ipud.addSong(song, songInfo.a, songInfo.d);
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
				if (!ipud.getPlaylist().empty())
					cout << "Sonando " << ipud.getPlaylist().front() << endl;
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
			cout << e.what() << '\n';
			cout << "ERROR " << inst << endl;
			cout << "----\n";
		}
		cin >> inst;
	}
	return true;
}

int main() {
	while (resuelve());
	return 0;
}