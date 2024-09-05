#include<bits/stdc++.h>
#include <unordered_map>

using namespace std;

long long Operation(long long x, long long y, long long k)
{
    while (k--)
    {
        x += 1;
        while (x % y == 0)
        {
            x /= y;
        }
    }
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, k;
        cin >> x >> y >> k;
        cout << Operation(x, y, k) << endl;
    }
    return 0;
}
