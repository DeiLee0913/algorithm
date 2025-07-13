#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int y = 0, m = 0;

	int time;

	for (int i = 0; i < n; i++) {
		cin >> time;
		y += (1 + (time / 30));
		m += (1 + (time / 60));
	}

	y *= 10;
	m *= 15;

	if (y == m) {
		cout << "Y M " << y;
	} else {
		y < m ? cout << "Y " << y : cout << "M " << m;
	}

	return 0;
}