class Solution {
    public int[] solution(int n) {
        int[][] arr = new int[n][n]; 
        int[] ans = new int[n*(n+1)/2];    // 1~n 까지 합 = 삼각형의 크기
        
        int x = -1; int y = 0; 
        int tmp = 1;   // 달팽이 채우기 값 
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i%3==0)  x++;   // 아래 
                else if(i%3==1)  y++;   // 위 
                else if(i%3==2){ 
                    x--; y--;      // 대각선
                }
                arr[x][y] = tmp++; 
            }
        }
        
        int idx = 0; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(arr[i][j]==0) break; 
                ans[idx++] = arr[i][j];
            }
        }
        return ans; 
    }
}