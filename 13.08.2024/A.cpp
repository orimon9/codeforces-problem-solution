
    #include <bits/stdc++.h>
    #define dbg(args...) 42;
    #define endl "\n"


using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) ((lli)(x).size())
#define eb emplace_back
#define X first
#define Y second

using lli = long long int;
using mytype = long double;
using ii = pair<lli,lli>;
using vii = vector<ii>;
using vi = vector<lli>;

const auto start_time = std::chrono::high_resolution_clock::now();
void aryanc403()
{
auto end_time = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
}

const lli INF = 0xFFFFFFFFFFFFFFFLL;
const lli SEED=chrono::steady_clock::now().time_since_epoch().count();
mt19937_64 rng(SEED);
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    // freopen("txt.in", "r", stdin);
    // freopen("txt.out", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// Ve::iota(1, 6) | Ve::transform([](int x) { return x * 2; }) | Ve::reverse | Ve::take(3)
lli T=1;
cin>>T;
while(T--)
{
    string s;
    cin>>s;
    if(sz(s)<3){
        cout<<"NO"<<endl;
        continue;
    }

    string t=s.substr(2);
    const lli a=stoll(s.substr(0,2)),b=stoll(t);

    if(a!=10||b<2||t!=to_string(b)){
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }

}   aryanc403();
    return 0;
}
