#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<string> str;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string resource;
		cin >> resource;
		auto it = find(str.begin(), str.end(), resource);
		if (it == str.end()) str.push_back(resource);
	}
	if (str.size() >= 4) cout << "invalid" << endl;
	else cout << "valid" << endl;
}
