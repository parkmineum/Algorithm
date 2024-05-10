#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std;

// 양 쪽 끝은 물을 채울 수 없다는 것을 간과하면 안된다. 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int sero, garo; cin >> sero >> garo;
    vector<int> block(garo);

    for (int i = 0; i < garo; i++) {
        cin >> block[i];
    }
    int ans = 0; 
    for (int i = 1; i < garo - 1; i++) {   // 양쪽 끝 배제
        int left_max = 0, right_max = 0; 
        for (int j = 0; j < i; j++)  left_max = max(left_max, block[j]); 
        for (int j = garo - 1; j > i; j--)   right_max = max(right_max, block[j]); 

        // 가장 직관적인 로직이 양 쪽 제외하고, block에서 두번째로 큰값을 
        // 모든 block을 돌면서 뺀 값을 더하는 것이 결괏값이다. 
        ans += max(0, min(left_max, right_max) - block[i]); 
    }
    cout << ans << "\n"; 
}