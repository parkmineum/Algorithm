#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

 
int dp[4010][4010] = {0, }; 
int main(){ 
    string s1, s2;  cin >> s1 >> s2; 
    int a = s1.length(), b = s2.length(); 

    int ans = 0; 
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; 
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}