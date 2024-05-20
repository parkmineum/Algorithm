#include <vector>
#include <iostream>
#include <cmath> 
using namespace std;

bool check_prime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int ans = 0, sum = 0;
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            for(int z = j + 1; z < nums.size(); z++) {
                sum = nums[i] + nums[j] + nums[z];
                if(check_prime(sum)) ans++;
            }
        }
    }
    return ans;
}