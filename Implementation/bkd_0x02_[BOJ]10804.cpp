#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> cards(21);

	for (int i = 1; i < 21; i++) {
		cards[i] = i;
	}

	/*
	reverse()를 이용한 풀이
	everse(begin, end)는 [begin, end) 범위를 뒤집으므로 b+1까지 넣어야 b까지 포함됨
	*/
	int a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		reverse(cards.begin() + a, cards.begin() + b + 1);
	}


	// 스택을 이용한 풀이
	//for (int i = 0; i < 10; i++) {
	//	cin >> a >> b;
	//	stack<int> cnt;

	//	for (int j = a; j <= b; j++) {
	//		cnt.push(cards[j]);
	//	}

	//	for (int j = a; j <= b; j++) {
	//		cards[j] = cnt.top();
	//		cnt.pop();
	//	}
	//}

	for (int i = 1; i < 21; i++) {
		cout << cards[i] << " ";
	}

	return 0;
}