#include<bits/stdc++.h>

#define ll long long int
#define nline '\n'

using namespace std;

void sol()
{
    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll cnt=0;

    for(auto ch:s){

        if(ch=='Q')
            cnt++;
        else
            cnt--;

        if(cnt<0)
            cnt=0;
    }
    if(cnt==0)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll T=1;
cin>>T;
while(T--)
{
    sol();
}
}
