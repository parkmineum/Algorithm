import java.util.*;

class Solution {
    public int[] solution(String today, String[] terms, String[] privacies) {
        List<Integer> result = new ArrayList<>();
        Map<String, Integer> termMap = new HashMap<>();
        
        for (String term : terms) {
            String[] split = term.split(" ");
            termMap.put(split[0], Integer.parseInt(split[1]));    // "A 6" => <"A", 6>
        }
        int todayTotalDays = convertToDays(today);
        
        for(int i=0; i<privacies.length; i++){
		        String[] split = privacies[i].split(" ");
            String date = split[0];
            String type = split[1];
            
            int period = termMap.get(type);   // type
            
            int dateTotal = convertToDays(date) + (period * 28) - 1;   // 해당 날짜에 유효기간 더하기
            
            
            // 오늘보다 과거에 만료라면 파기 대상
            if (todayTotalDays > dateTotal) {
                result.add(i + 1);
            }
        }
        int[] arr = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            arr[i] = result.get(i);
        }
        return arr;
    }
    
    
    // 날짜 => 일 수 
    private int convertToDays(String date) { 
        String[] split = date.split("\\.");
        int year = Integer.parseInt(split[0]);
        int month = Integer.parseInt(split[1]);
        int day = Integer.parseInt(split[2]);
        
        return (year * 12 * 28) + (month * 28) + day;
    }
}