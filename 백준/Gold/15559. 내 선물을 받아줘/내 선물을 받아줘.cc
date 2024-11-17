#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> visited;
int result = 0;
int depth = 0;

void dfs(int y, int x, int n, int m) {
    visited[y][x] = depth;
    
    char c = map[y][x];
    int nextY = 0, nextX = 0;
    
    if (c == 'N')
        nextY = -1;
    else if (c == 'E')
        nextX = 1;
    else if (c == 'S')
        nextY = 1;
    else
        nextX = -1;

    int moveY = y + nextY;
    int moveX = x + nextX;

    if (moveY >= 0 && moveY < n && moveX >= 0 && moveX < m) {
        if (visited[moveY][moveX] == 0) {
            dfs(moveY, moveX, n, m);
        } else if (visited[moveY][moveX] == depth) {
            result++;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Allocate the map and visited arrays
    map.resize(n, vector<char>(m));
    visited.resize(n, vector<int>(m, 0));

    // Read the map input
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] == 0) {
                depth++;
                dfs(i, j, n, m);
            }
        }
    }

    cout << result << "\n";
}