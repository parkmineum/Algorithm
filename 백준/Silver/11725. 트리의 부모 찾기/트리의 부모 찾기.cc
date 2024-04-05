#include <iostream>
#include <vector>

using namespace std;
 
int arr[100001];
bool visited[100001];
vector<int> v[100001];

void dfs(int k) {
    visited[k]=true;
    for(int i=0;i<v[k].size();i++) {
        if(!visited[v[k][i]]) {
            arr[v[k][i]]=k;
            dfs(v[k][i]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;

    for(int i=0;i<N;i++) {
        int x,y;   cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(1);

    for(int i=2;i<=N;i++) cout << arr[i] << "\n";
}
 