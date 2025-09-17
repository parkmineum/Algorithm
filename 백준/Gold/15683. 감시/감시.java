import java.io.*;
import java.util.*;

public class Main {

    static class Point {
        int x, y, cctvNum;
        Point(int x, int y, int cctvNum) {
            this.x = x;
            this.y = y;
            this.cctvNum = cctvNum;
        }
    }

    static int N, M;
    static int min = Integer.MAX_VALUE;

    // 상, 하, 좌, 우
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};

    // CCTV 별 방향 경우의 수 정의 (상=0, 하=1, 좌=2, 우=3)
    static int[][][] dir = {
        {},                                         // 0번 없음
        {{0}, {1}, {2}, {3}},                       // 1번 CCTV
        {{0, 1}, {2, 3}},                           // 2번 CCTV (상+하, 좌+우)
        {{0, 3}, {3, 1}, {1, 2}, {2, 0}},           // 3번 CCTV (상+우, 우+하, 하+좌, 좌+상)
        {{0, 2, 3}, {0, 1, 3}, {1, 2, 3}, {0, 1, 2}}, // 4번 CCTV (세 방향)
        {{0, 1, 2, 3}}                              // 5번 CCTV (네 방향)
    };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        int[][] map = new int[N][M];
        ArrayList<Point> cctv = new ArrayList<>();

        for(int i=0; i<N; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0 && map[i][j] != 6) {
                    cctv.add(new Point(i, j, map[i][j]));
                }
            }
        }

        dfs(0, map, cctv);
        System.out.println(min);
    }

    // DFS로 CCTV 배치 경우의 수 탐색
    public static void dfs(int cnt, int[][] map, ArrayList<Point> cctv) {
        if(cnt == cctv.size()) {
            min = Math.min(min, getZeroCnt(map));
            return;
        }

        Point p = cctv.get(cnt);
        for(int[] dirs : dir[p.cctvNum]) {
            int[][] tmp = copyMap(map);
            for(int d : dirs) {
                watch(tmp, p.x, p.y, d);
            }
            dfs(cnt+1, tmp, cctv);
        }
    }

    // 감시 영역 표시
    public static void watch(int[][] map, int x, int y, int d) {
        int nx = x, ny = y;
        while(true) {
            nx += dx[d];
            ny += dy[d];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) break;
            if(map[nx][ny] == 6) break; // 벽
            if(map[nx][ny] == 0) map[nx][ny] = -1; // 감시 가능
        }
    }

    // 사각지대 개수 계산
    public static int getZeroCnt(int[][] map) {
        int zeroCnt = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(map[i][j] == 0) zeroCnt++;
            }
        }
        return zeroCnt;
    }

    // 맵 복사
    public static int[][] copyMap(int[][] map) {
        int[][] tmp = new int[N][M];
        for(int i=0; i<N; i++) {
            System.arraycopy(map[i], 0, tmp[i], 0, M);
        }
        return tmp;
    }
}