#define _CRT_SECURE_NO_WARNINGS 1
#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
#include<unordered_set>

#define ll long long
#define all(x) (x).begin(), (x).end()
#define do_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }
ll lowbit(ll x, ll y) { return x & (-x); }

using namespace std;
void run() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }

ll t;
ll k;
ll x, y, z;
ll m;
ll n;
char C;
string s, s1, s2;

/**/ 			    #define $$ <<" "
/**/	        	#define $ <<"\n"
/**/	        //	#define $ <<"\n"<<"\n"



int main()
{
	run();

	ll test;
	cin >> test;
	for (int ii = 0; ii < test; ii++)
	{
		cin >> n;
		vector<int>p(n), q(n);
		for (int i = 0; i < n; i++)
			cin >> p[i];
		for (int j = 0; j < n; j++)
			cin >> q[j];
		for (int i = 0; i < n; i++)
			p[i] = q[i] - p[i];
		sort(all(p));
		ll res = 0;
		ll l = 0, r = n - 1;
		while (l < r)
		{
			if (p[l] + p[r] >= 0)
			{
				res++;
				r--;
				l++;
			}
			else l++;
		}
		cout << res $ $;


	}


	return 0;
}
