#include<bits/stdc++.h>
using namespace std;
#define task "TEST"
int main(){
    int n = 1e5;
    ofstream fout(task".inp");
    if(!fout){
        cerr<<"Can't open file " task ".inp\n";
        return 1;
    }
    mt19937 rng(time(0));
    uniform_int_distribution<int> dist(1, 1e5);
    fout<<n<<endl;
    for(int i=0; i<n; i++){
        fout<<dist(rng) << " " <<endl;
    }
    fout.close();
    return 0;
}