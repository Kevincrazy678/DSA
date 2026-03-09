#include<bits/stdc++.h>
using namespace std;
#define task "TEST"
void file(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}
void insertion_sort(vector<int>&a, int n){
	for(int i=1; i<n; i++){
		int key = a[i], j = i-1;
		while(j>=0 && a[j] > key){
			a[j+1] = a[j];
			j = j - 1;
		}
		a[j+1] = key;
	}
}
void xuli(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	insertion_sort(a, n);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	file();
	xuli();
	return 0;
}


