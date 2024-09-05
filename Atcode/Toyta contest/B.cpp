#include<bits/stdc++.h>
#include <cmath>

using namespace std;

int distSquared(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    int xA, yA, xB, yB, xC, yC;

    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;


    int AB2 = distSquared(xA, yA, xB, yB);
    int BC2 = distSquared(xB, yB, xC, yC);
    int CA2 = distSquared(xC, yC, xA, yA);

    if (AB2 + BC2 == CA2 || AB2 + CA2 == BC2 || BC2 + CA2 == AB2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
