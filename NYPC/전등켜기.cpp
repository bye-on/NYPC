#include <iostream>
#include <vector>
using namespace std;
char map[30][30] = { 0, };
int dw[4] = { 0,0,-1,1 };
int dh[4] = { -1,1,0,0 }; // �� �� �� ��

int main() {
	int w, h; // ����(��), ����(��)
	cin >> w >> h;
	int x = 0, y = 0; // ���� ��ġ
	vector<char> direction;
	vector<int> location;
	for (int i = 0; i < h; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < w; j++) {
			map[i][j] = str[j];
			if (map[i][j] == 'O') {
				x = i; // ����
				y = j; // ����
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dh[i];
		int ny = y + dw[i];
		int index = i;
		while (true) {
			if (nx < 0) {
				direction.push_back('U');
				location.push_back(ny);
				break;
			}
			else if (nx >= w) {
				direction.push_back('D');
				location.push_back(ny);
				break;
			}
			else if (ny < 0) {
				direction.push_back('L');
				location.push_back(nx);
				break;
			}
			else if (ny >= h) {
				direction.push_back('R');
				location.push_back(nx);
				break;
			}
			else { // �����¿�
				if (map[nx][ny] == '\\') {
					// nx = nx + dw[i];
					// ny = ny + dh[i];
					i = (i + 2) % 4;
					nx = nx + dh[i];
					ny = ny + dw[i];
				}
				else if (map[nx][ny] == '.') {
					nx = nx + dh[i];
					ny = ny + dw[i];
				}
				else if (map[nx][ny] == '/') {
					// nx = nx - dw[i];
					// ny = ny - dh[i];
					if (i == 0) i = (i + 3) % 4;
					else if (i == 2) i = 1;
					else i = (i + 1) % 4;
					nx = nx + dh[i];
					ny = ny + dw[i];
				}
			}
		}
		i = index;
	}
	cout << direction.back() << " " << location.back() << endl;
}