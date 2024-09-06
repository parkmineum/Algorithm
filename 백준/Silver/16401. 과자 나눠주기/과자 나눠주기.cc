#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int child,n;  cin >> child >> n;      // 조카 수, 과자 수 
    vector<int> vec(n+1);
    for(int i=1; i<=n; i++)   cin >> vec[i]; 
    sort(vec.begin(),vec.end()); 

    int low = 1, high = vec[n], maxLen = 0; 
    while(low<=high){ 
        int mid = (low + high)/2; 

        int cnt = 0; 
        for(int i=1; i<=n; i++) cnt += vec[i]/mid;   // mid 과자 길이로 나눠줄 수 있는 양

        // m명에게 나눠줄 수 있다면 
        if(cnt >= child) {
            maxLen = mid;    // 갱신 
            low = mid + 1;   // 길이 늘리기
        }

        // m명에게 나눠줄 수 없다면
        else  high = mid - 1;   // 길이 줄이기 
    }
    cout << maxLen; 

    return 0;
}