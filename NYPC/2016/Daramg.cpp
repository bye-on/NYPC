// https://www.nypc.co.kr/community/questionView.do?IDX=1&category=1
// 넥슨은 다람쥐를 뿌려라
#include <iostream>
using namespace std;
char map[21][21];

int main() {
	int N;
	cin >> N;
	int Dcount = 0; // 다람쥐의 수
	int Ccount = 0; // 플레이어의 수

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
