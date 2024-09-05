#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    std::cin>>t;
    while(t--){
        int a,b,c;
        std::cin>>a>>b>>c;

        int t1=std::abs(a-1); //1st elevator

        int t2=std::abs(b-c)+std::abs(c-1); //2nd elevator

        if(t1<t2){
            std::cout<<"1\n";
        }
        else if(t2<t1){
            std::cout<<"2\n";
        }
        else{
            std::cout<<"3\n";
        }
    }
    return 0;
}
