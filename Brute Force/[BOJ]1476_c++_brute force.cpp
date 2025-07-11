#include <iostream>

using namespace std;

int min_rotate(int e, int s, int m) {
	int e_ = 1, s_ = 1, m_ = 1;
	int cnt = 1;

	while (true) {
		if (e_ == e && s_ == s && m_ == m) {
			break;
		}

		e_++; s_++; m_++; cnt++;

		if (e_ > 15) e_ = 1;
		if (s_ > 28) s_ = 1;
		if (m_ > 19) m_ = 1;
	}

	return cnt;
}

int main() {
	int e, s, m;
	cin >> e >> s >> m;

	//while (true) {
	//	if (e == e_ || (e == 15 && e_ == 0)) {
	//		if (s == s_ || (s == 28 && s_ == 0)) {
	//			if (m == m_ || (m == 19 && m_ == 0)) {
	//				break;
	//			}
	//		}
	//	}

	//	++e_ %= 15;
	//	++s_ %= 28;
	//	++m_ %= 19;

	//	cnt++;
	//}

	cout << min_rotate(e, s, m);

	return 0;
}