#include<bits/stdc++.h>

using namespace std;
const int N=1e6+10;

int main()

{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        int num=n/2;
        if(n%2==0)
        {
            for(int i=num,j=n;i>=1,j>num;i--,j--)
            {
                cout<<i<<" "<<j<<" ";
            }
            cout<<endl;
        }
        else
        {
            for(int i=num+1,j=n;i>=1,j>num+1;i--,j--)
                cout<<i<<" "<<j<<" ";
            cout<<"1"<<endl;
        }
    }
    return 0;

}
