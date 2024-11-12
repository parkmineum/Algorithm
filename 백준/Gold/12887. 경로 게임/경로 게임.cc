#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char board[2][51];
int dist[2][51];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(queue<pair<int, int>>& Q, int m) {
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= 2 || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != 0 || board[nx][ny] == '#') continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int m;
    cin >> m;

    int white = 0;
    for (int cnt_i = 0; cnt_i < 2; cnt_i++){
        for (int cnt_j = 0; cnt_j < m; cnt_j++){
            cin >> board[cnt_i][cnt_j];
            if (board[cnt_i][cnt_j] == '.') white++;
            if (board[cnt_i][cnt_j] == '#') dist[cnt_i][cnt_j] = -1;
        }
    }
    
    queue<pair<int,int>> Q;
    if (board[0][0] == '.') {
        Q.push({0,0});
        dist[0][0] = 1;
    }
    if (board[1][0] == '.') {
        Q.push({1,0});
        dist[1][0] = 1;
    }

    // BFS 호출
    bfs(Q, m);

    int mn;
    if (board[0][m-1] == '#') mn = dist[1][m-1];
    else if (board[1][m-1] == '#') mn = dist[0][m-1];
    else {
        mn = min(dist[0][m-1], dist[1][m-1]);
    }

    cout << white - mn;
    return 0;
}