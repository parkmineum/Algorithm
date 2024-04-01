class Solution {
    public String solution(int age) {
        String answer = "";  
        String s = String.valueOf(age); //숫자->문자열
        String[] arr = s.split("");  
        
        for(int i=0 ; i<arr.length; i++){
            answer += ( (char)(Integer.parseInt(arr[i])+97));   // 97 == 'a'
        }
        
        return answer;
    }
}