#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 


#define INF 100000000
int city[101][101];
int n, m;  

void floid(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(city[i][j] > city[i][k] + city[k][j]){
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j) city[i][j] = INF;
        }
    }
    // 중요 
    for(int i = 0; i<m; i++){
        int a,b,cost;  cin >> a >> b >> cost;
        city[a][b] = min(city[a][b], cost);
    }

    floid();

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            if(city[i][j] == INF){
                cout << 0 << " ";
                continue;
            }
            cout << city[i][j] << " ";
        }
        cout << "\n";
    }
}