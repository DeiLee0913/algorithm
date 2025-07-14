#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	long long ans = a * b * c;

	int cnt[10] = {};

	while (ans > 0) {
		cnt[ans % 10]++;
		ans /= 10;
	}

	for (int c : cnt) {
		cout << c << "\n";
	}

	return 0;
}