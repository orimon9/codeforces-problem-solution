#include<bits/stdc++.h>
#include<string>

int main(){
std::string S,T;
std::cin>>S>>T;

int res=0;

for(int i=0;i<S.length();i++){

    if(S[i]!=T[i]){
        res++;
    }
}
std::cout<<res<<std::endl;
return 0;
}
