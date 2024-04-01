#include <iostream>
using namespace std;


#define MAX 51 
int n, maxCandy = 0; 
char candy [MAX][MAX];

void check(){
    for(int i=0; i<n; i++){         // 행 
        int cnt = 1; 
        for(int j=0; j<n; j++){
            if(candy[i][j]==candy[i][j+1])  cnt++; 
            else{
                if(maxCandy<cnt) maxCandy = cnt; 
                cnt = 1; 
            }
        }
    }
    for(int j = 0; j < n; j++) {
        int count = 1;
        for(int i = 0; i < n; i++) {
            if(candy[i][j] == candy[i + 1][j]) {
                count++;
            }
            else {
                if(maxCandy < count) maxCandy = count;
                count = 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> candy[i][j];
        }
    }
        for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            swap(candy[i][j], candy[i][j + 1]);
            check();
            swap(candy[i][j], candy[i][j + 1]);
        }
    }

    for(int j = 0; j < n; j++) {
        for(int i = 0; i < n - 1; i++) {
            swap(candy[i][j], candy[i + 1][j]);
            check();
            swap(candy[i][j], candy[i + 1][j]);
        }
    }

    cout << maxCandy << '\n';


}