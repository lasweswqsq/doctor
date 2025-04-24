#include<iostream>
using namespace std;
int main(){
    int year;
    cout<<"Enter the year: ";
    (cin>>year).get();
    cout<<"What is your address?";
    char address[100];
    cin.getline(address,100);
    cout<<"Your address is: "<<address<<endl;
    return 0;
}