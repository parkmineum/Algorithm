#include <string>
#include <vector>

using namespace std;

// 비밀번호는 같을 수 있지만, 아이디는 같을 수 없다. 
string solution(vector<string> id_pw, vector<vector<string>> db) {
    string answer = "";
    bool id, pw;
    for(const auto& data : db) {
        id = id_pw[0] == data[0];
        pw = id_pw[1] == data[1];
        
        if(id)  break;     // id 매칭되었을 경우
        if (id && !pw)  pw = false;    // id 일치하지만, pw 불일치 
        else  pw = true;       
    }
    
    if(id && pw)  answer = "login";
    else if(id && !pw)  answer = "wrong pw";
    else if(!id)   answer = "fail";
    
    return answer;
}