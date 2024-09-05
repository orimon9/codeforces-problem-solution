#include<iostream>
#include<cstring>
#include<utility>
#define N 200005
#define S 15
using namespace std;
typedef pair<int,int>pii;
char s[N];
int cnt[N];
int f[S][2];
void solve()
{
    cin>>s+1;
    int n=strlen(s+1);
    for(int i=1; i<=n; ++i)cnt[i]=cnt[i-1]+s[i]-'0';
    int w,m;
    cin>>w>>m;
    for(int i=0; i<9; ++i)f[i][0]=f[i][1]=1e9;
    for(int i=1; i+w-1<=n; ++i)
    {
        int k=(cnt[i+w-1]-cnt[i-1])%9;
        if(i<f[k][0])f[k][1]=f[k][0],f[k][0]=i;
        else if(i<f[k][1])f[k][1]=i;
    }
    while(m--)
    {
        int l,r,k;
        cin>>l>>r>>k;
        pii ans= {1e9,1e9};
        for(int i=0; i<9; ++i)
        {
            int j=((k-(cnt[r]-cnt[l-1])*i)%9+9)%9;
            if(i==j)
            {
                if(f[i][0]+f[i][1]<1e9)ans=min(ans, {f[i][0],f[i][1]});
            }
            else if(f[i][0]+f[j][0]<1e9)
            {
                ans=min(ans, {f[i][0],f[j][0]});
            }
        }
        if(ans.first+ans.second>1e9)cout<<"-1 -1\n";
        else cout<<ans.first<<" "<<ans.second<<"\n";
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
