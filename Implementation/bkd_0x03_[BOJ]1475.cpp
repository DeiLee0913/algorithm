#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// 0~9 각 숫자의 등장 횟수 저장
	int cnt[10] = {};

	// 각 자리수 숫자 세기
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10;
	}
	
	// 6과 9는 서로 대체 가능 → 합쳐서 올림 평균 내기
	//cnt[6] = (cnt[6] + cnt[9]) / 2 + (cnt[6] + cnt[9]) % 2;
	cnt[6] = (cnt[6] + cnt[9] + 1) / 2;
	cnt[9] = 0;

	int max = 0;
	// 0~8 중 가장 많이 등장한 숫자 개수 찾기
	for (int i = 0; i < 9; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
		}
	}

	// 필요한 세트 수 출력
	cout << max << "\n";

	return 0;
}