#include<iostream>
using namespace std;
int main(){
    struct woman{
        string name;
        int age;
        float height;
    } smith1, smith2;
    smith1.name = "Smith";
    smith1.age = 30;
    smith1.height = 1.7;
    smith2.name = "Jones";
    smith2.age = 25;
    smith2.height = 1.6;
    cout<<"Name of first woman: "<<smith1.name<<endl;
    cout<<"Age of first woman: "<<smith1.age<<endl;
    cout<<"Height of first woman: "<<smith1.height<<endl;
    cout<<"Name of second woman: "<<smith2.name<<endl;
    cout<<"Age of second woman: "<<smith2.age<<endl;
    cout<<"Height of second woman: "<<smith2.height<<endl;
    return 0;
    
}