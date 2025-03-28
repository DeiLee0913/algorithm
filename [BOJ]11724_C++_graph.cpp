#include <iostream>
#include <vector>

using namespace std;

// DFS: 현재 정점에서 연결된 모든 정점 방문
void dfs(int here, vector<vector<int>>& adjs, vector<bool>& visited) {
	visited[here] = true;

	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];

		if (!visited[there]) {
			dfs(there, adjs, visited);
		}
	}

	return;
}

// DFS 전체 호출: 연결 요소(컴포넌트) 개수 세기
int dfsAll(int n, vector<vector<int>>& adjs) {
	vector<bool> visited(n + 1);

	int cnt = 0;

	for (int i = 1; i < n + 1; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i, adjs, visited);
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;


	vector<vector<int>> adjs(n + 1);

	int u, v;
	/// 무향 그래프 입력
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adjs[u].push_back(v);
		adjs[v].push_back(u);
	}

	cout << dfsAll(n, adjs);

	return 0;
}