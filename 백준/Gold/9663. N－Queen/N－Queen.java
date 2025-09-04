import java.io.*;
import java.util.*;

public class Main {

	public static int N;	 
	public static int[] arr;
	public static int cnt = 0;   // 경우의수
 
	public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			N = Integer.parseInt(br.readLine());
			arr = new int[N]; 
			
			backTracking(0);
			System.out.println(cnt);
	}
	
	private static void backTracking(int depth){
			if(depth==N){
					cnt++;
					return;
			}
			
			for(int i=0; i<N; i++){
					arr[depth] = i;
					if(isQueenOk(depth)){
							backTracking(depth+1); 
					}
			}
	}
	
	private static boolean isQueenOk(int col) {     // 행 단위로 읽어 내려감
			
			for(int i=0; i<col; i++){
					// 같은 행에 존재하는 경우 
					if(arr[col] == arr[i]){
							return false;
					}
					
					// 대각선상에 놓여 있는 경우(열의 차와 행의 차가 같을 때)
					else if(Math.abs(col - i) == Math.abs(arr[col] - arr[i])){
							return false; 
					}
			}
			return true;
	}
}