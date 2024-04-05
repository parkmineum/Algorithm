#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int k; 
vector<int> arr;  
vector<int> ans_tree[11];   // 방문 순서대로 저장되어야

void findCenter(int left, int right, int depth){

    if(depth==k)  return;


    int center = (left+right)/2;    // 3(루트 노드)
    ans_tree[depth].push_back(arr[center]); 
    findCenter(left,center-1,depth+1);   // 왼쪽 이분 탐색 
    findCenter(center+1,right,depth+1); 
}

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> k; 
    int n = pow(2,k)-1; 
    for(int i=1; i<=n; i++){
        int num; cin >> num; 
        arr.push_back(num);   // 1 6 4 3 5 2 7  // 빌딩 들어간 순서 
    }

    findCenter(0,arr.size(),0); 

    for(int i=0; i<k; i++){
        for(int j=0; j<ans_tree[i].size(); j++){
            cout << ans_tree[i][j] << " "; 
        }
        cout << "\n"; 
    }
}