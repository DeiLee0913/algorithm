#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void infect(vector<vector<int>>& adjs, int here, vector<bool>& infected) {
	infected[here] = true;

	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];
		if (!infected[there]) {
			infect(adjs, there, infected);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	int n_of_adjs; cin >> n_of_adjs;

	vector<vector<int>> adjs(n + 1);

	int a, b;
	for (int i = 0; i < n_of_adjs; i++) {
		cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}

	vector<bool> infected(n + 1, false);
	
	infect(adjs, 1, infected);

	cout << count(infected.begin(), infected.end(), true)  - 1 << "\n";

	return 0;
}