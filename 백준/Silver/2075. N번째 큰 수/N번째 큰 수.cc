#include <iostream>
#include <algorithm> 
#include <vector> 
#include <stack> 
#include <queue> 
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙
    for(int i=0; i<n*n; i++){
        int num; cin >> num; 
        pq.push(num);  
        // 12 7 9 15 5 -> 5 9 7 12 15 
        
        if(pq.size()>n)  pq.pop();  // 가장 작은 값 pop 
    }
    cout << pq.top() << "\n";
}