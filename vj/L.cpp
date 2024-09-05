//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: O R Imon( TAMK, SE'24)
 ** @Category:
/** ========================================**/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


#define N 100006

int main()
{
    ll m,n,t,b,c,d,i,j,k,x,y,z,l,q,r, cnt=0;

    string s,s1;
    cin>>n>>s;

    for(i=0; i<n; i+=2)
    {
        if(s[i] ==s[i+1] )
        {
            s.erase(s.begin()+i+1 ),cnt++, i-=2;
        }
        n=s.size();
    }

    if(n%2 !=0) s.erase(s.end()-1 ), cnt++;
    cout<<cnt<<endl<<s;

    return 0;
}
