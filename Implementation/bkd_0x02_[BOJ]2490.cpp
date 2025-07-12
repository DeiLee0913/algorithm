#include <iostream>

using namespace std;

int main() {

	// 윷의 등(0) 개수에 따라 결과 문자를 저장한 배열
	char result[5] = { 'E', 'A', 'B', 'C', 'D' };

	int cnt;

	for(int i = 0; i < 3; i++) {
		int sum = 0;

		for(int j = 0; j < 4; j++) {
			cin >> cnt;
			if (cnt == 0) sum++;
		}

		// 등 개수에 따른 문자 출력
		cout << result[sum] << "\n";

		/*
		아래는 조건문으로 구현한 대체 방식
		result 배열을 쓰면 코드가 더 간결하고 명확하므로,
	   배열 방식 사용을 추천 (아래 코드는 비효율적이거나 중복 가능성 있음)
		*/

		//if (sum == 0) {
		//	cout << "D\n";
		//} else if (sum == 4) {
		//	cout << "E\n";
		//} else {
		//	char ans = 'D' - sum;
		//	cout << ans << "\n";
		//}
	}

	return 0;
}