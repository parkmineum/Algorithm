#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

// 연속된 게이트를 하나의 집합으로 묶어주는게 포인트 
// 비행기는 1번부터 g번 게이트 중 하나에 도킹 가능. 꽉차면 더이상 도킹 불가능 
// g번 게이트부터 차례로 도킹. g -> g-1 -> g-2 -> ... 1번까지 도킹. 
// 도킹 시, g번 게이트와 g-1번게이트 합치기. g번 게이트가 0이 아니라면
// 도킹 가능한 게이트가 적어도 한개 남았다는 뜻. 
// 0이 되면 즉시 종료해야 
int g,p; 
int parent[100001]; 

int find(int node){
    if(parent[node]==node) return node; 
    else  return parent[node] = find(parent[node]); 
}

void Union(int a, int b){
    int root_a = find(a); 
    int root_b = find(b); 

    if(root_a == root_b) return; 
    parent[root_a] = root_b; 
}

int main(){
    cin >> g >> p;    // 게이트 수, 비행기 수 
    for(int i=1; i<=g; i++)   parent[i] = i; 

	int res = 0; 
	while (p--) {
		int node; cin >> node;
		if (find(node) == 0) break;
		else {
			res++;
			Union(find(node), find(node)-1);
		}
	}
	cout << res;
}