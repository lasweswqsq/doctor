#include<iostream>
using namespace std;
int main(){
    char first_name[50],last_name[50];
    int age;
    cout<<"Enter your first name: ";
    cin.getline(first_name,50);
    cout<<"Enter your last name: ";
    cin.getline(last_name,50);
    cout<<"Enter your age: ";
    cin>>age;
    cout<<"Your name is "<<first_name<<" "<<last_name<<" and your age is "<<age<<endl;
    return 0;
}