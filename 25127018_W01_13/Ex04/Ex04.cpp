#include<iostream>
#include<cmath>
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
    char a[n][m];
    //Complexity: O(n^2)
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    //We can declare to find min row, column and max row, column
    int minh = INT_MAX, minc = INT_MAX, maxh = 0, maxc = 0;
    //We can use bubble sort to find these
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '*'){
                minh = min(minh, i);
                minc = min(minc, j);
                maxh = max(maxh, i);
                maxc = max(maxc, j);
            }
        }
    }
    //Finally, from min row, column and max row, column, we can print the answer
    for(int i=minh; i<=maxh; i++){
        for(int j=minc; j<=maxc; j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
//test case 1
//Input:
//6 7
//.......
//..***..
//..*....
//..***..
//..*....
//..***..
//Ans:
//***
//*..
//***
//*..
//***

//test case 2
//Input:
//3 3
//***
//*.*
//***
//Ans:
//***
//*.*
//***

//test case 3
//Input:
//1 1
//*
//Ans:
//*

int main(){
//	file();
	xuli();
	return 0;
}
