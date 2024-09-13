#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
#include <map> 
#include <unordered_map>
using namespace std; 

// 수강신청(13414)   // 입력 50만, 1초

// 대기 순 정렬 
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.second < b.second;
}
int main(){ 
    int n, l;   cin >> n >> l;   // 수강 가능 인원, 대기목록 길이
    unordered_map<string, int> Map;     // 해시 테이블. O(1)  <-> map (Ologn)   // 중복 데이터 허용 x
    for(int i=0; i<l; i++){ 
        string student_num;  cin >> student_num; 
        Map[student_num] = i;  
    }

    vector<pair<string,int>> vec;
    for(auto& i : Map)  vec.push_back(i); 
    sort(vec.begin(), vec.end(), compare); 
    
    for(int i=0; i < min(n, (int)vec.size()); i++) cout << vec[i].first << "\n" ;

    return 0; 
}
