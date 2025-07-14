#include <iostream>

using namespace std;

bool strfryTest(string s1, string s2) {
	int occur[26] = {};

	for (char c : s1) {
		occur[c-'a']++;
	}

	for (char c : s2) {
		occur[c - 'a']--;
	}

	for (int c : occur) {
		if (c != 0) {
			return false;
		}
	}

	return true;
}

int main() {
	int n; cin >> n;

	string s1, s2;

	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2;
		strfryTest(s1, s2) == 1 ? cout << "Possible\n" : cout << "Impossible\n";
	}

	return 0;
}