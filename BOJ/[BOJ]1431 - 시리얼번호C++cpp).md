# [BOJ] 1431 - 시리얼 번호

## 문제

## 문제 풀이

### 아이디어

- if 문을 통한 비교 함수
- 사용자 정의 함수를 이용한 sort
- 문자열에서 숫자 골라내기

### ~ 코드 전문

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int sum(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
		if (isdigit(s[i]))
			ans += s[i] - '0';
	return ans;
}

bool cmp(string& s1, string& s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	if (sum(s1) != sum(s2))
		return sum(s1) < sum(s2);
	return s1 < s2;
}

int main()
{
	int n;

	//입력
	cin >> n;
	
	vector<string> serials(n);

	for (int i = 0; i < n; i++)
		cin >> serials[i];

	// 연산
	sort(serials.begin(), serials.end(), cmp);

	// 출력
	for (int i = 0; i < n; i++)
		cout << serials[i] << "\n";

	return 0;
}
```

### 힘들었던 점

- 문자열에서 숫자를 골라내는 방법
    
    ```cpp
    isdigit(s[i])
    ```
    
- 문자의 숫자합을 구하는 올바른 방법
    
    숫자 문자 `'0'`부터 `'9'`는 ASCII 값으로 각각 48부터 57까지 할당되어 있습니다. 따라서 문자를 숫자로 변환하려면 `'0'`의 ASCII 값을 빼줘야 합니다. 이를 적용한 올바른 코드는 다음과 같습니다:
    
    ```cpp
    int sum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                ans += s[i] - '0'; // 문자 '0'의 ASCII 값을 빼줌으로써 숫자 값으로 변환
            }
        }
        return ans;
    }
    
    ```