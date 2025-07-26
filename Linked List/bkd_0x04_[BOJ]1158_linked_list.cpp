#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    list<int> ppl;
    for (int i = 1; i <= n; ++i) {
        ppl.push_back(i);
    }

    auto it = ppl.begin();
    cout << "<";

    while (!ppl.empty()) {
        // k-1번 이동
        for (int i = 0; i < k - 1; ++i) {
            ++it;
            if (it == ppl.end()) it = ppl.begin();
        }

        // 현재 값 출력
        cout << *it;

        // 다음 요소를 가리키도록 이동 후 현재 삭제
        it = ppl.erase(it);
        if (it == ppl.end()) it = ppl.begin();

        // 출력 포맷 처리
        if (!ppl.empty()) {
            cout << ", ";
        }
    }

    cout << ">" << '\n';
    return 0;
}
