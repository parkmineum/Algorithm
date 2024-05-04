#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int n,m,key, key_num; 
int parent[51];
vector<int> know; 
vector<vector<int>> party(51);

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
    cin >> n >> m >> key;  // 사람의 수,  파티 수,  진실을 아는 사람 수    

    while(key--){        
        int t; cin >> t;  // 진실을 아는 사람들 
        know.push_back(t); 
    }
    for(int i=1; i<=n; i++)  parent[i] = i; 
    for(int i=0; i<m; i++){
        int p; cin >> p;      // 파티 참가 인원은 최소 1명 
        for(int j=0; j<p; j++){   // 인원 수 만큼 받기 
            int num, first_person; 
            if(j==0){     // 이렇게 작성하면, 벡터써서 또 반복문 이용할 필요가 없음.
                cin >> num;  first_person = num; 
            }  
            else{
                cin >> num; 
                Union(first_person,num); 
            }
            party[i].push_back(num);   // 같은 파티원들 묶기 
            // [[1,5],[2,6],[7],[8],[7,8],[9],...]
        }
    }
    for(auto& party_list : party){
        bool check = false;
        for(auto& person : party_list){   // [1,5]
            if(check) break;   // 하나라도 일치하면 그 파티는 참석 불가. 
            for(auto& key_person : know){
                if(find(person)==find(key_person)){
                    check = true;    
                    break; 
                }
            }
        }
        if(check) m--;    // 비밀 누설 
    }
    cout << m; 
}