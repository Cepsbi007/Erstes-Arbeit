#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char CDfv[] = "Duom.txt";
const int Cmax = 40;
//------------------------------------
void Ivestis(const char fv[], int &k, int Skon[], float Svor[]);
void Sprendimas(int k, int Skon[], float Svor[], int &kiek, float &sum, int &skan, int &did);
void Isvestis(int kiek, float sum, int skan, int did);
//************************************
int main() {
	int k=0, Skon[Cmax];
	float Svor[Cmax];
	Ivestis(CDfv, k, Skon, Svor);
	int kiek=0, skan=0, did=0;
	float sum=0;
	Sprendimas(k, Skon, Svor, kiek, sum, skan, did);
	Isvestis(kiek, sum, skan, did);
}
//************************************
void Ivestis(const char fv[], int &k, int Skon[], float Svor[]) {
	char ats = 'T';
	cout << "Iveskite zuvies svori ir skoni: " << endl;
	while (ats == 'T') {
		cin >> Svor[k];
		cin >> Skon[k];
		k++;
		cout << "Ar dar liko zuveliu? ";
		cin >> ats;
	}
}
//------------------------------------
void Sprendimas(int k, int Skon[], float Svor[], int &kiek, float &sum, int &skan, int &did) {
	for (int i = 0; i < k; i++) {
		if (Skon[i] == 1 && Svor[i] >= 1) {
			kiek++;
			sum += Svor[i];
		}
		if (Skon[i] == 1) {
			skan++;
		}
		if (Svor[i] >= 1) {
			did++;
		}
	}
}
//------------------------------------
void Isvestis(int kiek, float sum, int skan, int did ) {
	cout << kiek << " " << fixed << setprecision(2) << sum << endl;
	cout << "Dideliu zuveliu - " << did << ", skaniu - " << skan;
}