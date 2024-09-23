#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int a, b, c;
vector<pair<int, int>> apple;
int main()
{
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		apple.push_back({ b,c });
	}
	sort(apple.rbegin(), apple.rend());
	int cnt = 0;
	int pre = apple[4].first;
	for (int i = 5; i <a; i++) {
		if (pre == apple[i].first)
			cnt++;
		else
			break;
		//cout << apple[i].first<<" " << apple[i].second<<"\n";
	}
	cout << cnt;
	
}
