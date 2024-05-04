#include <iostream>
#include <algorithm> 
#include <vector> 
#include <stack> 
#include <queue> 
using namespace std; 


int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    priority_queue<int, vector<int>, greater<int>> pq;  //  최소힙
    vector<pair<int,int>> study; 
    int n; cin>>n; 
    int start, finish; 

    for(int i=0; i<n; i++){
        cin >> start >> finish; 
        study.push_back({start,finish}); 
        // {1,3}, {2,4}, {3,5}
    }
    sort(study.begin(),study.end()); 

    for(int i=0; i<study.size(); i++){
        pq.push(study[i].second);  // 3, 4, 5 (끝나는 시간)
        
        // top의 종료 시간보다 i번째 수업이 늦게 시작한다면, 
        // 연달아 같은 강의실에서 진행 가능 
        if(study[i].first >= pq.top()){
            pq.pop(); 
        }   
    }

    cout << pq.size(); 
}