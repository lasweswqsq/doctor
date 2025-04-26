#include<iostream>
#include<vector>
#include<array>
using namespace std;
int main(){
    vector<double> a1(4);
    a1[0] = 1.1;
    a1[1] = 2.2;
    a1[2] = 3.3;
    a1[3] = 4.4;
    array<double, 4> a2 = {1.1, 2.2, 3.3, 4.4};
    cout<<"a1[0] = "<<a1[0]<<" at "<<&a1[0]<<endl;
    cout<<"a2[0] = "<<a2[0]<<" at "<<&a2[0]<<endl;
    cout<<"a2[0] = "<<a2[0]<<endl;
    cout<<"a1[-2] = "<<a1[-2]<<" at "<<&a1[-2]<<endl;
    cout<<"a2[-2] = "<<a2[-2]<<" at "<<&a2[-2]<<endl;
    a1[-2] = 5.5;
    cout<<"a1[-2] = "<<a1[-2]<<" at "<<&a1[-2]<<endl;
    a2[-2] = 5.5;
    cout<<"a2[-2] = "<<a2[-2]<<" at "<<&a2[-2]<<endl;
    return 0;   

}