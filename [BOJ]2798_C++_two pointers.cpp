#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> cards(n);

	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}

	// 투 포인터를 위한 정렬
	sort(cards.begin(), cards.end());

	int cnt = 0;
	int ans = 0;


	// i는 첫 번째 카드의 인덱스를 의미
	// left가 두 번째, right가 세 번째 카드
	for (int i = 0; i < n - 2; i++) {
		int left = i + 1;
		int right = n - 1;

		while (left < right) {
			int sum = cards[i] + cards[left] + cards[right];

			// m과 일치하는 합을 찾아내면 바로 정리
			if (sum == m) {
				std::cout << sum;
				return 0;
			}

			// 합이 작은 경우
			if (sum < m) {
				ans = max(ans, sum);
				left++;
			}
			else {
				right--;
			}
		}
	}

	std::cout << ans;

	return 0;
}