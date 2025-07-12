#include <iostream>

using namespace std;

int main() {
	int cnt;
	int min = 100 , sum = 0;

	for (int i = 0; i < 7; i++) {
		cin >> cnt;

		if ((cnt % 2) == 1) {
			sum += cnt;
			if (cnt < min) {
				min = cnt;
			}
		}
	}
	
	if (sum == 0) {
		cout << "-1";
	}
	else {
		cout << sum << "\n" << min;
	}
	
	return 0;
}