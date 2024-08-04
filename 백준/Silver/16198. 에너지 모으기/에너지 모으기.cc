#include <iostream>
#include <vector>
 
using namespace std;
 
int n;
int ans=0;
 
vector<int> v;
 
 
void dfs(int sum){
 
    if(v.size() == 2){
        ans = max(ans, sum);
        return;
    }
    
    for(int i=1; i<v.size()-1; i++){
        
        int add = v[i-1] * v[i+1];
        int tmp = v[i];
        
        v.erase(v.begin()+i);
        dfs(sum + add);
        v.insert(v.begin()+i, tmp);
    }
}
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    
    int w;
    for(int i=0; i<n; i++){
        cin >> w;
        v.push_back(w);
    }
    
    dfs(0);
    cout << ans << endl;
}
