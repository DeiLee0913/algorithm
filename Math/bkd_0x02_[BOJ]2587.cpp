#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	vector<int> nums(5);
	
	for (int i = 0; i < 5; i++) {
		cin >> nums[i];
	}

	double mean = accumulate(nums.begin(), nums.end(), 0.0) / 5;
	sort(nums.begin(), nums.end());
	double mid = nums[2];

	cout << mean << "\n" << mid;

	return 0;
}