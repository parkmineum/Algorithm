#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 
typedef long long ll; 
#define MAX 10000001     // 10^14 절반인 10^7 
bool isPrime[MAX]; 
int cnt_Prime = 0; 

// 에라토스테네스의 체
void solution(){ 
    for(int i=2; i<MAX; i++)  isPrime[i] = true; 
    for(int i=2; i*i<=MAX; i++){
        if(isPrime[i]){
            for(int j=i*i; j<MAX; j+=i){ 
                isPrime[j] = false;    
            }
        }
    }
}
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll A,B;   cin >> A >> B;       // 배열 생성 불가 
    solution(); 
    
    for(int i=2; i<=MAX; i++){
        // A<=key<=B   
        if(isPrime[i]){    // 소수라면
            ll key = i;
            while(key<=B/i){   // 본래 key * i <= B지만 시간 초과 때문에 나눈꼴로 진행 
                if(A <= key*i)   cnt_Prime++; 
                key *= i; 
            }
        }
    }

    cout << cnt_Prime; 
}