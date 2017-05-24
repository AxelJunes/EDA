//-----------------------------------------------------------
//           TEMA 11-01: CONSULTORIO MÉDICO
//-----------------------------------------------------------
//               Author: Axel Junestrand
//-----------------------------------------------------------

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Consultorio.h"

using namespace std;

bool resuelve() {

	int N;
	cin >> N;
	if (!cin) return false;

	string inst;
	Medico med;
	Paciente pac;
	int d, h, m;
	Consultorio con;

	for (int i = 0; i < N; ++i) {
		try {
			cin >> inst;
			if (inst == "nuevoMedico") {
				cin >> med;
				con.nuevoMedico(med);
			}
			else if (inst == "pideConsulta") {
				cin >> pac >> med >> d >> h >> m;
				con.pideConsulta(pac, med, Fecha(d, h, m));
			}
			else if (inst == "siguientePaciente") {
				cin >> med;
				pac = con.siguientePaciente(med);
				cout << "Siguiente paciente doctor " << med << '\n';
				cout << pac << '\n';
				cout << "---\n";
			}
			else if (inst == "atiendeConsulta") {
				cin >> med;
				con.atiendeConsulta(med);
			}
			else if (inst == "listaPacientes") {
				cin >> med >> d;
				auto vec = con.listaPacientes(med, Fecha(d, 0, 0));
				cout << "Doctor " << med << " dia " << d << '\n';
				for (auto p : vec) {
					cout << p.first << ' ';
					cout << setfill('0') << setw(2) << p.second.getHora() << ':';
					cout << setfill('0') << setw(2) << p.second.getMinuto() << '\n';
				}
				cout << "---\n";
			}
		}
		catch (ExcepcionTAD e) { cout << e.msg() << '\n' << "---\n"; }
	}
	cout << "------\n";
	return true;
}

	int main() {
		while (resuelve())
			return 0;
	}
