#include <iostream> 
#include <vector>
#include <algorithm>
#include <string> 
#include <map> 
using namespace std; 

int main(){
    int n; cin >> n; 
    
    long long ans = 0; 
    for(int i=1; i<=n; i++)   ans += (n/i)*i; 
    
    cout << ans << "\n"; 
    
    return 0; 
}