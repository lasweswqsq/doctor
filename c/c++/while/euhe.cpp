#include<iostream>
#include<cctype>
using namespace std;

int main(){
    double person1 = 100;
    double person2 = 100;
    do{
        person1 +=10;
        person2 *=1.05;
    }while(person1>person2);
    cout<<"Person 1 has $"<<person1<<" and Person 2 has $"<<person2<<endl;

    char ch;
    do{
        cout<<"Enter a character: ";
        cin>>ch;
    }while(!isalpha(ch));
    cout<<"You entered a letter: "<<ch<<endl;

    return 0;
}