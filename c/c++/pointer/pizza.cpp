#include<iostream>
using namespace std;
int main(){
    struct Pizza{
        string name;
        double d;
        double weight;
    };
    Pizza *p1 = new Pizza;
    cout<<"Enter name of Pizza: ";
    getline(cin,p1->name);
    cout<<"Enter diameter of Pizza: ";
    cin>>p1->d;
    cout<<"Enter weight of Pizza: ";
    cin>>p1->weight;
    cout<<"Name of Pizza: "<<p1->name<<endl;
    cout<<"Diameter of Pizza: "<<p1->d<<" inches"<<endl;
    cout<<"Weight of Pizza: "<<p1->weight<<" oz"<<endl;
    delete p1;
    return 0;

}