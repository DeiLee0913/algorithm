#include <iostream>
#include <list>

using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		list<char> ls;
		auto it = ls.begin();

		for(char ch: s) {
			if (ch == '\n') break;
			else if (ch == '-') {
				if (it != ls.begin()) {
					--it;		// list의 bidirectional iterator에서는 --it / ++it가 더 깔끔하고 빠름
					it = ls.erase(it);
				}
			}
			else if (ch == '<') {
				if (it != ls.begin()) {
					--it;
				}
			}
			else if (ch == '>') {
				if (it != ls.end()) {
					++it;
				}
			}
			else {
				ls.insert(it, ch);
			}
		}

		for (auto ch : ls) {
			cout << ch;
		}
		cout << "\n";
	}

	return 0;
}