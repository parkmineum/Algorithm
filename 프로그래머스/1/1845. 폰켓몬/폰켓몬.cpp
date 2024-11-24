#include <vector>
#include <set> 
using namespace std;

// [3,1,2,3] -> 3번 두마리, 1번 & 2번 각 한마리 
// n마리 -> 최대 n/2마리 가져갈 수 있음 
int solution(vector<int> nums){
    int ans = 0;
    set<int> S; 
    
    for(int i=0; i<nums.size(); i++) S.insert(nums[i]);   // set에 복사하므로써, 중복 제거 
    
    int n = nums.size()/2;
    if(S.size()<=n) ans = S.size();   // S.size() : 종류 수 
    else ans = n; 
    
    return ans;
}