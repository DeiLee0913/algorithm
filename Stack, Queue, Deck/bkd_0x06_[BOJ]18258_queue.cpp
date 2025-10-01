#include <iostream>
#include <queue>

using namespace std;

queue<int> q;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	while (n--) {
		string order; int num;
		cin >> order;

		if (order == "push") {
			cin >> num;
			q.push(num);
		}
		else if (order == "pop") {
			if (q.empty()) {
				cout << "-1\n";
				continue;
			}
			cout << q.front() << "\n";
			q.pop();
		}
		else if (order == "size") {
			cout << q.size() << "\n";
		}
		else if (order == "empty") {
			q.empty() ? cout << "1\n" : cout << "0\n";
		}
		else if (order == "front") {
			q.empty() ? cout << "-1\n" : cout << q.front() << "\n";
		}
		else if (order == "back") {
			q.empty() ? cout << "-1\n" : cout << q.back() << "\n";
		}
		else {
			cout << "Wrong Input!\n";
		}
	}

	return 0;
}