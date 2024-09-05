#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {

            int n,k;
            cin>>n>>k;
            vector<vector<char>>grid(n,vector<char>(n));

            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){

                    cin>>grid[i][j];
                }
            }
            int reduced_size=n/k;
            vector<vector<char>> reduced_grid(reduced_size, vector<char>(reduced_size));
            for (int i = 0; i < reduced_size; ++i) {
            for (int j = 0; j < reduced_size; ++j) {
                reduced_grid[i][j] = grid[i * k][j * k];
            }
        }
            for (int i = 0; i < reduced_size; ++i) {
            for (int j = 0; j < reduced_size; ++j) {
                cout << reduced_grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
