#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,k;   cin >> n >> k;         // 시험지 수, 나눌 그룹의 수 
    vector<int> v(n+1);
    // 시험지마다 맞은 문제 개수

    int low = 0 , high = 0; 
    for(int i=1; i<=n; i++){
        cin >> v[i];
        high += v[i];     // 최대 점수 
    }    
    // 7 9 10 12 14 17 19 20 

    while(low <= high){ 
        int mid = (low + high) / 2; 

        int group = 0 , score = 0; 
        for(int i=1; i<=n; i++){ 
            score += v[i]; 
            if(score>=mid){ 
                group++;
                score = 0; 
            }
        }

        if(group>=k){
            low = mid + 1; 
        }
        else  high = mid - 1;
    }
    cout << high << "\n"; 
    
    return 0; 
}