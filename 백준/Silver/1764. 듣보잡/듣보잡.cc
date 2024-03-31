#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; 
    int n,m; 
 
    vector<string> str, ans; 
    cin >> n >> m; 

    for(int i=0; i<n+m; i++){
        cin >> s; 
        str.push_back(s);
    }
    sort(str.begin(), str.end()); 
    
    int cnt = 0;
    for(int i=0; i<n+m-1; i++){
        if(str[i]==str[i+1]){
            ans.push_back(str[i]); 
            cnt++; 
        }
    }

    cout << cnt << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << "\n"; 
    }
}