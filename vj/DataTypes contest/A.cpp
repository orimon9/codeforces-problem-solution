#include<iostream>

using namespace std;

int main(){
int x;
cin>>x;

int ld=x%100;

cout<<"k"<<(ld<10? "0" : "")<<ld<<endl;
return 0;

}
