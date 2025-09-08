import java.io.*;
import java.util.*;

public class Main {

	public static int N;	 
	public static int M; 
	public static int[] arr;
	public static boolean[] visited;
 
	public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			arr = new int[M];
			visited = new boolean[N];
			
			backTraking(0,0);
	}
	

    public static void backTraking(int depth, int start) {
        if (depth == M) {
            for (int i = 0; i < M; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
            return;
        }

        for (int i = start; i < N; i++) {    // 이전 숫자보다 큰 숫자만 선택
            arr[depth] = i + 1;
            backTraking(depth + 1, i + 1);   // 다음은 i+1부터 시작 (오름차순 보장)
        }
    }
}