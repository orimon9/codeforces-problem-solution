#include<bits/stdc++.h>
#include<iomanip>

using namespace std;

int main()
{
    int abc;
    cin>>abc;
    //extract digit a,b,c from the integer abc

    int a=abc/100;
    int b=(abc/10)%10;
    int c=abc%10;

    int bca=b*100+c*10+a;
    int cab=c*100+a*10+b;

    int sum=abc+bca+cab;

    cout<<sum<<endl;
    return 0;

}
