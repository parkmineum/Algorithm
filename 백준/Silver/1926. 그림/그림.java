import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    static int[] dx = {-1, 1, 0, 0};  
    static int[] dy = { 0, 0,-1, 1};
    
    static int[][] pic;
    static boolean[][] visited;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(tk.nextToken());
        int m = Integer.parseInt(tk.nextToken());

        Queue<int[]> q = new LinkedList<>();

        pic = new int [n][m];
        visited = new boolean[n][m];

        for(int i=0;i<n;i++){
            tk = new StringTokenizer(br.readLine());
            for(int j=0;j<m;j++){
                pic[i][j] = Integer.parseInt(tk.nextToken());   
            }
        }

        int num = 0;  // 그림 수
        int max_width = 0; // 가장 넓은 그림 크기

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pic[i][j] == 0 || visited[i][j]) continue;
                
                num++;
                visited[i][j] = true;
                q.offer(new int[] {i,j});
                int area = 0 ;
                
                while(!q.isEmpty()){
                    area++;
                    int[] temp = q.poll();
                    int x = temp[0];
                    int y = temp[1];

                    for(int dir = 0;dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(visited[nx][ny] || pic[nx][ny] !=1) continue;
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx,ny});
                    }
                }
                max_width = Math.max(max_width,area);
            }
        }


        System.out.println(num);
        System.out.println(max_width);
    }
}