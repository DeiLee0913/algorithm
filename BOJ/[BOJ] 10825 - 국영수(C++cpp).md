# [BOJ] 10825 - 국영수(C++/cpp)

## 문제

[https://www.acmicpc.net/problem/10825](https://www.acmicpc.net/problem/10825)


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

### 힘들었던 점

- 비교 함수를 써보는 처음 문제라서 사용자 정의 함수를 sort에 사용할 수 있는지 몰랐다.
    
    [비교 구문과 sort 함수](https://www.notion.so/sort-79318028f6aa476596d3b1ab2bec85f6?pvs=21) 
    
- 시간 초과로 계속 실패했는데, “\n”이 아닌 endl을 사용해서 그렇다고 한다.
    
    [endl과 “/n”의 차이점](https://www.notion.so/endl-n-bdf671c4cb6b48949febd3ee79ccc3bc?pvs=21)