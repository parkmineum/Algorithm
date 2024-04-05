#include <iostream> 
#include <vector> 
#include <algorithm>
using namespace std; 
   
void post_order(vector<int>& tree){
    if(tree.size() == 1){
        cout << tree[0] << " ";
        return; 
    }

    int center = tree.size()/2; 
    vector<int> left(tree.begin(),tree.begin()+center); 
    vector<int> right(tree.begin()+(center+1),tree.end());

    post_order(left); 
    post_order(right);
    cout << tree[center] << " "; 
    return;
}
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    vector<int> tree(n,0); 
    for(int i=0; i<n; i++){
        cin >> tree[i];    // -1 : 가려진 노드 // 10 5 17 1 -1 14 21 
    }
    int x; cin >> x; 
    for(int i=0; i<n; i++){
        if(tree[i]==-1)  tree[i] = x;
    }
    sort(tree.begin(),tree.end());
    post_order(tree);
}