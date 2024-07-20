#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cstring> 
using namespace std; 

int study[1010], score[1010]; 
int dp[110][10010]; 
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,t;    cin >> n >> t;
    // 단원 별 예상 공부 시간 , 단원 배점
    for(int i=1; i<=n; i++)  cin >> study[i] >> score[i];  
    for(int i=1; i<=n; i++){
        for(int j=1; j<=t; j++){
            if(j-study[i]>=0)  dp[i][j] = max(dp[i-1][j],dp[i-1][j-study[i]]+score[i]); 
            else  dp[i][j] = dp[i-1][j]; 
        }
    }
    cout << dp[n][t] << "\n"; 
}