import java.io.*;
import java.util.*;

public class Main {

    static int[][] map;
    static int n;
    static int m;
    static boolean[][] visited;
    static int[] dx = {-1, 1, 0, 0}; // 상하좌우
    static int[] dy = {0, 0, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tk = new StringTokenizer(br.readLine());
        n = Integer.parseInt(tk.nextToken());
        m = Integer.parseInt(tk.nextToken());

        map = new int[n][m];
        visited = new boolean[n][m];

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < m; j++) {
                map[i][j] = s.charAt(j) - '0';
            }
        }

        visited[0][0] = true; // 시작점 방문처리
        bfs(0, 0);
        System.out.println(map[n - 1][m - 1]);
    }

    public static void bfs(int a, int b) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{a, b});

        while (!q.isEmpty()) {
            int[] now = q.poll();
            int x = now[0];
            int y = now[1];

            for (int i = 0; i < 4; i++) {
                int nX = x + dx[i];
                int nY = y + dy[i];

                if (nX < 0 || nY < 0 || nX >= n || nY >= m) continue;
                if (visited[nX][nY] || map[nX][nY] == 0) continue;

                q.add(new int[]{nX, nY});
                map[nX][nY] = map[x][y] + 1;
                visited[nX][nY] = true;
            }
        }
    }
}