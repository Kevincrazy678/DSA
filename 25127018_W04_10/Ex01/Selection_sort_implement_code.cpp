#include<bits/stdc++.h>
using namespace std;
#define task "TEST"
void file(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}
void selection_sort(vector<int>&a, int n){
	for(int i=0; i<n-1; i++){
		int min_idx = i;
		for(int j=i+1; j<n; j++){
			if(a[j] < a[min_idx]){
				min_idx = j;
			}
		}
		if(min_idx != i){
			swap(a[i], a[min_idx]);
		}
	}
}
void xuli(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	selection_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	file();
	xuli();
	return 0;
}


