#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int N,M; 
int parent[1000001]; 
int find(int node){
    if(parent[node]==node)   return node; 
    else   return parent[node] = find(parent[node]); 
}

void Union(int a, int b){ 
    int root_a = find(a);
    int root_b = find(b); 

    if(root_a == root_b)  return; 
    parent[root_a] = root_b; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		parent[i] = i;

    for(int i=0; i<M; i++){
        int a,b; cin >> a >> b; 
        if(find(a)==find(b)){     // 둘이 연결되어 있다면,
            cout << i+1;
            return 0;      // 출력하고 main 종료(중요)
        }
        else  Union(a,b); 
    }
    cout << 0; 
}