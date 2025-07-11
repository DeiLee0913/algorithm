#include <iostream>

using namespace std;

// 유클리드 호제법을 이용한 최대 공약수 구하기
int gcd(int a, int b) {
	while (b != 0) {
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

// 최소 공배수
int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << gcd(a, b) << "\n" << lcm(a, b);
	
	return 0;
}