#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int round = 0;
	while(++round) {
		string instr;
		cin >> instr;
		
		if (instr[0] == '-') {
			break;
		}
	
		int ans = 0;

		stack<char> st;

		for (char ch : instr) {
			if (!st.empty() && st.top() == '{' && ch == '}') {
				st.pop();
			}
			else {
				st.push(ch);
			}
		}

		while (st.size() >= 2) {
			char a = st.top(); st.pop();
			char b = st.top(); st.pop();

			if (a == b) {
				ans += 1;
			}
			else ans += 2;
		}

		cout << round << ". " << ans << "\n";
	}

	return 0;
}