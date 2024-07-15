#include <string>
#include <vector>
#include <unordered_map> 
using namespace std;

// 제품 모두 할인 받을 수 있는 날짜와 일수 return
// 원하는 제품, 제품의 수량, 할인 품목 
 
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    // 정렬되지 않은 해시
    unordered_map<string,int> cart; 
    
    for(int i = 0; i < number.size(); i++)   cart.insert({want[i], number[i]});
    
    // discount size는 최소 10부터이다. 
    int ans = 0; 
    for(int i = 0; i <= discount.size()-10; i++) {
        unordered_map<string,int> discountMap;
        
        for(int j=i; j< i+10; j++)  discountMap[discount[j]]++;
        if(discountMap == cart)  ans++;
    }
    
    return ans;
}