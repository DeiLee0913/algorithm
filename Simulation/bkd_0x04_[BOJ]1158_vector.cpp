#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> nums;

	for (int i = 1; i <= n; i++) {
		nums.push_back(i);
	}
	
	vector<int> result;
	int idx = 0;

	while (!nums.empty()) {
		idx = (idx + k - 1) % nums.size();	// 다음 삭제할 인덱스
		result.push_back(nums[idx]);		// 값 저장
		nums.erase(nums.begin() + idx);		// 해당 인덱스 삭제
	}

	cout << "<";
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) cout << ", ";
	}
	cout << ">\n";

	return 0;
}