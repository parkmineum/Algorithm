#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 


#define CITY 105
#define INF 200000000

int map[CITY][CITY];
int nextNode[CITY][CITY];

int n, m;
void Floyd(){
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= n; k++){
            for(int j = 1; j <= n; j++){
                if(map[k][j] > map[k][i] + map[i][j]){
                map[k][j] = map[k][i] + map[i][j];
                nextNode[k][j] = nextNode[k][i];
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i <= n; i++){
        for(int k = 0;k <= n; k++){
           map[i][k] = INF;
           nextNode[i][k] = k; 
        }
    }
    
    for(int i = 0; i < m; i++){
        int p1, p2, w;  cin >> p1 >> p2 >> w;
        if(map[p1][p2] > w)  map[p1][p2] = w;
    }
    
    Floyd();
    
    for(int k = 1; k <= n; k++){
        for(int j = 1; j <= n; j++){
            if(k != j && map[k][j] != INF)
                cout << map[k][j] << " ";
            else{
                cout << "0 ";
            }
        }
        cout << "\n";
    }
    
    for(int p1 = 1; p1 <= n; p1++){
        for(int p2 = 1; p2 <= n; p2++){
           if(map[p1][p2] == INF || p1 == p2){
               cout << 0 << "\n";
           }
           else{
               int u = p1, v = p2;
               vector<int> path;
               while(1){
                   u = nextNode[u][v];
                   path.push_back(u);
                   if(u == v)  break;
               }
               
               cout << path.size()+1 << " " << p1 << " ";
               int Size = path.size();
               for(int i =0;i<Size;i++){
                   cout << path[i] << " ";
               }
               cout << "\n";
           }
        }
    }
}