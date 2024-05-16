#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <climits>
using namespace std;

vector<vector<int>> graph;
vector<int> dist;
vector<int> res; //거리가 K인 도시
int n, m, k, x;

void dijkstra(int node) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int i = 0; i < graph[now].size(); i++) {
            int next = graph[now][i];
            if (dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

void find_k() {
    for (int i = 0; i < n; i++) {
        if (dist[i + 1] == k)
            res.push_back(i + 1);
    }
}

int main() {
    // 도시 수, 도로 개수, 거리 정보, 출발 도시
    cin >> n >> m >> k >> x;
    graph = vector<vector<int>>(n + 1);
    dist = vector<int>(n + 1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    dijkstra(x);
    find_k();
    if (res.size() == 0)
        cout << -1;
    else {
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << "\n";
    }

    return 0;
}
