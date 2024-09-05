#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        long long l, r;
        cin >> n >> l >> r;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int maxRounds = 0;
        long long currentSum = 0;
        bool isPossible = false;

        for (int i = 0; i < n; ++i)
        {
            currentSum += a[i];

            if (currentSum >= l && currentSum <= r)
            {
                maxRounds++;
                currentSum = 0;
                isPossible = true;
            }
            else if (currentSum > r)
            {
                currentSum = a[i];
                if (currentSum >= l && currentSum <= r)
                {
                    maxRounds++;
                    currentSum = 0;
                    isPossible = true;
                }
            }
        }

        if (!isPossible)
        {
            for (int i = 0; i < n; ++i)
            {
                if (a[i] >= l && a[i] <= r)
                {
                    maxRounds++;
                    break;
                }
            }
        }

        cout << maxRounds << endl;
    }

    return 0;
}
