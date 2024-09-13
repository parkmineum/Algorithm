#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
using namespace std; 


// 생태학 (4358)

#include <map> 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<string, int> Map;
    string tree;  int n = 0; 

    while(getline(cin, tree)){    
        Map[tree]++;  n++;    
    }  

    cout << fixed; cout.precision(4);   // 소수점 이하 4자리 출력으로 고정 
    
    for(auto iter = Map.begin(); iter != Map.end(); iter++){
        // 인자 각 각 꺼내기
        cout << iter -> first << " " << (double)iter -> second/n*100 << "\n"; 
    }
}