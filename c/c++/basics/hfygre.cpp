#include<iostream>
#include<cmath>
using namespace std;
int main(){
    auto x=10;
    auto str = "Hello World";
    cout<<x<<endl;
    cout<<str<<endl;
    double n = 10;
    int sum = 3847;
    double average = static_cast<double>(sum) / n;
    double pos = static_cast<double>(std::sqrt(n));
    cout<<"Sum: "<<sum<<endl;
    cout<<"Average: "<<average<<endl;
    cout<<"Position: "<<pos<<endl;
    return 0;
}