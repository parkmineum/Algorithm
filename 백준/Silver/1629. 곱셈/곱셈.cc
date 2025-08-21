#include <iostream> 
using namespace std; 

using ll = long long; 
ll a,b,c; 
ll POW(ll a, ll b, ll c){ 
    if(b==1) return (a*1)%c; 

    ll val = POW(a,b/2,c);     // a^(b/2)
    val = val * val % c;       // (a^b/2)*(a^b/2) % c // val^2 % c; 

    if(b%2==0)   return val; 
    return a * val % c;    // 홀수라면, a가 하나 괄호 밖으로 나오기 때문
}

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> b >> c; 
    cout << POW(a,b,c); 
}