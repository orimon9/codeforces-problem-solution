#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1;  
        cin >> x2 >> y2;  
        
  
        int dx = x2 - x1;
        int dy = y2 - y1;
        
      
        if (abs(dx - dy) > 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
