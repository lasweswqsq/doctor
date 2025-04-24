#include<iostream>
using namespace std;
int main()
{
    const int Arsize = 30;
    char name[Arsize];
    char restaraunt[Arsize];
    cout<<"Enter your name: ";
    cin.getline(name,Arsize);
    cout<<"Enter your favorite restaraunt: ";
    cin.getline(restaraunt,Arsize);
    cout<<"Your name is: "<<name<<endl;
    cout<<"Your favorite restaraunt is: "<<restaraunt<<endl;
    return 0;
}