#include<iostream>
using namespace std;
long double probability(unsigned numbers,unsigned picks){
    long double result=1;
    for(long double n = numbers, p = picks; p > 0; n--, p--){
        result*=n/p;
    }
    return result;
}
int main(){
    double total,choices;
    while(cin>>total>>choices &&total>=choices){
        cout<<probability(total,choices)<<endl;
    }
    return 0;
}