#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, key;  cin >> n >> key;    // k : 올릴 수 있는 레벨 총합 // 10 
    vector<int> T(n+1); 
    for(int i=1; i<=n; i++) cin >> T[i];   
    sort(T.begin(), T.end());    // 10 15 20


    // right가 나올 수 있는 최댓값(최대 20억이기에 int)
    int left = T[1], right = T[1] + key , minLevel = 1; 
    while(left<=right){
        int mid = (left+right)/2; 

        long long sum = 0; 
        for(int i=1; i<=n; i++){
            if(T[i] < mid) sum += mid - T[i];   // 5 
            else break; 
        }

        if(sum <= key) {
            minLevel = max(minLevel, mid); 
            left = mid + 1;   
        }      
        else {
            right = mid - 1;
        } 
    } 
    cout << minLevel; 
} 