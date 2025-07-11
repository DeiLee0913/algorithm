#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end());

	int x;
	cin >> x;


	int ans = 0;

	int left = 0, right = n - 1;

	while (left < right) {
		int cnt = nums[left] + nums[right];

		if (cnt == x) {
			ans++;
			left++;
			right--;
		}

		else if (cnt > x) {
			right--;
		} else { // cnt < x
			left++;
		}
	}


	cout << ans;

	return 0;
}