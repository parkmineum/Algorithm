#include <iostream>
#include <cmath>
using namespace std;

int N;
int ans = 0;
int col[15] = {0,};

// 해당 위치에 퀸을 놓을수 있는지 없는지 확인하는 함수
bool isPossible(int num){
    for(int i = 0; i < num; i++){
   		// 같은 열, 대각선에 있으면 안됨
        if(col[num] == col[i] || 
        abs(num-i) == abs(col[num]-col[i])) return false;
    }
    return true;
}

void backTracking(int cIdx){
    // 마지막행까지 도달했다면 N개의 퀸을 모두 놓은 것이므로 성공
    if(cIdx == N){
        ans++;
        return;
    }
    for(int i = 0; i < N; i++){
        col[cIdx] = i; // cIdx 행 i열에 퀸을 둠(cIdx,i)
        if(isPossible(cIdx)){
            // 해당 위치에 놓을 수 있으면 다음 행으로 넘어감
            backTracking(cIdx+1);
        }
        // 그렇지 않으면 다음 열에 놓는 것으로 다시 판단
    }
}
int main(){
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    cin >> N;
    backTracking(0);
    cout << ans;
}