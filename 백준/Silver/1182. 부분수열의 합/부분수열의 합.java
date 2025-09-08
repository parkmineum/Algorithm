import java.io.*;
import java.util.*;

public class Main {

	public static int N, S, arr[];
	public static int cnt = 0;    
 
	public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      StringTokenizer st = new StringTokenizer(br.readLine());
      
      N = Integer.parseInt(st.nextToken());
      S = Integer.parseInt(st.nextToken());
      arr = new int[N];
      
      st = new StringTokenizer(br.readLine());
      for(int i = 0; i < N; i++){
          arr[i] = Integer.parseInt(st.nextToken());
      }
      
      backtraking(0,0);
      
      if(S==0) System.out.println(cnt-1);   // 합이 0인 경우 공집합 제외 
      else System.out.println(cnt);   
	}
	
	public static void backtraking(int start, int result){ 
      if(start == N){     // 원소 개수 충족(종료 조건)
          if(result == S) cnt++;    // 합이 S가 되는 순간
          return;
      }
      
      backtraking(start + 1, result + arr[start]);    
      backtraking(start + 1, result);
	}
}