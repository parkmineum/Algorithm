#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

using ll = long long;

ll n, m, trash = 0, ans = 0;
ll room[100][100];

void clean(ll x, ll y) {
    if (x == n - 1 && y == m - 1) {
        if (room[x][y] == 1) {
            trash--;
            room[x][y] = 0;        
        }
        return;
    }
    for (ll i = x; i < n; i++) {
        for (ll j = y; j < m; j++) {
            if (room[i][j] == 1) {
                room[i][j] = 0;
                trash--;
                clean(i, j);              
                return;
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) { 
            cin >> room[i][j];
            if (room[i][j] == 1) trash++;
        }
    }
    while (trash > 0) {
        ans++;
        if (room[0][0] == 1) {
            room[0][0] = 0;
            trash--;
        }
        clean(0, 0);
    }
    cout << ans;
}