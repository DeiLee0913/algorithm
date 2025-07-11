#include <iostream>

using namespace std;

int findNthApocalypseNumber(int n) {
	int num = 666;

	int con = 0;
	int ans = 0;

	while (true) {
		int cnt = num++;
		con = 0;

		while (cnt != 0) {
			if (cnt % 10 == 6) {
				con++;
			}
			else {
				con = 0;
			}

			cnt /= 10;

			if (con == 3) {
				ans++;
				break;
			}
		}

		if (ans == n) {
			return num - 1;
		}
	}
}

int main() {
	int n;
	cin >> n;

	int ans = findNthApocalypseNumber(n);

	cout << ans;

	return 0;
}