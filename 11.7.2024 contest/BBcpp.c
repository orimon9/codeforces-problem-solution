#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second
#define int long long
typedef pair<int, int>ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;

int32_t main(){_
    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        vector<int> v(s.size());
        for(int i = 0; i < n; i++) v[i] = s[i]-'0';

        vector<int> aux;
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(v[i]==0){
                int tira;
                if(i+1 < n and v[i+1]==0) tira = 1;
                else tira = 2;
                for(int i = 0; i < aux.size()-tira; i++){
                    ans.pb(aux[i]);
                }
                int val;
                if(i+1 < n and v[i+1]==0){
                    val = aux[aux.size()-1] * 10;
                    i++;
                }else val = aux[aux.size()-1] + 10*aux[aux.size()-2];
                ans.pb(val);
                aux.clear();
            }else aux.pb(v[i]);
        }
         for(int i = 0; i < aux.size(); i++){
            ans.pb(aux[i]);
        }


        for(int i = 0; i < ans.size(); i++) cout << (char)(ans[i]-1+'a');
        cout << endl;
    }
}
