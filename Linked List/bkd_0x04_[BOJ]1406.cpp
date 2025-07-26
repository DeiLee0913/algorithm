#include <iostream>
#include <list>

using namespace std;

int main() {
	list<char> editer;
	
	string orig;
	cin >> orig;
	for(auto c: orig) {
		editer.push_back(c);
	}

	auto it = editer.end();
	int num; char cmd;
	


	cin >> num;
	
	for (int i = 0; i < num; i++) {
		cin >> cmd;
		if (cmd == 'L' && it != editer.begin()) {
			it--;
		}
		if (cmd == 'D' && it != editer.end()) {
			it++;
		}
		if (cmd == 'B' && it != editer.begin()) {
			editer.erase(prev(it));
		}
		if (cmd == 'P') {
			char c;
			cin >> c;

			editer.insert(it, c);
		}
	}

	for (char c : editer) {
		cout << c;
	}
	cout << "\n";

	return 0;
}