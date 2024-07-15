#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int dp[101][100001];
int weight[101];
int value[101];
int n, k;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)   cin >> weight[i] >> value[i];
 
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            //물건을 넣을 수 있는 경우
            if (j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            //물건을 넣을 수 없는 경우
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][k];
}
