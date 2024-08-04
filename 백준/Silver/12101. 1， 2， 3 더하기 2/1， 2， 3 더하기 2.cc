#include<iostream>
#include<vector>
using namespace std;
int n, k, cnt;
void solve(vector<int>& v, int sum) {
    if (sum > n) return;  
    if (sum == n) {
            cnt++; 
                if (cnt == k) { //k번째라면
                       for (int i = 0; i < v.size(); i++) {  //1,2,3으로 이루어진 벡터를 크기만큼(전체)를 출력
                                 if (i == v.size() - 1) cout << v[i]; // 마지막 숫자를 출력할때는 "+"기호를 붙이지않는다.
                                 else cout << v[i] << "+";
                       }
               }
           return; 
    }
    for  (int i = 1; i <= 3; i++) { // 1,2,3으로 이루어지므로
            v.push_back(i); 
            solve(v, sum + i); // sum에 i를 더하고 다시 함수를 실행한다.
            v.pop_back(); 
    }
}
int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      cin >> n >> k;
      vector<int> v;
      solve(v, 0);  // 인수로 vector와 0을 넣어준다. // 현재 합(sum)은 0이기 때문이다.
     if (cnt == 0 || cnt < k) cout << "-1";  // 합의 개수가 0개 즉, 없거나 k개보다 적은 경우 -1을 출력한다.
}