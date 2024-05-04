#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int parent[1000001];

int find(int a){     // 특정 노드의 부모노드 찾기
    if(parent[a]==a) return a;     

    // 노드 a가 자신의 부모가 아닌 경우, 재귀로 부모 노드 찾기
    // 재귀 과정 속에서 각 노드의 부모가 업데이트 되므로 이를 '경로 압축'이라 함
    else   return parent[a] = find(parent[a]); 
}

void Union(int a, int b){   // 두 노드의 부모 노드 병합 
    int a_root = find(a); 
    int b_root = find(b); 

    // 이미 부모가 같다면, union 연산 수행할 필요 x 
    if (a_root == b_root) return; 

    // Union 연산 수행 
    parent[a_root] = b_root; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;  cin >> n >>m;  // {0}, {1}, {2}, ... , {n}

    for(int i=0; i<=n; i++){
        parent[i] = i;   
        // 각 노드의 부모 노드를 자기 자신으로 초기화
        // 이는 새로운 집합을 만드는 것으로, 각 노드를 자신만의 집합에 포함
    }

    int num,a,b; 
    while(m--){
        cin >> num >> a >> b; 
        
        if(num==0)  Union(a,b); 
        else{
            // 부모 노드가 같다면, 같은 집합에 속한다. 
            if(find(a)==find(b)) cout << "YES" << "\n";
            else   cout << "NO" << "\n"; 
        }
    }
    
}