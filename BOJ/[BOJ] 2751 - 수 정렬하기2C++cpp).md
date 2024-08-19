# [BOJ]2751 - 수 정렬하기 2(C++/cpp)

## 문제

[https://www.acmicpc.net/problem/2751](https://www.acmicpc.net/problem/2751)

![image.png](%5BBOJ%5D%202751%20-%20%E1%84%89%E1%85%AE%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF%E1%84%92%E1%85%A1%E1%84%80%E1%85%B5%202(C++%20cpp)%206cf80d8fae0a4799b037cf83be06212b/image.png)

## 문제 풀이

### 아이디어

- if 문을 통한 비교 함수
- 사용자 정의 함수를 이용한 sort

### ~ 코드 전문

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
	string name;
	int kor, eng, math;
};

bool cmp(const student& s1, const student& s2) {
	if (s1.kor == s2.kor)
	{
		if (s1.eng == s2.eng) {
			if (s1.math == s2 .math) {
				// 이름이 사전 순으로 증가하는 순서
				return s1.name < s2.name;
			}
			// 수학 점수가 감소하는 순서
			return s1.math > s2.math;
		}
		// 영어 점수가 증가하는 순서
		return s1.eng < s2.eng;
	}
	// 국어 점수가 감소하는 순서
	return s1.kor > s2.kor;
}

bool advCmp(const student& s1, const student& s2) {
	if (s1.kor != s2.kor)
		return s1.kor > s2.kor;
	if (s1.eng != s2.eng)
		return s1.eng < s2.eng;
	if (s1.math != s2.math)
		return s1.math > s2.math;
	return s1.name < s2.name;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;

	//입력
	cin >> n;
	vector<student> students(n);

	for (int i = 0; i < n; i++) {
		cin >> students[i].name >> students[i].kor >> students[i].eng >> students[i].math;
	}

	//연산
	sort(students.begin(), students.end(), advCmp);

	//출력
	for (int i = 0; i < n; i++) {
		//endl 쓰면 시간 초과 된다...
		cout << students[i].name << "\n";
	}

	return 0;
}
```