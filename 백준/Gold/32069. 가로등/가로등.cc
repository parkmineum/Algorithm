#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std; 

typedef long long ll;
ll L, x;   int n, k;  
queue<pair<ll,ll>> q; 
int dx[2] = {-1, 1}; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> L >> n >> k;
    set<ll> visited;
    for(int i=0; i<n; i++){
        cin >> x;                   // 가로등 위치 
        q.push({x,0});              // {1,0} , {4,0} , {8,0}
        visited.insert(x);  
    }
    while(!q.empty()){    // k번 출력
        ll now = q.front().first;  ll dist = q.front().second; 
        cout << dist << "\n"; 

        q.pop();   k--; 
        if(k==0)  return 0; 

        for(int i=0; i<2; i++){     // 탐색 방향 2가지(왼/오)
            ll next = now + dx[i];   
            if(next>=0 && next<=L && visited.find(next) == visited.end()){ 
                q.push({next, dist + 1});     
                visited.insert(next); 
            }   
        }
    }
}