#include <iostream>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string word1, word2;
	cin >> word1 >> word2;

	char occur1[26] = {};
	char occur2[26] = {};

	// 첫 번째 단어 알파벳 개수 기록
	for (char c : word1) {
		occur1[c - 'a']++;
	}

	// 두 번째 단어 알파벳 개수 기록
	for (char c : word2) {
		occur2[c - 'a']++;
	}

	int ans = 0;

	// 각 알파벳별 차이 누적
	for (int i = 0; i < 26; i++) {
		ans += abs(occur1[i] - occur2[i]);
	}
	
	cout << ans;

	return 0;
}