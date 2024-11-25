#include<bits/stdc++.h>

using namespace std;


#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define SZ(a)           (int)a.size()
#define all(a)  a.begin(), a.end()
#define allr(a)  a.rbegin(), a.rend()


#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("d",&a,&b)
#define sfff(a,b,c)     scanf("d%d",&a,&b,&c)

#define f0(i,b) for(int i=0;i<(b);i++)
#define f1(i,b) for(int i=1;i<=(b);i++)
#define f2(i,a,b) for(int i=(a);i<=(b);i++)
#define fr(i,b,a) for(int i=(b);i>=(a);i--)

#define CIN ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define TEST_CASE(t) for(int z=1 ; z<=t ; z++)
#define PRINT_CASE printf("Case %d: ",z)
#define Debug(x)            cout<<#x " = "<<(x)<<endl
#define NOT_VISITED 0
#define IS_VISITED 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int fx[4]= {1,-1,0,0};
int fy[4]= {0,0,1,-1};

const double PI = acos(-1.0);
const double EPS = 1e-6;
const int MOD = (int)1e9+7;
const int maxn = (int)2e5+5;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;

vector < int > graph[maxn];
int n;
bool visited[maxn];
vector < int > store;

void dfs(int u)
{
    visited[u]=1;
    store.pb(u);
    for(int i=0 ; i<graph[u].size() ; i++){
        if(!visited[i]){
            dfs(graph[u][i]);
        }
    }
}

int main()
{

    cin>>n;

    for(int i=2 ; i<=n ; i++)
    {
        int x;
        cin>>x;
        graph[i].pb(x);
    }

    dfs(n);

    for(int i=store.size()-1 ; i>=0 ; i--) cout<<store[i]<<" ";





    return 0;
}
