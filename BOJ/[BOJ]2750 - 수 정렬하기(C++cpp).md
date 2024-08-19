# [BOJ]2750 - 수 정렬하기(C++/cpp)

## 문제

[https://www.acmicpc.net/problem/2750](https://www.acmicpc.net/problem/2750)


## 문제 풀이

## 아이디어

- 선택 정렬
- 삽입 정렬
- 버블 정렬

## ~ 코드 전문

```cpp
#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>& arr) {
	int min_idx;

	for (int i = 0; i < arr.size() - 1; i++) {
		min_idx = i;
		for (int j = i; j < arr.size(); j++)
			if (arr[j] < arr[min_idx]) 
				min_idx = j;
		if (min_idx != i)
			swap(arr[i], arr[min_idx]);
	}
}

void insertionSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) { 
		int key = arr[i];
		int j = i - 1;
		// vector subscript out of range와 같은 에러가 발생
		// while (arr[i] < arr[j] && j >= 0) {
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}

	return;
}

void bubbleSort(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) 
		for (int j = 1; j < arr.size() - i; j++) 
			if (arr[j - 1] > arr[j])
				swap(arr[j - 1], arr[j]);
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	// 입력
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	//연산
	//selectionSort(arr);
	//insertionSort(arr);
	bubbleSort(arr);

	//출력
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	return 0;
}
```

## 힘들었던 점

### Insertion Sort의 로직 오류

**내가 원래 쓴 코드**

```cpp
void insertionSort(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) { 
		int j = i - 1;
		// vector subscript out of range와 같은 에러가 발생
		// while (arr[i] < arr[j] && j >= 0) {
		while (j >= 0 && arr[i] < arr[j]) {
			swap(arr[i--], arr[j]);
			j--;
		}
	}
```

**문제점(chatGPT):**

1. **`swap(arr[i--], arr[j]);`**:
    - 여기서 `i--`는 `arr[i]`와 `arr[j]`를 스왑한 후 `i`의 값을 감소시킵니다. 삽입 정렬에서는 원래의 `i` 값은 변하지 않고, `j`만 감소해야 합니다. 하지만 이 코드는 `i`를 감소시키고 있어 잘못된 동작을 하게 됩니다.
    - `i`의 값이 계속 감소하면서 반복문이 돌게 되면, `i`의 값이 음수로 가게 되어 잘못된 인덱스에 접근할 가능성이 있습니다.
2. **`arr[i]`의 위치 변경**:
    - 일반적인 삽입 정렬에서는 **`*arr[i]`의 위치는 고정되고, `j`가***
    - ***이동하면서 `arr[j]`와 비교하여 필요할 때 `arr[j+1]`에 값을 삽입***합니다. 현재 코드는 `arr[i]`를 계속 바꿔가면서 `swap`하기 때문에 삽입 정렬과는 다릅니다.

**수정된 코드**

```cpp
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) { 
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

## 발전 가능한 아이디어

- advancedBubbleSort로 구현하기