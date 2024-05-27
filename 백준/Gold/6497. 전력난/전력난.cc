#include<iostream>
#include<algorithm>
using namespace std;


int m, n;

pair<long, pair<int, int>> edge[200001];
int parents[200001];

long res=0;
int edgenum = 0;


int Find(int x){
	if (x == parents[x])
		return x;
	return parents[x] = Find(parents[x]);
}

void Union(int x, int y){
	x = Find(x);
	y = Find(y);

	if (x == y)  return;
	parents[x] = y;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, y, z;
	while(1){
		edgenum = 0;
		res = 0;
        
		cin >> m >> n;

		if (m == 0 && n == 0)  break;
        
		for (int i = 0; i <= n; i++){
			parents[i] = i;
			edge[i] = { 0,{0,0} };
		}

		for (int i = 0; i < n; i++) {
			cin >> x >> y >> z;
			edge[i] = { z,{x,y} };
			res += z;
		}
		sort(edge, edge + n);

		for (int i = 0; i < n; i++){
			if (Find(edge[i].second.first) == Find(edge[i].second.second))
				continue;

			Union(edge[i].second.first, edge[i].second.second);
			res -= edge[i].first;

			edgenum++;
			if (edgenum == m - 1)
				break;
		}
		cout << res<<'\n';
	}
}