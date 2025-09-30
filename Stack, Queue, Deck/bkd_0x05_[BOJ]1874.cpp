#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio( false );
	cin.tie( nullptr );

	int n; cin >> n;

	vector<int> nums;			// 입력으로 주어진 수열
	bool ava_flag = true;		// 수열 출력이 가능한지 여부 판단
	vector<bool> push_or_pop;	// 결과 출력용 연산 기록 true: push / false: pop

	int num;
	for ( int i = 0; i < n; i++) {
		cin >> num;
		nums.push_back( num );
	}

	stack<int> st;
	int it = 0;			// 현재 nums에서 비교 중인 인덱스
	int cnt = 0;		// 1부터 차례대로 스택에 push할 값

	while ( it < n ) {	
		// 스택이 비어있거나, 현재 필요한 숫자보다 작은 숫자를 더 push해야 하는 경우
		if ( st.empty() || nums[ it ] > st.top() ) {
			st.push( ++cnt );
			push_or_pop.push_back( true );
		}
		// 스택의 top이 현재 필요한 숫자인 경우
		else if ( nums[ it ] == st.top() ) {
			it++;
			st.pop();
			push_or_pop.push_back( false );
		}
		// 스택의 top이 현재 필요한 숫자보다 큰 경우 → 불가능한 수열
		else if ( nums[ it ] < st.top() ) {
			ava_flag = false;
			break;
		}
	}

	if ( !ava_flag ) {
		cout << "NO\n";
	}
	else {
		for ( bool p : push_or_pop ) {
			p ? cout << "+\n" : cout <<"-\n";
		}
	}

	return 0;
}