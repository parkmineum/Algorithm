#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int dx[8]={1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8]={1, 0, -1, 1, -1, 1, 0, -1};
    // 상하좌우 + 대각선 이동

    int n = board.size(); 
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==1){
                for(int k=0; k<8; k++){
                    if(i+dx[k]>=0&&i+dx[k]<n &&
                      j+dy[k]>=0&&j+dy[k]<n){
                        if(board[i+dx[k]][j+dy[k]]!=1)
                            board[i+dx[k]][j+dy[k]]=2;
                    }
                }
            }
        }
    }
    
    int ans = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j]==0)  ans++; 
        }
    }
    return ans; 
}