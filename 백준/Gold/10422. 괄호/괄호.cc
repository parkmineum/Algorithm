#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
#include <map> 
using namespace std; 

typedef long long ll; 
ll dp[5010]; 
ll num = 1000000007;
ll func(int L){
    if(L==0)  return 1; 
    if(dp[L]>0)  return dp[L];
    for(int i=2; i<=L; i+=2){ 
        dp[L] += (func(i-2) * func(L-i));     // 점화식 // 짝수번째마다 재귀
        dp[L] %= num;
    }
    return dp[L]; 
}
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    
    while(t--){
        int L; cin >> L;      // 괄호 문자열의 길이
        
        if(L%2!=0)  cout << 0 << "\n";      
        else     cout << func(L) << "\n"; 
    }
}