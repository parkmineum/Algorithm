#include <iostream> 
using namespace std; 
bool button[10];   // 기본값 : false

int possible(int n){      // 원하는 채널로 이동할 때, 숫자 버튼 누를 횟수 출력
    if(n==0){        
        if(button[n]) return 0;      // 버튼 누르면, 이동 불가(발문) 
        else  return 1;
    }
    int cnt = 0;
    while(n>0){
        if(button[n%10])   return 0;  // n%10과 버튼이 일치할 경우 함수 종료
        cnt += 1;   n /= 10; 
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int trg, fail;         // 이동하고자 하는 채널 , 고장난 버튼 수
    cin >> trg >> fail;

    for(int i=0; i<fail; i++){
        int num;  cin >> num;        // 고장난 버튼
        button[num] = true;      // 고장난 버튼 = true 
    }

    int ans = abs(100-trg);   // 100번과 목표 채널(trg)의 차
    for(int i=0; i<=1000000; i++){
        int n = i;   
        int len = possible(n); 

        if(len>0){         //버튼을 눌러야 할 최소 횟수를 구하는 것 
            int press = abs(trg-n);      // 숫자 버튼으로 이동 후 +,-
            if(ans>len+press)   ans = len + press; 
        }
    }
    cout << ans; 
}