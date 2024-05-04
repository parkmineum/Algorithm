#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;   
int n,parent,child,weight;
int circle_len = 0;   // 지름 길이  
int end_node = 0;   // 지름 끝점(반대편)
vector<pair<int,int>> node[10001];
bool visited[10001] = {0, }; 

void dfs(int k, int weight){
    if(visited[k]) return; 

    visited[k] = 1;
    if(circle_len < weight){
        circle_len = weight; 
        end_node = k; 
    } 

    for(int i=0; i<node[k].size(); i++){  
        dfs(node[k][i].first, node[k][i].second + weight); 
    }
}

int main(){  
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;   // 노드의 개수 
    for(int i=0; i<n-1; i++){
        cin >> parent >> child >> weight;  // 부모, 자식, 가중치 
        node[parent].push_back({child,weight});
        node[child].push_back({parent,weight}); 
    }
    dfs(1,0);      // 루트 노드 ->> 가장 먼 노드 

    circle_len = 0; 
    fill(visited,visited+sizeof(visited),0);    

    dfs(end_node,0);   //  루트에서 가장 먼 노드 기준 ->> 가장 먼 노드

    cout << circle_len; 
 }