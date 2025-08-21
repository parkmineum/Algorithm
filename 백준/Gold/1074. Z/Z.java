import java.io.*;
import java.util.*;

public class Main {
	static int cnt = 0;     // 현 위치 기준 앞에 몇 번의 방문을 했는지

	public static void main(String[] args) throws IOException {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int N = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken()); // 행
			int c = Integer.parseInt(st.nextToken()); // 열
			
			int size = (int) Math.pow(2, N);          // 한 변의 사이즈 2^n
			
			find(size, r, c);
			System.out.println(cnt);                  // r행 c열을 몇 번째로 방문하는지
	}
	
	private static void find(int size, int r, int c) {
		
		if(size == 1)  return;
		
		if(r < size/2 && c < size/2) {
			find(size/2, r, c);
		}
		else if(r < size/2 && c >= size/2) {
			cnt += size * size / 4;
			find(size/2, r, c - size/2);
		}
		else if(r >= size/2 && c < size/2) {
			cnt += (size * size / 4) * 2;
			find(size/2, r - size/2, c);
		}
		else {
			cnt += (size * size / 4) * 3;
			find(size/2, r - size/2, c - size/2);
		}
	}	
}