import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int m;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0};   // 상하좌우
    static int[] dy = {0, 0, -1, 1};
    static int cnt = 0;  // 최소 익은 날짜 
    static Queue<int[]> q = new LinkedList<>(); 
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());  
        n = Integer.parseInt(st.nextToken());
        map = new int[n][m];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if (map[i][j] == 1) {     // 1일 경우(익은 경우) 삽입 => 시작점
                    q.add(new int[]{i, j});
                } 
            }
        }
        System.out.println(bfs());
    }

    private static int bfs(){
        while(!q.isEmpty()){
            int[] now = q.poll();
            int x = now[0];
            int y = now[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                
                if(map[nx][ny] == 0){     // 아직 익지 않은 토마토인 경우
                    map[nx][ny] = map[x][y] + 1; 
                    q.add(new int[]{nx, ny});
                }
            }
        } 

        int min = Integer.MIN_VALUE;
        if(checkIsZero())  return -1;   // 토마토가 모두 익지 못하는 상황
        else{
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(min < map[i][j]){
                        min = map[i][j];
                    }
                }
            }
            return min - 1; 
        }
    }

    private static boolean checkIsZero(){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 0)
                    return true;
            }
        }
        return false;
    }
}