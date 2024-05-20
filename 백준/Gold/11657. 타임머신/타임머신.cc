#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack>
#include <queue>
#include <deque> 
using namespace std;


// 타임머신
// 1번 도시에서 출발해 각 도시로 가는 가장 빠른 시간 순서대로 출력
// cnt = 0 인 경우 순간 이동. cnt < 0인 경우 시간 되돌리기 가능 
// "시간을 무한히 오래전으로 되돌릴 수 있다면" == "음의 사이클 존재"
#define INF 987654321 
int n, m, a, b, cnt;
vector<pair<pair<int, int>,int>> graph;
long long dist[501]; 

void solution() {
    dist[1] = 0;

    // n-1 번 반복 -> 모든 노드 탐색 
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < graph.size(); j++) {
            int start = graph[j].first.first; 
            int end = graph[j].first.second; 
            int cost = graph[j].second; 

            if (dist[start] == INF) continue;  // 1을 자동으로 찾아가게 됨
            if (dist[end] > dist[start] + cost) dist[end] = dist[start] + cost;
        }
    }

    // 여기서 핵심은, 같은 과정을 한 번 더 해준다. 
    // 한 번 더 했을 때, 가중치가 작아지는 노드가 있다면 음의 사이클 존재
    for (int j = 0; j < graph.size(); j++) {
        int start = graph[j].first.first;
        int end = graph[j].first.second;
        int cost = graph[j].second;

        if (dist[start] == INF) continue; 
        if (dist[end] > dist[start] + cost) {
            cout << -1; 
            return;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF)  cout << -1 << "\n";
        else   cout << dist[i] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;     // 도시 개수, 버스 개수 
    for (int i = 1; i <= n; i++)  dist[i] = INF;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> cnt;
        graph.push_back({{ a, b }, cnt});    // 방향 그래프 
    }
    solution();

}