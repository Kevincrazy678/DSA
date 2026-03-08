#include<iostream>
using namespace std;
#define ll long long
void xuli(){
	bool check = true;
	char **a = new char *[3];
	for(int i=0; i<3; i++){
		a[i] = new char[3];
		for(int j=0; j<3; j++){
				cin>>a[i][j];
		}
	}
	//Complexity: O(1) 
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			//check the symmetry of the matrix
			if(i==0 && j==0){
				if(a[i][j] != a[2][2])check = 0;
			}
			else{
				if(a[i][j] != a[2-i][2-j])check = 0;
			}
			//if we checked 1 condition that hadn't satisfied, we can immediately stop the loop 
			if(!check)break;
		}
	}
	if(check)cout<<"YES";
	else cout<<"NO";
	for(int i=0; i<3; i++){
		delete[] a[i];
	}
	delete[] a;
}
//test case 1
//XX.
//...
//.XX
//Ans: YES

//test case 2
//X.X
//X..
//...
//Ans: NO

//test case 3
//...
//...
//...
//Ans: YES
int main(){
	xuli();
	return 0;
}
