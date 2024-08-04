#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> v;
int L, C;

bool check(string& s) {
	int ja = 0, mo = 0;
	for (auto& x : s) {
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') mo++;
		else ja++;
	}
    if (ja >= 2 && mo >= 1)  return true;
    else  return false; 
}
void solve(string pw, int i) {
	if (pw.length() == L) {
		if (check(pw)) {
			cout << pw << "\n";
			return;
		}
	}
	if (i >= v.size()) return;
	solve(pw + v[i], i + 1);
	solve(pw, i + 1);
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> L >> C;       // 구성 알파벳 수, 사용 가능한 알파벳 수 
	for (int i = 0; i < C; i++) {
		char c;  cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	solve("", 0);
}