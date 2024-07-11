#include <iostream> 
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque> 
using namespace std; 

int n, m;
int parent[100001];
int result;
int getParent(int num) {
	if (num == parent[num]) return num;
	return parent[num] = getParent(parent[num]);

}
void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);

	if (a != b) {
		parent[a]= b;
	}
}
bool findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	vector<pair<int, pair<int, int>>> edge(m);
	for (int i = 0; i < m; i++) {
		int cost, a, b;
		cin >> a >> b >> cost;
		edge[i] = { cost,{a,b} };
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	sort(edge.begin(), edge.end());

	int maxCost = 0;
	for (int i = 0; i < m; i++) {
		int cost = edge[i].first;
		int a = edge[i].second.first;
		int b = edge[i].second.second;
		if (!findParent(a, b)) {
			maxCost = max(maxCost, cost);
			result += cost;
			unionParent(a, b);
		}
	}
	cout << result-maxCost;


}