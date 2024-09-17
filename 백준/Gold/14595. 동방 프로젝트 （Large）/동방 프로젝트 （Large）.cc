#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
#include <map> 
using namespace std; 

int n,m, x,y;  
int arr[1000010]; 
int find(int a){
    if(arr[a] == a)  return a; 
    else  return arr[a]  = find(arr[a]); 
}
void Union(int x, int y){
    x = find(x);  y = find(y); 
    if(x==y) return ; 
    arr[x] = y;  
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;     // 동방 개수, 행동 횟수 
    for(int i=1; i<=n; i++) arr[i] = i; 

    int cnt = n;
    for(int i=0; i<m; i++){ 
        cin >> x >> y;    // x번방 ~ y번방 벽 무너뜨림  // 중복 허용 
        // 1 2 , 2 4   
        // (1 2) 3 4 5  ->  (1 2 3 4) 5   4개 -> 2개( |x-y|개 만큼 생성)\

        x--; y--; 
        while(find(x) != find(y)){ 
            cnt--;   // 서로 다른 그룹 합칠때마다, 
            int next = find(x) + 1; 

            Union(x,y); 
            x = next; 
        }
    }
    cout << cnt << "\n";
}