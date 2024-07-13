#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

typedef long long ll;
ll arr[1000010]; 
ll sum[1000010];
ll cnt[1010];   
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,m;   cin >> n >> m; 
    for(int i=1; i<=n; i++){
        cin >> arr[i]; 
        sum[i] = (sum[i-1] + arr[i]) % m;   // 구간합 나머지
        cnt[sum[i]] += 1;     // 나머지 값 개수 카운트
    }  
    
    // Ai + ... + Aj 중 (i,j)쌍의 개수 구해야 
    ll ans = 0; 
    for(int i=0; i<m; i++) ans += cnt[i]*(cnt[i]-1);   // 나머지가 i에 대해 (i,j)쌍 선택하기
    ans /= 2;              // 중복 제거 (조합)
    ans += cnt[0];         // 나머지가 0인 경우 카운트

    cout << ans;
}