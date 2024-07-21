#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cstring> 
using namespace std;  
int dp[1001][1001]; 
int main(){
    
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string from, to;   cin >> from >> to;   // abc -> cba 
    
    int n = from.length(), m = to.length();
    for(int i=1; i<=n; i++)  dp[i][0] = i; 
    for(int j=1; j<=m; j++)  dp[0][j] = j; 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            // 공집합{} 부터 비교 // 두 문자가 같을 시 이전까지 비교한 내용으로 복사 
            if(from[i-1]==to[j-1])  dp[i][j] = dp[i-1][j-1]; 
            else  dp[i][j] = min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1)); 
        }
    }
    cout << dp[n][m] << "\n"; 
 }