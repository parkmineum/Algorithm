#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cstring> 
using namespace std; 

int imp[100010], time[10010]; 
int dp[1010][10010]; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;  cin >> n >> k;  
    for(int i=1; i<=k; i++) cin >> imp[i] >> time[i]; 

    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(j-time[i]>=0)  dp[i][j] = max(dp[i-1][j],dp[i-1][j-time[i]]+imp[i]); 
            else  dp[i][j] = dp[i-1][j]; 
        }
    }
    cout << dp[k][n] << "\n"; 
}