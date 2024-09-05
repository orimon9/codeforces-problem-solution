//! Bismillahi-Rahamanirahim.
/** ========================================**
 ** @Author: O R Imon( TAMK, SE'24)
 ** @Category:
/** ========================================**/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int>A(2*N);
    for(int i=0;i<2*N;++i){
        cin>>A[i];
    }

    unordered_map<int, vector<int>> positions;
    for(int i=0;i<2*N;i++){

        positions[A[i]].push_back(i);
    }

    int count=0;

    for(const auto&entry:positions){
        const vector<int>& pos=entry.second;
        if(pos.size()==2 && pos[1]-pos[0]==2)
        {
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
