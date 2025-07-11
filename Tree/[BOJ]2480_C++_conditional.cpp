#include <iostream>

using namespace std;

void initalizeArray(int arr[]) {
	for (int i = 0; i < 7; i++) {
		arr[i] = 0;
	}

	return;
}

int getPrize(int noon[]) {
	int prize = -1;

	for (int i = 1; i < 7; i++) {
		if (noon[i] == 3) {
			prize = 10000 + i * 1000;
			break;
		}

		else if (noon[i] == 2) {
			noon[0] = 2;
			prize = 1000 + i * 100;
		}

		else if (noon[i] == 1 && noon[0] == 0) {
			prize = i * 100;
		}
	}

	return prize;
}

int main() {
	int noon[7];

	initalizeArray(noon);

	for (int i = 0; i < 3; i++) {
		int cnt;
		cin >> cnt;
		noon[cnt]++;
	}

	int prize = getPrize(noon);
	
	cout << prize;

	return 0;
}