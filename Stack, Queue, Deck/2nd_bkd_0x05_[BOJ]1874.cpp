#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie( nullptr );

	int n;
	cin >> n;

	bool flag = true;	// Flag indicating whether the sequence can be constructed
	stack<int> st;
	vector<char> pom;	// Stores the sequence of operations( + or - )
	
	vector<int> nums(n);
	for ( int i = 0; i < n; i++ ) {
		cin >> nums[ i ];
	}

	int it = 0;		// iterator for nums
	int i = 1;		// numbers to be pushed to stack from 1 to n

	// it < n 조건을 생각하지 못해서 좀 헤맴
	while( it < n ) {
		if ( !st.empty() && st.top() == nums[ it ] ) {
				st.pop();
				pom.push_back( '-' );
				it++;
			}
		else if ( st.empty() || st.top() <= nums[it] ) {
			st.push( i++ );
			pom.push_back( '+' );
		} else if ( st.top() > nums[it]) {
			flag = false;
			break;
		}
	}

	if ( flag ) {
		for ( char c : pom ) {
			cout << c << '\n';
		}
	}
	else {
		cout << "NO\n";
	}

	return 0;
}