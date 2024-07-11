#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int arr[110][110]; 
int  n,m,trash = 0; 

void cleaning(int x, int y){
    for(int i=x; i<n; i++){
        for(int j=y; j<m; j++){  // 열 단위로 검사 
            if(arr[i][j]==1){
                arr[i][j]=0;   
                trash--;

                if(!trash)  return;   // 더 이상 쓰레기가 없다면
                else cleaning(i,j);   // 쓰레기가 남아있다면
                return; 
            }
        }
    }
    return; 
}

int main(){
    cin >> n >> m; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j]; 
            if(arr[i][j]==1)  trash++; 
        }
    }

    int robot = 0; 
    while(trash){ 
        robot++; 
        cleaning(0,0); 
    }
    cout << robot; 
}