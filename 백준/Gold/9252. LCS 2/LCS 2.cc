#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

int dp[1010][1010] = {0, }; 
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1, s2;  cin >> s1 >> s2; 
    int a = s1.length(), b = s2.length(); 
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1; 
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
        }
    }
    cout << dp[a][b] << "\n"; 

    string res;
    while(a>0&&b>0){
        if(dp[a-1][b]==dp[a][b]) a--;
        else if(dp[a][b-1]==dp[a][b]) b--; 
        else{
            res += s1[a-1]; 
            a--; b--; 
        }
    }
    reverse(res.begin(), res.end()); 
    if(res.size()>0) cout << res << "\n"; 
    
    return 0; 
}