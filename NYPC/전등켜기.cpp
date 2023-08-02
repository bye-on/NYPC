#include <iostream>
#include <vector>
using namespace std;
char map[30][30] = { 0, };
int dw[4] = { 0,1,0,-1 }; // ��, ��, ��, ��
int dh[4] = { -1,0,1,0 }; // -> �ð�(+1) <- �ݽð�(+3)

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
					if ((index % 2) == 0) index = (index + 3) % 4; // �� �� -> �ݽð�
					else index = (index + 1) % 4; // �� �� -> �ð�
				}
				else if (map[nx][ny] == '/') {
					if ((index % 2) == 0) index = (index + 1) % 4; // �� �� -> �ð�
					else index = (index + 3) % 4; // �� �� -> �ݽð�
				} 
				// '.'�� �ʿ� ����(���� �ٲ��� �����ϱ�)
			}
		}
	}
	//for (int i = 0; i < 4; i++) {
	//	cout << direction[i] << " " << location[i] << '\n';
	//}

	cout << direction.front() << " " << location.front() << endl;
}