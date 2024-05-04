#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll ;  



int a[4001], b[4001], c[4001], d[4001]; 
vector<ll> ab,cd;  
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin >> n; 
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];  
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ab.push_back(a[i]+b[j]);   // a+b 쌍
            cd.push_back(c[i]+d[j]);   // c+d 쌍 
        }
    }
    sort(ab.begin(),ab.end()); 
    sort(cd.begin(),cd.end()); 

    ll ans = 0; 
    for(int i=0; i<ab.size(); i++){
        int front_B_idx = lower_bound(cd.begin(),cd.end(),-ab[i]) - cd.begin();
        int end_B_idx = upper_bound(cd.begin(),cd.end(),-ab[i]) - cd.begin(); 

        ans += (end_B_idx-front_B_idx); 
    }

    cout << ans ;


}