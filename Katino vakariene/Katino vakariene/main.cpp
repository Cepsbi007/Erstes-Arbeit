#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const char CDfv[] = "Duom.txt";
const int _cmax = 40;

void Input(const char fv[], int &amount, int Taste[], float Weight[]);
void Solution(int amount, int Taste[], float Weight[], int &good, float &sum, int &tasty, int &big);
void Output(int good, float sum, int tasty, int big);

int main() {
	int amount = 0;
	int Taste[_cmax];
	float Weight[_cmax];
	int good = 0;
	int tasty = 0;
	int big = 0;
	float sum = 0;

	Input (CDfv, amount, Taste, Weight);
	Solution (amount, Taste, Weight, good, sum, tasty, big);
	Output (good, sum, tasty, big);
}

void Input (const char fv[], int &amount, int Taste[], float Weight[]) {
	char answer = 'T';
	cout << "Iveskite zuvies svori ir skoni: " << endl;

	while (answer == 'T') {
		cin >> Weight[amount];
		cin >> Taste[amount];

		amount++;
		cout << "Ar dar liko zuveliu? ";
		cin >> answer;
	}
}

void Solution (int amount, int Taste[], float Weight[], int &good, float &sum, int &tasty, int &big) {
	for (int i = 0; i < amount; i++) {
		
		if (Taste[i] == 1 && Weight[i] >= 1) {
			good++;
			sum += Weight[i];
		}
		if (Taste[i] == 1) {
			tasty++;
		}
		if (Weight[i] >= 1) {
			big++;
		}
	
	}
}

void Output (int good, float sum, int tasty, int big ) {
	cout << good << " " << fixed << setprecision(2) << sum << endl;
	cout << "Dideliu zuveliu - " << big << ", skaniu - " << tasty;
}
