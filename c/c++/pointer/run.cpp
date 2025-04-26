#include <iostream>
#include <array>
using namespace std;
int main(){
    array<double,3> time;
    cout<<"Enter your 50m score: ";
    cin>>time[0];
    cout<<"Enter your 100m score: ";
    cin>>time[1];
    cout<<"Enter your 200m score: ";
    cin>>time[2];
    double average = (time[0]+time[1]+time[2])/3;
    cout<<"Your average time is: "<<average<<endl;
    return 0;
}