#include <iostream>
#include <vector>

using namespace std;

void dfs(int here, vector<vector<int>>& adjs, vector<int> &pair) {
	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];

		// 현재 노드에 연결된 노드가 방문된 적 없는 상태라면
		// 그 노드의 부모 노드를 자신으로 지정
		if (pair[there] == 0) {
			pair[there] = here;
			dfs(there, adjs, pair);
		}
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>> adjs(n + 1);

	//간선 입력
	int a, b;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;

		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}
	
	// 각 노드의 부모를 저장하는 벡터
	vector<int> parent(n + 1, 0);

	dfs(1, adjs, parent);

	for (int i = 2; i < n + 1; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}