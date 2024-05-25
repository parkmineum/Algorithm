#include <iostream>
#include <algorithm> 
#include <vector> 
#include <string> 
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

#define INF 987654321
int v,e,a,b,cost; 
int arr[401][401]; 

void floyd() {
	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
                // 최단 경로 업데이트 
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
}
int main(){
    cin >> v >> e;       // 마을, 도로 
    // 플로이드 - 와샬 초기 설정 
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i!=j) arr[i][j] = INF;   // INF는 경로가 없음을 의미
        }
    }

    for(int i=0; i<e; i++){
        cin >> a >> b >> cost; 
        arr[a][b] = cost; 
    }
    floyd(); 

    int res = INF; 
    for(int i=1; i<=v; i++){
        for(int j=1; j<=v; j++){
            if(i==j) continue;
            res = min(res, arr[i][j]+arr[j][i]); 
        }
    }
    if(res==INF) cout << -1; 
    else  cout << res; 
}