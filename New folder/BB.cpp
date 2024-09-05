#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaximumBalancedShipments(vector<int>& weight)
{
    int n = weight.size();
    int maxShipments = 0;
    int i = 0;

    while (i < n)
    {
        int maxInSegment = weight[i];
        int segmentEnd = i;
        bool foundBalanced = false;


        while (segmentEnd < n)
        {
            maxInSegment = max(maxInSegment, weight[segmentEnd]);


            if (weight[segmentEnd] != maxInSegment)
            {
                foundBalanced = true;
                break;
            }
            segmentEnd++;
        }


        if (foundBalanced)
        {
            maxShipments++;
            i = segmentEnd + 1;
        }
        else
        {

            break;
        }
    }

    return maxShipments;
}

int main()
{
    int n;
    cin >> n;
    vector<int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    int result = findMaximumBalancedShipments(weight);
    cout << result << endl;

    return 0;
}
