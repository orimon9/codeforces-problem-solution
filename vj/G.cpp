//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: O R Imon( TAMK, SE'24)
 ** @Category:
/** ========================================**/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;


int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    string num;
    cin >> num;

    string goal(x, '0');
    goal[x - y - 1] = '1';

    int ch = 0;
    for (int i = 0; i < x; ++i)
    {
        if (num[n - x + i] != goal[i])
        {
            ch++;
        }
    }

    cout << ch << endl;
    return 0;
}
