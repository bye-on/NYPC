#include <iostream>
using namespace std;
char map[21][21];

int main() {
	int N;
	cin >> N;
	int Dcount = 0; // �ٶ����� ��
	int Ccount = 0; // �÷��̾��� ��

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = str[j];
			if (str[j] == 'D') Dcount++;
			if (str[j] == 'C') Ccount++;
		}
	}
	Ccount *= 2;

	while (true) {
		if (Ccount <= Dcount) break;
		int row = rand() % N;
		int col = rand() % N;
		if (map[row][col] == 'C' || map[row][col] == 'D') continue;
		map[row][col] = 'D';
		Dcount++;
	}

	cout << N << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << endl;
	}
}