import java.io.*;
import java.util.*;


class Main {

    static int N, K; 

    // - 0 초 : 수빈이 위치
    // - 1초 : x-1, x+1, x*2 의 위치로 이동 가능
    public static void main(String[] args) throws Exception{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        String [] inputs = input.split(" "); 

        N = Integer.valueOf(inputs[0]);     // 수빈 위치 
        K = Integer.valueOf(inputs[1]);     // 동생 위치 

        if(N>=K) System.out.println(N-K);
        else System.out.println(bfs(N));
    }

    static int bfs(int start){
        Queue<Integer> q = new LinkedList<Integer>();
        int[] dist = new int[100001]; 
        
        q.add(start);
        dist[start] = 1;

        while(!q.isEmpty()){
            int now = q.poll();

            for(int i=0; i<3; i++){
                int next = 0; 
                if(i==0) next = now - 1;
                else if(i==1) next = now + 1; 
                else next = now * 2; 
                if(next == K) return dist[now];

                if(0<=next && next<=100000 && dist[next]==0){
                    q.add(next);
                    dist[next] = dist[now] + 1;
                }
            }
        }
        return 0; 
    }
}