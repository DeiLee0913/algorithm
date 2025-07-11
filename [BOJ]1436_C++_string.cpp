#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	int count = 0;
	int cnt = 666;

	while (count < n) {
		string str = to_string(cnt++);

		if (str.find("666") != string::npos) {
			count++;
		}
	}

	cout << cnt - 1;
	
	return 0;
}