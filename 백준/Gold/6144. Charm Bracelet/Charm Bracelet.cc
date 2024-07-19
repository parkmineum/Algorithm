#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cstring> 
using namespace std; 
int dp[12900]; 
int w[3410],d[3410]; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;  cin >> n >> m;
    for(int i=1; i<=n; i++) cin >> w[i] >> d[i];
    for(int i=1; i<=n; i++){
        for(int j=m; j>=w[i]; j--){
            dp[j] = max(dp[j],dp[j-w[i]]+d[i]); 
        }
    }
    cout << dp[m] << "\n"; 
}