#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, height = 0; 
vector<int> tree[500001];
bool visited[500001]; 

void dfs(int node, int edge_cnt){    // 루트 노드부터 시작
    if(tree[node].size()==1 && node!=1){   // 자식 1개 == 간선 1개 
        height += edge_cnt;
        return; 
    }

    for(int i=0; i<tree[node].size(); i++){
        if(!visited[tree[node][i]]){
            visited[tree[node][i]] = true; 
            dfs(tree[node][i],edge_cnt+1); 
            visited[tree[node][i]] = false; 
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;   // 정점 개수 
    for(int i=0; i<n-1; i++){
        int node1, node2; 
        cin >> node1 >> node2;  
        tree[node1].push_back(node2);    // 양방향 
        tree[node2].push_back(node1);
    }
    visited[1] = true;
    dfs(1,0); 

    if(height%2==0)  cout << "No"<< "\n"; 
    else cout<< "Yes" << "\n"; 
}