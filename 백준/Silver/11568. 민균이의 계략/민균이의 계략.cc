#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

int arr[1010], dp[1010]; 
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    for(int i=0; i<n; i++)  cin >> arr[i];  // 8 9 1 2 10 

    int max_cnt = 0; 
    for(int i=0; i<n; i++){
        dp[i] = 1; 
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1); 
            }
        }
        max_cnt = max(max_cnt, dp[i]); 
    }
    cout << max_cnt; 
}
