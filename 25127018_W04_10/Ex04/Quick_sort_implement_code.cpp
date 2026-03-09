#include<bits/stdc++.h>
using namespace std;
#define task "TEST"
void file(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".inp","r",stdin);
	freopen(task".out","w",stdout);
}
int part(vector<int>& a, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);
    
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void Quick_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        int pi = part(a, low, high);
        Quick_sort(a, low, pi - 1);
        Quick_sort(a, pi + 1, high);
    }
}
void xuli(){
	int n; cin>>n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	Quick_sort(a, 0, n-1);
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
}
int main(){
	file();
	xuli();
	return 0;
}


