# [BOJ]23881  알고리즘 수업 - 선택 정렬 1(C++/cpp)

## 문제

![image.png]
https://www.acmicpc.net/problem/23881
(%5BBOJ%5D23881%20%E1%84%8B%E1%85%A1%E1%86%AF%E1%84%80%E1%85%A9%E1%84%85%E1%85%B5%E1%84%8C%E1%85%B3%E1%86%B7%20%E1%84%89%E1%85%AE%E1%84%8B%E1%85%A5%E1%86%B8%20-%20%E1%84%89%E1%85%A5%E1%86%AB%E1%84%90%E1%85%A2%E1%86%A8%20%E1%84%8C%E1%85%A5%E1%86%BC%E1%84%85%E1%85%A7%E1%86%AF%201(C++%20%20b0708f5075ec4b58804ae664b3aba90b/image.png)

## 문제 풀이

### 아이디어

- **뒤에서부터 선택 정렬**을 수행합니다.
- 정렬 과정에서 발생하는 **swap 횟수를 추적**하고, 해당 횟수가 주어진 `k` 값과 일치하면 해당 시점에서 **정지**하고 결과를 출력합니다.

### 코드 구현

```cpp
cpp코드 복사
#include <iostream>#include <vector>using namespace std;

bool selectionSortBreak(vector<int>& arr, int k) {
    int max_idx, change_num = 0;

    for (int i = arr.size() - 1; i > 0; i--) {
        int max_idx = 0;
        for(int j = 0; j <= i; j++) {
            if (arr[j] > arr[max_idx])
                max_idx = j;
        }

        if (arr[i] != arr[max_idx]) {
            if (++change_num == k) {
                cout << arr[i] << " " << arr[max_idx] << endl;
                return true;
            }
            swap(arr[max_idx], arr[i]);
        }
    }
    return false;
}

int main() {
    int n, k;

    // 입력
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // 연산 & 출력
    if(!selectionSortBreak(arr, k))
        cout << -1;

    return 0;
}

```

### 어려웠던 점/ 피드백

- 선택 정렬을 **끝에서부터** 구현하는 부분에서 생각보다 시간이 걸렸습니다.
- 문제에서 제시된 **의사코드를 실제 코드로 변환**하는 과정이 예상보다 까다로웠습니다.
- 출력 형식에 대한 사소한 실수로 인해 한 번 틀렸습니다. 구체적으로는 두 수 사이에 **공백을 포함**해야 한다는 점을 놓쳤습니다.
    
    ```cpp
    cout << arr[i] << " " << arr[max_idx] << endl;
    ```
    

⇒ 이번 문제를 통해 오랜만에 알고리즘 문제를 풀다 보니 감을 잡는 데 시간이 걸렸지만, 다음번엔 더 잘할 수 있을 것 같습니다.