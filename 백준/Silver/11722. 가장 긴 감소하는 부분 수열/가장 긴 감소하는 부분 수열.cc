#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 


int arr[1001], dp[1001]; 
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    for(int i=0; i<n; i++) cin >> arr[i];  // 10 30 10 20 20 10
    
    int ans = 0; 
    for(int i=0; i<n; i++){
        dp[i] = 1; 
        for(int j=0; j<i; j++){
            if(arr[i]<arr[j]) dp[i] = max(dp[i], dp[j]+1);
        }
        ans = max(ans, dp[i]); 
    }
    cout << ans; 
}