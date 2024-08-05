#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, num, s, e; cin >> n; 
    vector<pair<int,bool>> vec;
    for(int i=0; i<n; i++){
        cin >> num >> s >> e; 
        vec.push_back({s,true}); vec.push_back({e,false}); 
        // {2,t}, {14,f}, {3,t}, {8,f} , ... 
    } 
    sort(vec.begin(),vec.end());   
    // {2,t}, {3,t}, {8,f}, ...   

    // t t t t t e  t  e  s  e  e  s 
    // 2 3 6 6 7 8 12 13 15 18  20  
    int ans = 0, cnt = 0; 
    for(int i=0; i<vec.size(); i++){
        if(vec[i].second)  cnt++; 
        else  cnt--; 
        ans = max(ans, cnt);    // 강의실 수 기억
    }
    cout << ans; 
}