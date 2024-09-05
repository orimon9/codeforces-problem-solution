#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

int main()

{
    int a,b;
    cin>>a>>b;

    //calculator integer division

    int d=a/b;

    //calculator reminder

    int r=a%b;

    //calculate floating point division
    double f=static_cast<double>(a)/b;

    cout<<d<<" "<<r<<" "<<fixed<< setprecision(5) <<f<<endl;
    return 0;

}
