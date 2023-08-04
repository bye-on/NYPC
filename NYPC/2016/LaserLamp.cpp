// https://www.nypc.co.kr/community/questionView.do?IDX=3&category=1
// 전등 켜기
#include <iostream>
#include <vector>
using namespace std;
char map[30][30] = { 0, };
int dw[4] = { 0,1,0,-1 }; // 상, 하, 우, 좌
int dh[4] = { -1,0,1,0 }; // -> 시계(+1) <- 반시계(+3)

int main() {
	int w, h; // 가로(열), 세로(행)
	cin >> w >> h;
	int x = 0, y = 0; // 전등 위치
	vector<char> direction;
	vector<int> location;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < w; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'O') {
				x = i; // 세로
				y = j; // 가로
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int index = i;
		int nx = x;
		int ny = y;
		while (true) {
			nx = nx + dh[index];
			ny = ny + dw[index];

			if (nx < 0) {
				direction.push_back('U');
				location.push_back(ny);
				break;
			}
			else if (nx >= h) {
				direction.push_back('D');
				location.push_back(ny);
				break;
			}
			else if (ny < 0) {
				direction.push_back('L');
				location.push_back(nx);
				break;
			}
			else if (ny >= w) {
				direction.push_back('R');
				location.push_back(nx);
				break;
			}
			else {
				if (map[nx][ny] == '\\') {
					if ((index % 2) == 0) index = (index + 3) % 4; // 상 하 -> 반시계
					else index = (index + 1) % 4; // 우 좌 -> 시계
				}
				else if (map[nx][ny] == '/') {
					if ((index % 2) == 0) index = (index + 1) % 4; // 상 하 -> 시계
					else index = (index + 3) % 4; // 우 좌 -> 반시계
				} 
				// '.'가 필요 없음(방향 바꾸지 않으니까)
			}
		}
	}
	//for (int i = 0; i < 4; i++) {
	//	cout << direction[i] << " " << location[i] << '\n';
	//}

	cout << direction.front() << " " << location.front() << endl;
}
