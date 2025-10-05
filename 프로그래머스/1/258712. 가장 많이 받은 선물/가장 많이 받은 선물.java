import java.util.*;

class Solution {
    public int solution(String[] friends, String[] gifts) {
        int n = friends.length; 
        
        HashMap<String, Integer> friendsIdx = new HashMap<>();
        for(int i=0; i<n; i++){
		        friendsIdx.put(friends[i], i);      // 이름을 인덱스로 매핑 
        }
        
        int[][] giftHistory = new int[n][n];   // 선물 주고받은 횟수 기록 [준 사람][받은 사람]
        int[] giftScore = new int[n];          // 선물 지수(준 개수 - 받은 개수)
        int[] nextMonthGifts = new int[n];     // 다음 달 받을 선물 개수 
        
        // 선물 기록 처리
        for(String record : gifts){
		        String[] names = record.split(" "); 
		        int giver = friendsIdx.get(names[0]);
            int receiver = friendsIdx.get(names[1]);
		        
		        giftHistory[giver][receiver]++;    // 선물 주기 기록
		        
		        giftScore[giver]++;    // 선물 지수(준 사람 +1, 받은 사람 -1)
		        giftScore[receiver]--; 
        }
        
        // 모든 친구 쌍 비교 
        // 선물 기록 있다면 : 둘 사이에 더 많은 선물을 준 사람이 다음 달에 선물 하나를 받는다.
        // 선물 기록 없음 or 수가 같다면 : 이번 달 선물 지수가 더 큰 사람이 선물 하나를 받는다. * 선물 지수도 같다면, 선물 주고 받지 않음
        for(int i=0; i<n; i++){
	        for (int j = i + 1; j < n; j++) {
			        // 선물 기록이 있는 경우
			        if(giftHistory[i][j] > giftHistory[j][i]){   // A의 선물 주고받은 기록 vs B의 선물 주고받은 기록 
					        nextMonthGifts[i]++;
			        }
			        else if(giftHistory[i][j] < giftHistory[j][i]){
					        nextMonthGifts[j]++;
			        }
			        
			        // 선물 기록이 없는 경우
			        else{
					        if (giftScore[i] > giftScore[j]) nextMonthGifts[i]++;
                  else if (giftScore[i] < giftScore[j]) nextMonthGifts[j]++;
			        }   
	        }
        }
        
        int answer = 0;
        for(int giftsReceived : nextMonthGifts){
		        answer = Math.max(answer, giftsReceived); 
        }
        
        return answer;
    }
}