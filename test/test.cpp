#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define task "BAI1"
const int maxn = 2*1e5;
const int INF=1e9;
void file(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}
void xuli(){
	int n, m; cin>>n>>m;
	int x = min(n, m);
	vector<pair<int, int>>a;
	while(n > 0 || m > 0){
		a.push_back({x, x});
		if(n >= m){
			n -= x;
		}
		else{
			m -= x;
		}
		if(n!=0 && m!=0)x = min(n, m);
		if(n == 0 && m == 0)break;
	}
	for(auto x : a){
		cout<<x.first<<" "<<x.second<<endl;
	}
}
int main(){
//	file();
	xuli();
	return 0;
}


