import java.util.*;

class Solution {
    public int[] solution(int[][] edges) {
        int[] answer = new int[4];
        int edge = edges.length; 
        int graph = 0;  // 생성 정점으로부터 뻗어나가는 그래프 수
        
        HashMap<Integer, Integer> fromNode = new HashMap<>();  // <Key, Value>        
        HashMap<Integer, Integer> toNode = new HashMap<>();   
        HashSet<Integer> nodes = new HashSet<>();   // 정점 집합(단일값)
        
        for (int i = 0; i < edge; i++) {
            int a = edges[i][0]; 
            int b = edges[i][1];
            
            nodes.add(a);
            nodes.add(b);
            
            // 출발점 degree 증가
            if (fromNode.containsKey(a)) {
                fromNode.put(a, fromNode.get(a) + 1);
            } else {
                fromNode.put(a, 1);
            }
            
            // 도착점 degree 증가
            if (toNode.containsKey(b)) {
                toNode.put(b, toNode.get(b) + 1);
            } else {
                toNode.put(b, 1);
            }
        }
        
        for (int node : nodes) {
            // 생성 정점 찾기
            if (!toNode.containsKey(node) && fromNode.containsKey(node) && fromNode.get(node) >= 2) {
                answer[0] = node;
            }
            // 막대 그래프
            if (!fromNode.containsKey(node) && toNode.containsKey(node)) {
                answer[2]++;
            }
            // 8자 그래프
            if (fromNode.containsKey(node) && fromNode.get(node) >= 2 &&
                toNode.containsKey(node) && toNode.get(node) >= 2) {
                answer[3]++;
            }
        }
        
        int num = answer[0];
        for (int i = 0; i < edge; i++) { // 생성 정점에서 나가는 간선 수
            if (num == edges[i][0]) graph++;
        }
        
        // 도넛 그래프 개수 계산
        answer[1] = graph - answer[2] - answer[3];
        
        return answer;
    }
}
