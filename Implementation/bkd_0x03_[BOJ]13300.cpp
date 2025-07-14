#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	int students[14] = {};

	int sex, grade;
	int room = 0;

	for (int i = 0; i < n; i++) {
		cin >> sex >> grade;
		students[grade * 2 + sex]++;
	}

	for(int i = 2; i < 14; i++) {
		room += students[i] / k;
		students[i] %= k;

		if (students[i] > 0) {
			room++;
		}
	}

	cout << room;
	
	return 0;
}