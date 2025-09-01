import java.io.*;
import java.util.*;

public class Main {

	public static int N;	 
	public static int M; 
	public static int[] arr;
	public static boolean[] visited;
	public static StringBuilder sb = new StringBuilder();     // 출력 버퍼
 
	public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			arr = new int[M];
			visited = new boolean[N];
			
			dfs(0);
			System.out.println(sb);
	}
	
	public static void dfs(int depth) {
			if (depth == M) {          // 기저 조건이 만족할 경우(원하는 길이의 수열이 되었을 경우)
					for (int val : arr) {
							sb.append(val).append(' ');
					}
					sb.append('\n');
					return;
			}
 
			for (int i = 0; i < N; i++) {
					if (!visited[i]) {
							visited[i] = true;
							arr[depth] = i + 1;
							dfs(depth + 1);            // 다음 개수로 재귀 호출
							visited[i] = false;       // 원상 복구하여 다른 조합이 가능하도록
					}
			}
	}
}