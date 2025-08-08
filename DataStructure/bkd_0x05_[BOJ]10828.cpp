#include <iostream>

using namespace std;

const int MX = 10005;
int stack[MX];
int pos = 0;

int size( void ) {
	return pos;
}

void push(int x) {
	stack[pos++] = x;
}

int empty( void ) {
	return size() == 0 ? 1 : 0;
}

int pop(void) {
	if ( empty() ) {
		return -1;
	}
	else {
		return stack[ --pos ];
	}
}

int top(void) {
	if ( empty() ) {
		return -1;
	}
	else {
		return stack[ pos - 1 ];
	}
}



int main() {
	ios::sync_with_stdio( false );
	cin.tie( nullptr );

	int n;
	cin >> n;


	string order;
	int num;

	while ( n-- ) {
		cin >> order;

		if ( order == "push" ) {
			cin >> num;
			push( num );
		}
		else if ( order == "top" ) {
			cout << top() << "\n";
		}
		else if ( order == "pop" ) {
			cout << pop() << "\n";
		}
		else if ( order == "empty" ) {
			cout << empty() << "\n";
		}
		else if ( order == "size" ) {
			cout << size() << "\n";
		}
	}

	return 0;
}