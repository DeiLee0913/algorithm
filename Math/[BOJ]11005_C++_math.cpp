#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int b;
	cin >> n >> b;

	string ans = "";

	while (n) {
		int cnt = n % b;
		if (cnt < 10) {
			ans += (cnt + '0');
		}
		else {
			ans += (cnt + 'A' - 10);
		}
		
		n /= b;
	}

	reverse(ans.begin(), ans.end());

	cout << ans;

	return 0;
}