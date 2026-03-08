#include<iostream>
using namespace std;
#define ll long long
void xuli(){
	ll n, d, res = 0; 
	cin>>n>>d;
	
	ll *a = new ll[n];
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	// Time and Complexity: O(n) because we need to access to all value of the array
	for(int i=1; i<n; i++){
		if(a[i] <= a[i-1]){ // for ex: a4 <= a3 like 3 <= 2
			ll sum = a[i-1] - a[i]; 
			//check if a[i] and a[i-1] is equal
			if(sum == 0){
				res += 1;
				a[i] += d;
			}
			else{
				sum/=d;
				a[i] += sum*d;
				//condition that makes the array increasing at least 1 value
				if(a[i] <= a[i-1]){
					a[i] += d;
					res += sum+1;
				}
				else res += sum;
			}
		}
	}
	// Print the answer
	cout<<res;
	delete[] a;
}
//test case 1
//4 2
//1 3 3 2
//Ans: 3

//test case 2
//2 1
//1 1
//Ans: 1

//test case 3
//2 1
//2 5
//Ans: 0
int main(){
	xuli();
	return 0;
}
