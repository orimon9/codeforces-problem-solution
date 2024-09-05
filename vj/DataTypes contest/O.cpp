#include<bits/stdc++.h>

using namespace std;

    int zero(int n){
    int c=0;

    while((n%2)==0){

        n/=2;
        c++;
    }
    return c;
}

int main(){
int N;
cin>>N;

int r=zero(N);
cout<<r<<endl;

return 0;
}
