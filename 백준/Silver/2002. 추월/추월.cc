#include <iostream>
#include <algorithm> 
#include <vector> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
using namespace std; 
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    map<string,int> Map; 
    int car[1001]; 
    int n; cin >> n; 

    for(int i=0; i<n; i++){
        string s; cin >> s;
        Map[s] = i;     // a, b, c, d 
    }
    for(int i=0; i<n; i++){
        string s; cin >> s;   // d, a, b, c 

        int idx = Map[s];    // car :  4 , 1 , 2, 3 
        car[i] = idx;   
        // 인덱스만 저장하는게 포인트!
        // 두번쨰 입력 받는 차량 순서에 맞는 idx를 car에 저장
    }

    int cnt = 0; 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){    
            if(car[i]>car[j]){
                cnt++;
                break; 
            }  
        }
    }
    cout << cnt; 
}