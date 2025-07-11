#include <iostream>
#include <vector>

using namespace std;

int oneRound() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> houses(n);

	// 초기 윈도우 설정
	for (int i = 0; i < n; i++) {
		cin >> houses[i];
	}

	int ans = 0, sum = 0;

	for (int right = 0; right < m; right++) {
		sum += houses[right];
	}

	if (sum < k) {
		ans += 1;
	}

	// 특별 케이스: n == m
	// 부분 배열이 하나뿐

	if (n == m) {
		return ans;
	}

	// 슬라이딩 윈도우 실행
	// right = m - 1로 두는 실수를 했다가 한참 헤맴 
	int left = 0, right = m;

	while (right < n + m - 1) {
		sum -= houses[left++ % n];
		sum += houses[right++ % n];

		if (sum < k) {
			ans += 1;
		}
	}

	return ans;
}

int main() {
	int t;

	cin >> t;

	for (int i = 0; i < t; i++) {
		cout << oneRound() <<  "\n";
	}

	return 0;
}