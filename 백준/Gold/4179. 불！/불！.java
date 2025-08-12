import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static int m;
    static int[][] map;
    static int[] dx = {-1, 1, 0, 0};   // 상하좌우
    static int[] dy = {0, 0, -1, 1};

    static int[][] fire, person;      // 불과 지훈이의 이동 시간
    static Queue<int[]> fireQ, personQ; 
    
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());  
        map = new int[n][m];

        fire = new int[n][m];
        person = new int[n][m];

        fireQ = new LinkedList<>();
		personQ = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            String line = br.readLine();       // 한 줄씩 문자열로 읽어서 
            for (int j = 0; j < m; j++) {
                map[i][j] = line.charAt(j);    // 문자로 저장하기 
                person[i][j] = -1; 
                fire[i][j] = -1; 
                
                if(map[i][j]=='J') {
                    personQ.add(new int[] {i,j}); 
                    person[i][j] = 0;
                }
                else if(map[i][j]=='F') {
                    fireQ.add(new int[] {i,j});
                    fire[i][j] = 0;
                }
            }
        }
        while(!fireQ.isEmpty()){     // 불에 대한 BFS
            int[] now = fireQ.poll();
            int x = now[0];
            int y = now[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (fire[nx][ny] >= 0 || map[nx][ny] == '#') continue;  // 이미 불이 났거나, 벽인 경우 

                fire[nx][ny] = fire[x][y] + 1;
                fireQ.add(new int[]{nx,ny});
            }
        }
            
        while(!personQ.isEmpty()){   // 지훈이에 대한 BFS
            int[] now = personQ.poll();
            int x = now[0];
            int y = now[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || nx >= n || ny < 0 || ny >= m){   // 지훈이가 탈출에 성공한 경우
                    System.out.println(person[x][y] + 1); 
                    return; 
                }

                if (person[nx][ny] >= 0 || map[nx][ny] == '#') continue;  // 이미 지훈이가 지났거나, 벽인 경우 
                if (fire[nx][ny] != -1 && fire[nx][ny] <= person[x][y] + 1) continue;    // 불이 해당 공간에 도달한 시간 <= 지훈이가 해당 공간에 도달한 시간인 경우
                                                                                           // 즉 해당 공간은 이미 불이 번짐

                person[nx][ny] = person[x][y] + 1;
                personQ.add(new int[]{nx,ny});
            }
        }
        System.out.println("IMPOSSIBLE");
    }
}
