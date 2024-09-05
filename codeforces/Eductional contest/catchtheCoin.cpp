#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Coin {
    int x;
    int y;
};

bool canCollectCoin(int x, int y, const vector<Coin>& coins) {
    queue<pair<int, int>> moves;
    moves.push({0, 0});

    int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    const int MAX_MOVEMENT = 50;

    while (!moves.empty()) {
        int cx = moves.front().first;
        int cy = moves.front().second;
        moves.pop();

        for (const Coin& coin : coins) {
            if (cx == coin.x && cy == coin.y) {
                return true;
            }
        }

        for (int i = 0; i < 8; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];


            if (abs(nx) <= MAX_MOVEMENT && abs(ny) <= MAX_MOVEMENT) {
                moves.push({nx, ny});
            }
        }


        for (Coin& coin : coins) {
            coin.y--;

            if (coin.y < -MAX_MOVEMENT) {
                return false;
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Coin> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i].x >> coins[i].y;
    }

    for (const Coin& coin : coins) {
        if (canCollectCoin(0, 0, coins)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
