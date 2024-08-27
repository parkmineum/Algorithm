#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <cstring> 
 
using namespace std; 
int n, c;
int dp[10010];
pair<int, int> candy[5001]; // 칼로리, 가격 순
double m, p;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1){
        memset(dp, 0, sizeof(dp));
        cin >> n >> m;

        if(n == 0)   break;

        for(int i = 0; i < n; i++){
            cin >> c >> p;
            candy[i] = make_pair(c, (int)(p * 100 + 0.5));
        }

        
        int M = (int)(m * 100 + 0.5);
        int ans = 0; 
        for(int i = 0; i < n; i++){
            for(int j = candy[i].second; j <= M; j++){
                dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);
                ans = max(ans,dp[j]);
            }
        }

        cout << ans << '\n';
    }
}
 