#include<iostream>
using namespace std;
int main(){
    struct antarctica{
        int year;
        double temperature;
        string polabears;
    };
    antarctica a1,a2,a3;
    a1.year=2015;
    a1.temperature=1.5;
    a1.polabears="cold";
    antarctica *p1=&a1,*p2=&a2,*p3=&a3;
    p1->year = 2016;
    cout<<a1.year<<a1.temperature<<a1.polabears<<endl;
}