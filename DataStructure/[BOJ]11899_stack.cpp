#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string instr;
	cin >> instr;

	int ans = 0;

	stack<char> st;

	for (char ch : instr) {
		if (!st.empty() && st.top() == '(' && ch == ')') {
			st.pop();
		}
		else {
			st.push(ch);
		}
	}
	
	ans += st.size();

	cout << ans;

	return 0;
}