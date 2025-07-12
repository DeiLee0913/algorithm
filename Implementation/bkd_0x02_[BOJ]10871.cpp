#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	int cnt;
	for (int i = 0; i < n; i++) {
		cin >> cnt;
		if (cnt < x) {
			cout << cnt << " ";
		}
	}

	return 0;
}