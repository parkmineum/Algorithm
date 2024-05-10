#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;

    deque<pair<string, int>> dq;
    for (int i = 0; i < n; i++) {
        string x; int num;
        cin >> x >> num;
        dq.push_back(make_pair(x, num));  
    }

    while (n > 1) {
        // pair 한 쌍, mate라는 변수에 그대로 저장
        pair<string, int> mate = dq.front();  
        dq.pop_front();     // 가장 앞에 선 학생 

        for (int i = 0; i < mate.second - 1; i++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        dq.pop_front();
        n -= 2;        // 짝을 찾은 팀 out 
    }

    cout << dq.front().first << "\n";
}
