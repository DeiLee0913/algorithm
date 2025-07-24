#include <iostream>

using namespace std;

int main() {
	int cnt; 
	int max = 0, nth = 0;

	for (int i = 1; i < 10; i++) {
		cin >> cnt;
		
		if (max < cnt) {
			max = cnt;
			nth = i;
		}
	}

	cout << max << "\n" << nth;

	return 0;
}