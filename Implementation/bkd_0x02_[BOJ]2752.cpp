#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;

	vector<int> nums = { x, y, z };

	sort(nums.begin(), nums.end());

	for (int n : nums) {
		cout << n << " ";
	}

	return 0;
}