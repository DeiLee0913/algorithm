#include <iostream>
#include <stack>

using namespace std;

int main() {
	int k; cin >> k;

	stack<int> s;

	int cnt;
	while (k--) {
		cin >> cnt;
		if (cnt == 0) {
			s.pop();
		}
		else {
			s.push(cnt);
		}
	}

	int sum = 0;
	while (!s.empty()) {
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}