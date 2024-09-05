//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: O R Imon( TAMK, SE'24)
 ** @Category:
/** ========================================**/

#include<bits/stdc++.h>
#include<stdio.h>
#define ll                  long long
#define scl(n)              scanf("%lld", &n)
#define fr(i,n)             for (ll i=0;i<n;i++)
#define fr1(i,n)            for(ll i=1;i<=n;i++)
#define pfl(x)              printf("%lld\n",x)
#define endl 	    "\n"
#define pb                  push_back
#define asort(a)            sort(a,a+n)
#define dsort(a)            sort(a,a+n,greater<int>())
#define vasort(v)         sort(v.begin(), v.end());
#define vdsort(v)         sort(v.begin(), v.end(),greater<int>());
#define pn                  printf("\n")
#define md                  10000007
#define debug               printf("I am here\n")
#define ps                  printf(" ")

#define N 100006

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n+1),b(n+1),dp1(n+1,0),dp2(n+1,0);
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];

    for(int i=1;i<=n;i++)
    {
        dp1[i]=max(dp1[i-1],a[i]+dp2[i-1]);
        dp2[i]=max(dp2[i-1],b[i]+dp1[i-1]);
    }

    cout<<max(dp1[n],dp2[n]);
    return 0;
}
