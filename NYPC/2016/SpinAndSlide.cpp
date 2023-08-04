// https://nypc.github.io/2016/spinandslide.html
// 돌리고 밀고
#include <iostream>
using namespace std;
int N, M; // N = 게임판의 크기, M = Spin and Slide 횟수 
char map[100][100];

void SpinAndSlide() {
	char spin[100][100];
	for (int i = 0; i < N; i++) { // 행
		for (int j = 0; j < N; j++) { // 열
			spin[j][(N - 1) - i] = map[i][j];
		}
	}
	for (int j = N - 1; j >= 0; j--) { // 열 
		int index = N - 1;
		for (int i = N - 1; i >= 0; i--) { // 행
			while (true) {
				if (spin[index][j] == '.') index--;
				else break;
			}
			if (index < 0) map[i][j] = '.';
			else map[i][j] = spin[index--][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			map[i][j] = str[j];
		}
	}
	for (int i = 0; i < M; i++) {
		SpinAndSlide();
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}