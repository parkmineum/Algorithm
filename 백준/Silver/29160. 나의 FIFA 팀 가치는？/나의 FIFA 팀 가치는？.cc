#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

// 스택,큐,배열 -> 최대/최소 O(n)
// 우선순위 큐 -> 최대/최소 O(logn)
int main(){
    int n,k;  cin >> n >> k;   // 선수의 수, k년

    vector<priority_queue<int>> v(12); 
    bool p_check[12] = {false, }; 
    while(n--){
        // 해당 포지션(1~11)에 선수 없을 경우, 공석 처리 
        int position, weight;   cin >> position >> weight; 
        v[position].push(weight); 
        if(!p_check[position]) p_check[position] = true;
    }

    // 매년 11월에 새로운 팀 구성 
    for(int i=0; i<k; i++){
        for(int p = 1; p <= 11; p++){
            if(p_check[p]){
                int tmp = v[p].top();   // 맨 앞 원소 반환 
                if(tmp == 1)  break;   // 감소 시켰을 때,1보다 커야함
                
                v[p].pop();
                tmp--; 
                v[p].push(tmp); // 감소시킨 값 다시 넣기.  
            }
        }
    }
    int sum = 0; 
    for(int i=1; i<=11; i++){
        if(p_check[i])  sum += v[i].top(); 
    }
    cout << sum; 
}

