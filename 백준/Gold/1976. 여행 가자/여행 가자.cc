#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int parent[201]; 
vector<int> path;
int find(int tmp){ 
    if(parent[tmp]==tmp)  return tmp; 
    else   return  parent[tmp] = find(parent[tmp]); 
}
void Union(int a, int b){
    int a_root = find(a); 
    int b_root = find(b); 

    if(a_root == b_root) return; 
    parent[a_root] = b_root; 
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;  cin >> n >> m; 
    for(int i=1; i<=n; i++)  parent[i] = i; 
    
    // 도시 연결 정보
    for(int i=1; i<=n; i++){    
        for(int j=1; j<=n; j++){
            int tmp; cin >> tmp; 
            if(tmp==1)  Union(i,j); 
        }
    }
    // 여행 계획 
    path.resize(m+1); 
    for(int i=1; i<=m; i++){
        cin >> path[i];
    }

    bool check = true; 
    for(int i=1; i<m; i++){
        if(find(path[i])!=find(path[i+1])){
            check = false; 
            break; 
        }
    }
    if(check)  cout << "YES" << "\n"; 
    else cout << "NO" << "\n";  

}