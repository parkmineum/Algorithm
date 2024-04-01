#include <string>
#include <vector>

using namespace std;

string solution(int age) {   // age <= 1000 
    string answer =  to_string(age); 
 
    for(int i=0; i<answer.size(); i++){
        answer[i] += char(49);
    }

    return answer;
}