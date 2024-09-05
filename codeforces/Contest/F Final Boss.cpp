#include <bits/stdc++.h>

using namespace std;

struct Attack {
    int damage;
    int cooldown;
    int nextAvailableTurn;

    bool operator<(const Attack& other) const {
        return nextAvailableTurn > other.nextAvailableTurn;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long h;
        int n;
        cin >> h >> n;

        vector<int> damage(n);
        vector<int> cooldown(n);

        for (int i = 0; i < n; ++i) {
            cin >> damage[i];
        }

        for (int i = 0; i < n; ++i) {
            cin >> cooldown[i];
        }

        priority_queue<Attack> pq;
        for (int i = 0; i < n; ++i) {
            pq.push({damage[i], cooldown[i], 1});
        }

        int currentTurn = 0;
        long long totalDamage = 0;

        while (h > 0) {
            currentTurn++;
            long long damageThisTurn = 0;

            vector<Attack> toReinsert;
            while (!pq.empty() && pq.top().nextAvailableTurn <= currentTurn) {
                Attack atk = pq.top();
                pq.pop();
                damageThisTurn += atk.damage;
                atk.nextAvailableTurn += atk.cooldown;
                toReinsert.push_back(atk);
            }

            for (const auto& atk : toReinsert) {
                pq.push(atk);
            }

            h -= damageThisTurn;
        }

        cout << currentTurn << endl;
    }

    return 0;
}

