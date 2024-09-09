#include<iostream>
using namespace std;

int line[10001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int K, N;  cin >> K >> N;
    
    int maxl = 0;
	for (int i = 0; i < K; i++){
		cin >> line[i];
		if (line[i]>maxl) maxl = line[i];
	}
	long long low = 1, high, ans = 0;
    high = maxl; 
	while (low <= high){
		long long mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < K; i++)  cnt += line[i] / mid;

		if (cnt >= N) {
			low = mid + 1;
			if (mid > ans) ans = mid;
		}
		else high = mid - 1;
	}
	
	cout << ans;
}