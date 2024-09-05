//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: O R Imon( TAMK, SE'24)
 ** @Category:
/** ========================================**/

#include<bits/stdc++.h>
#include<stdio.h>
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
typedef long long ll;
void fa()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    fa();
    ll n;
    cin>>n;
    ll maxa=0,maxb=0;
    while(n--)
    {
        ll a,b;
        char ch;
        cin>>ch>>a>>b;
        if(a<b)
            swap(a,b);
        if(ch=='+')
        {
            maxa=max(a,maxa);
            maxb=max(b,maxb);

        }
        else
        {
            if(maxa<=a&&maxb<=b)
                cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}
