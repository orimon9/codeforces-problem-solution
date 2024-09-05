#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ask_query(vector<int>& p, vector<int>& q) {
    cout << p.size() << " " << q.size() << " ";
    for (int node : p) {
        cout << node << " ";
    }
    for (int node : q) {
        cout << node << " ";
    }
    cout << endl;
    cout.flush();

    int dist;
    cin >> dist;
    if (dist == -1) {
        exit(0);
    }
    return dist;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        // Initialize the sets of nodes
        vector<int> p, q;
        for (int i = 1; i <= n; ++i) {
            if (i <= n / 2) {
                p.push_back(i);
            } else {
                q.push_back(i);
            }
        }

        // Find the distance between the farthest nodes in p and q
        int max_distance = ask_query(p, q);

        // Try to find a node in p which is closer to a node in q
        reverse(p.begin(), p.end());
        for (int node : p) {
            vector<int> new_q = {node};
            int distance = ask_query(new_q, q);
            max_distance = max(max_distance, distance);
        }

        cout << "-1 " << max_distance << endl;
        cout.flush();
    }

    return 0;
}
