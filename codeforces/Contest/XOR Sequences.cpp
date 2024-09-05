#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(),x.end()
#define ll long long

void solve() {
    ll x,y;
    cin>>x>>y;
    ll ans=x^y;
    int i=0;
    while(!(ans&1)){
    	i++;
    	ans=ans>>1;
    }
    cout<<(1<<i)<<endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve();
    }
 return 0;
}
