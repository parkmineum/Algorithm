import java.io.*;
import java.util.*;

public class Main {

	public static int k, arr[], result[]; 
	public static boolean visited[]; 
	public static StringBuilder sb = new StringBuilder();
 
	public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			
			while(true){
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				k = Integer.parseInt(st.nextToken());  
				if(k==0) break; 
				
				arr = new int[k];
				visited = new boolean[k]; 
				result = new int[6];
				
				for(int i=0; i<k; i++){
					arr[i] = Integer.parseInt(st.nextToken());
				}
				
				backTraking(0,0);
				sb.append('\n');
			}
			System.out.print(sb.toString());
	}
	
	public static void backTraking(int depth, int start) {
			if (depth == 6) {   
					for(int ans : result){ 
						sb.append(ans).append(" "); 
					}
					sb.append("\n"); 
					return; 
			}
 
			for (int i = start; i < k; i++) {
					if (!visited[i]) {
							visited[i] = true;
							result[depth] = arr[i];       
							backTraking(depth + 1, i+1);          
							visited[i] = false;        
					}
			}
	}
}