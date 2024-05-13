#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int one[5] = {1,2,3,4,5}; 
    int two[8] = {2,1,2,3,2,4,2,5}; 
    int three[10] = {3,3,1,1,2,2,4,4,5,5}; 
    int cnt[3] = {0,0,0}; 
    
    // answers = {1,3,2,4,2}
    for(int i = 0; i < answers.size(); i++){
        // 각 배열의 크기만큼 반복
        if(answers[i] == one[i%5])
            cnt[0]++;
        if(answers[i] == two[i%8])
            cnt[1]++;
        if(answers[i] == three[i%10])
            cnt[2]++;
    }  
    int max_score = 0; 
    max_score = max(max(cnt[0],cnt[1]),cnt[2]);  
    // 3개 인자의 값을 비교하기 위해서이다. 
    // 3개의 값이 모두 같다면, 무작위로 하나의 값이 반환된다. 
    
    for(int i=0;i<3;i++){
        if(max_score == cnt[i])   
            answer.push_back(i+1); 
        // 값이 모두 같을 경우 answer에 전부 저장됨
    }
    return answer;
}