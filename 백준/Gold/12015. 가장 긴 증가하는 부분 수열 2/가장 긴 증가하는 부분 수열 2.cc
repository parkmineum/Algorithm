#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std; 

vector<int> vec; 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    for(int i=0; i<n; i++){
        int num; cin >> num;   // 10 20 10 30 20 50 

        // 자동 오름차순 정렬되므로 lower_bound 사용 가능 
        if(i!=0 && num <= vec.back()){
            auto tmp = lower_bound(vec.begin(),vec.end(),num);
            *tmp = num; 
            continue; 
        }
        vec.push_back(num); 
    }
    cout << vec.size(); 
}