#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N,M,L; cin >> N >> M >> L;   // 총 개수, 지으려는 개수, 길이

    vector<int> v(N+1);
    for(int i = 0; i < N; i++) cin >> v[i];

    v.push_back(0), v.push_back(L);
    sort(v.begin(),v.end());   // 0 200 701 800 1000

    int low = 1, high = L-1, ans = 987654321;
    while(low <= high){
        int mid = (low + high)/2;
        int complete = 0; // 현재 지은 휴게소 개수

        for(int i = 1; i < v.size(); i++){
            int len = v[i] - v[i-1];

            int cnt = len / mid; // 두 휴게소 사이에 올 수 있는 휴게소 개수
            if(cnt > 0){
                // 나누어 떨어진다는 것은 마지막 휴게소와 겹쳤다는 뜻이므로 하나 빼줌
                if(len % mid == 0) complete += cnt - 1;
                else  complete += cnt;
            }
        }
        if(complete > M) low = mid + 1; // 목표 개수보다 많은 경우
        else{
            high = mid-1;
            ans = min(ans,mid);     // 최솟값 갱신
        }
    }
    cout << ans << "\n";
}