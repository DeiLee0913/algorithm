#include <iostream>

using namespace std;

int q[100000];
int backIdx = 0, frontIdx = 0;


void push(int num) {
	q[backIdx++] = num;
}

int pop() {
	if (backIdx == frontIdx) {
		return -1;
	}
	else {
		return q[frontIdx++];
	}
}

int size(void) {
	return backIdx - frontIdx;
}

int empty(void) {
	return size() == 0;
}

int front() {
	if (empty()) {
		return -1;
	}
	return q[frontIdx];
}

int back() {
	if (empty()) {
		return -1;
	}
	else {
		return q[backIdx - 1];
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;


	while (n--) {
		string order; int num;
		cin >> order;

		if (order == "push") {
			cin >> num;
			push(num);
		}
		else if (order == "pop") {
			cout << pop() << "\n";
		}
		else if (order == "size") {
			cout << size() << "\n";
		}
		else if (order == "empty") {
			cout << empty() << "\n";
		}
		else if (order == "front") {
			cout << front() << "\n";
		}
		else if (order == "back") {
			cout << back() << "\n";
		}
		else {
			cout << "Wrong Input!\n";
		}
	}

	return 0;
}