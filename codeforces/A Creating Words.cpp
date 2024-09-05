#include<iostream>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--) {
        string a,b;
        cin>>a>>b;

        string in_a=b[0] +a.substr(1,2);
        string in_b=a[0] +b.substr(1,2);

        cout<<in_a<<" "<<in_b<<endl;

    }

    return 0;
}
