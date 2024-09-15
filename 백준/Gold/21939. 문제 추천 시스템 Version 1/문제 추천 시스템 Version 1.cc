#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
#include <map>  
#include <set>  //  중복 x, 자동 정렬    <->    우선순위 큐 : 중복 허용
using namespace std;
int main(){ 
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, p, l; cin >> n;    
    set<pair<int, int>> prob;
    map<int,int> mp;
    for(int i=0; i<n; i++){ 
        cin >> p >> l;     // 문제 번호, 난이도
        prob.insert({l,p}); 
        mp[p] = l; 
    }

    int m; cin >> m;  // 명령문 개수
    for(int i=0; i<m; i++){ 
        string commend;  cin >> commend; 

        if(commend == "recommend"){
            int order;  cin >> order;
            if(order == 1){         // 가장 어려운 난이도 번호 출력 
                auto iter = prob.rbegin(); 
                cout << iter -> second << "\n"; 
            }            
            else{
                auto iter = prob.begin();
                cout << iter -> second << "\n"; 
            }                    
        }
        else if(commend == "add"){
            int p, level;  cin >> p >> level; 
            prob.insert({level, p}); 
            mp[p] = level; 
        }
        else if(commend == "solved"){
            int p;  cin >> p;     // 리스트 內 문제 번호 
            prob.erase({mp[p],p});
        }
    }
}   

