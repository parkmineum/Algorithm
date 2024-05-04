#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001
bool visited[MAX]; 
int save_idx[MAX]; 
vector<int> path; 

int bfs(int n, int k){
    queue<pair<int,int>> q; 
    q.push({n,0}); 
    visited[n] = true; 

    while(!q.empty()){
        int subin = q.front().first; 
        int time = q.front().second; 
        q.pop(); 

        if(subin==k){      // 둘이 만났을 떄, 
            return time; 
        }

        if(subin+1<MAX && !visited[subin+1]){
            q.push({subin+1, time+1}); 
            visited[subin+1] = true;
            save_idx[subin+1] = subin; 
        }
        if(subin-1>=0 && !visited[subin-1]){
            q.push({subin-1, time+1});
            visited[subin-1] = true;
            save_idx[subin-1] = subin; 
        }
        if(subin*2<MAX && !visited[subin*2]){
            q.push({subin*2, time+1});
            visited[subin*2] = true;
            save_idx[subin*2] = subin; 
        }
    }

}

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;   cin >> n >> k;  // 수빈, 동생 
    cout << bfs(n,k) << "\n";

    while(1){
        path.push_back(k); 
        if(k==n) break; 

        k = save_idx[k];  // 역으로 거꾸로 올라가기 
    }

    for (int i = path.size()-1; i >=0 ; i--){
		cout << path[i] << " ";
	}	
}