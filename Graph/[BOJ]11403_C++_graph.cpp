#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;

// DFS: here 노드에서 도달 가능한 모든 노드를 visited에 기록
void dfs(int here, vector<vector<int>>& adj, vector<bool>& visited) {
	/*
	자기 자신에 대해서 항상 1을 출력하지 않게 하기 위해서
	visited는 there로서 방문 당할 때만 true로 설정되도록
	visited[there] = true;는 반복문 안에 배치
	*/

	//visited[here] = true;
	
	for (int there = 0; there < adj.size(); there++) {
		// note: here 노드에서 there 노드로의 도달 가능성과 방문 여부 동시 확인
		if (adj[here][there] == 1 && !visited[there]) {
			visited[there] = true;
			dfs(there, adj, visited);
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	// 인접 행렬 입력
	vector<vector<int>> adj(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}

	// 각 노드 i에 대해 도달 가능한 노드 j를 찾음
	for (int i = 0; i < n; i++) {
		vector<bool> visited(n, false);
		dfs(i, adj, visited);

		for (int j = 0; j < n; j++) {
			cout << (visited[j] ? 1 : 0) << " ";
		}

		cout << "\n";
	}

	return 0;
}