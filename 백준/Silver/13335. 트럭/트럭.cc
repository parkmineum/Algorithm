#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std;

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, w, l;  cin >> n >> w >> l;

    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x;  cin >> x;
        q.push(x);
    }

    int ans = 0;
    int bridge_weight = 0;
    queue<int> on_bridge;

    while (!q.empty()) {
        if (on_bridge.size() == w) {
            bridge_weight -= on_bridge.front();
            on_bridge.pop();
        }

        if (bridge_weight + q.front() <= l) {
            on_bridge.push(q.front());
            bridge_weight += q.front();
            q.pop();
        }
        else {
            on_bridge.push(0);
        }

        ans++;
    }

    ans += w;
    cout << ans << "\n";
}
