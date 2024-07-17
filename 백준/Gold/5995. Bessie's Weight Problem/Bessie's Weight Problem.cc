#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cstring> 
using namespace std; 

int dp[50010]; 
int arr[510];
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int h,n;  cin >> h >> n;    // 건초 양 , 개수 
    for(int i=0; i<n; i++)   cin >> arr[i]; 

    for(int i=0; i<n; i++){
        for(int j = arr[i]; j<=h; j++){
            dp[j] = max(dp[j], dp[j-arr[i]]+arr[i]); 
        }
    }
    cout << dp[h] << "\n"; 
}