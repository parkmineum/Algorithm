#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

#define INF 1e9+3 
vector<pair<int,int>> vec[5001]; 
vector<int> dist(5001,INF); 

int dijkstra(int s, int t){
    // 비용이 작은 거리부터 큐에서 꺼내진다.
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq; 
    pq.push({s,0});    // 노드, 해당 노드까지의 최단거리 
    dist[s] = 0; 

    while(!pq.empty()){
        int now = pq.top().first; 
        int cost = pq.top().second; 
        pq.pop(); 

        for(auto &next : vec[now]){
            // 새로운 경로가 기존 경로보다 짧다면,
            // next.second = now에서 next.first까지의 거리 
            if(dist[next.first] > next.second + cost){
                dist[next.first] = next.second + cost;
                pq.push({next.first, dist[next.first]}); 
            }
        }
    }
    return dist[t]; 
}

int main(){
    int n,m; cin >> n >> m;    // 정점 수, 간선 수 
    for(int i=0; i<m; i++){
        int a,b,cost; cin >> a >> b >> cost;
        vec[a].push_back({b,cost}); 
        vec[b].push_back({a,cost}); 
    }
    int s,t; cin >> s >> t;    // 두 정점 
    cout << dijkstra(s,t); 
}