#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std; 

int n, delete_node, root, leaf_cnt = 0;
vector<int>tree [51];

int dfs(int node){
    if(node==delete_node)  return -1;

    if(tree[node].size()==0){
        leaf_cnt++; 
        return 0;     // 재귀 종료 
    }

    for(int i=0; i<tree[node].size(); i++){
        int tmp = dfs(tree[node][i]); 

        // 제거할 노드를 제외하고 남은 노드가 1개여야 
        // 리프노드로써 의미가 있다. 
        if(tmp==-1 && tree[node].size() == 1)
            leaf_cnt++; 
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;  
    for(int i=0; i<n; i++){
        int parent;  cin >> parent; 
        if(parent==-1)   root = i;   // 0
        
        else{
            // 각 인덱스 별로 저장할 수 있는 원소 개수에 제한x
            tree[parent].push_back(i);
        }
    }
    cin >> delete_node;     // 지워야할 노드 번호에 해당
    dfs(root);

    cout << leaf_cnt; 
}