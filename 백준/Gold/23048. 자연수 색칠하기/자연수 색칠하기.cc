#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
#include <cmath> 
using namespace std; 


// 자연수 색칠하기(1~n, 서로소는 서로 다른 색깔)    // 사용한 색의 최소 개수 출력 

// 서로소인 자연수는 다른 색으로 칠해야 한다" == "새로운 소수가 등장하면,
// 그 소수의 배수는 모두 같은 색으로 칠하면 된다" == "소수의 개수를 찾으면 된다!
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int color[500010] = {0,}; int n; cin >> n; 
    int color_cnt = 1;  color[1] = 1;     
    for(int i=2; i<=sqrt(n); i++){
        if(color[i]==0){    // 아직 색칠되지 x
            color_cnt++; 
            for(int j=i; j<=n; j+=i){
                color[j] = color_cnt;    
                // 전부 같은 색으로 칠해주기 
                // i 간격 = 배수를 뜻함
            }
        } 
    } 
    for(int i=2; i<=n; i++){
        if(color[i]==0){   // 소수의 배수로 색칠된 숫자가 아닌 나머지 숫자  
            color_cnt += 1; 
            color[i] = color_cnt; 
        }
    } 

    cout << color_cnt << "\n"; 
    for(int i=1; i<=n; i++){ 
        cout << color[i] << ' ';
    }
}