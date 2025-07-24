#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int freq[26] = { 0, };

	for (char c: s) {
		freq[(c - 'a')]++;
	}

	for (int alpha : freq) {
		cout << alpha << " ";
	}

	return 0;
}