# include <queue> 
#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
struct moves{
    int x; 
    int y; 
};

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; 

    while(t--){
        int n; // 편의점 수 
        pair<int,int> home, festival;  
        
        cin >> n; 
        cin >> home.first >> home.second;  // 집 좌표 
        
        vector<pair<int,int>> store(n); 
        vector<bool>visitStore(n,false); 
        for(int i=0; i<n; i++){
            cin >> store[i].first >> store[i].second; // 편의점 좌표
        }
        cin >> festival.first >> festival.second;   // 축제 좌표 

        bool isFin = false;
        queue<moves> q; 
        q.push({home.first, home.second});  // 집 좌표 대입 
        while(!q.empty()){
            int x = q.front().x;   // 집 주소 
            int y = q.front().y; 
            q.pop(); 

            // 편의점 1000m 내에 있는지 
            for(int i=0; i<store.size(); i++){
                // 두 좌표 사이의 거리 = x 좌표 차이 + y 좌표 차이 
                if((abs(store[i].first - x) + abs(store[i].second - y)) <= 1000){
                    if(!visitStore[i]){
                        visitStore[i] = true;  // 방문처리 
                        q.push({store[i].first,store[i].second}); 
                    }
                }
            }
            if((abs(festival.first - x) + abs(festival.second - y))<=1000){
                isFin = true;    // 페스티벌 갈 수 있음 
                break; 
            }
        }
        if(isFin)  cout << "happy" << "\n";
        else cout << "sad" << "\n";  
    }
}