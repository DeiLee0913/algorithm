#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<pair<int, int>> tops;
	for (int i = 1; i <= n; i++) {
		int top;
		cin >> top;
		tops.push_back(make_pair(i, top));
	}

	stack<pair<int, int>> st;
	vector<int> answers(n);
	for (int i = 0; i < n; i++) {
		// 현재 탑 높이보다 큰 탑이 나올 때까지 stack 탐색
		while (!st.empty() && tops[i].second > st.top().second) {
			st.pop();
		}

		// 스택이 비었다면, 즉 본인보다 높은 탑이 없다면 정답으로 0 출력
		if (st.empty()) {
			answers[i] = 0;
			// 본인보다 높은 탑이 스택에, 즉 본인보다 왼쪽에 있다면 몇 번째 탑인지 저장
		}
		else {
			answers[i] = st.top().first;
		}

		// 오른쪽의 탑에서 높이 비교할 수 있도록 스택에 저장
		st.push(tops[i]);
	}

	for (int answer : answers) {
		cout << answer << " ";
	}

	return 0;
}