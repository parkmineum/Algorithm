#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std; 

// 백준 21278
// 모든 건물에서의 접근성(치킨집까지 거리)의 합을 최소화할 수 있는 건물 2개 선택
// 플로이드 와샬(값 존재하면 갱신) -> 브루트포스 
#define INF 1e9 
int dis[110][110]; 
int main(){
    for(int i=0; i<101; i++){
        for(int j=0; j<101; j++){
            if(i==j) dis[i][j] = 0;   // 자기 자신
            else dis[i][j] = INF;
        }
    }

    int n,m; cin >> n >> m;     // 건물 수, 도로 수 
    for(int i=0; i<m; i++){
        int a,b; cin >> a >> b;    // 도로 정보 // 1 <= a,b (a!=b)
        dis[a][b] = 1;     // 양방향 연결
        dis[b][a] = 1;
    }
    
    // 플로이드 - 워셜
    for(int k=1; k<=n; k++){    
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]); 
            }
        }
    }

    // 치킨집 건물 선택하기 
    int ans_a = 0, ans_b = 0, dis_hap = 1e9; 
    for(int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++){
            int temp_dis = 0;
            for(int k = 1; k<=n; k++){   // 치킨집까지의 거리 갱신
                int distanceToI = (i == k) ? 0 : dis[i][k];
                int distanceToJ = (j == k) ? 0 : dis[j][k];

                if (distanceToI < distanceToJ) {
                    temp_dis += distanceToI;
                } else {
                    temp_dis += distanceToJ;
                }   
            }
            if(temp_dis < dis_hap){
                dis_hap = temp_dis;    // 최솟값이여야 
                ans_a = i; ans_b = j;
            }
        }
    }
        
    cout << ans_a << ' ' << ans_b << ' ' << dis_hap * 2; 
}