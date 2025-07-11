#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS: 현재 노드부터 깊이 우선 탐색하며 방문 순서 출력
void dfs(int here, vector<vector<int>> &adjs, vector<bool>& visited) {
	visited[here] = true;
	std::cout << here << " ";

	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];

		if (!visited[there])
			dfs(there, adjs, visited);
	}
}

// BFS: 시작 노드부터 너비 우선 탐색하며 방문 순서 
void bfs(int start, vector<vector<int>> &adjs, vector<bool>& discovered) {
	queue<int> q;
	q.push(start);
	discovered[start] = true;

	while (!q.empty()) {
		// 방문
		int here = q.front();
		q.pop();
		cout << here << " ";

		// 전개
		for (int there : adjs[here]) {
			if (!discovered[there]) {
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int>> adjs(n+1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}

/*
	Note: 정점 정렬
	정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하므로
	입력이 끝난 후에는 정점마다 간선 정렬
*/
	for (int i = 1; i <= n; i++) {
		sort(adjs[i].begin(), adjs[i].end());
	}

	vector<bool> visited(n + 1, false);
	dfs(v, adjs, visited);

	cout << "\n";

	vector<bool> discovered(n + 1, false);
	bfs(v, adjs, discovered);

	return 0;
}