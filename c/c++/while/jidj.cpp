#include<iostream>
using namespace std;
int main(){
    int golf[5];
    cout<<"Enter golf scores: ";
    int i;
    for(i=0;i<5;i++){
        cout<<"Score "<<i+1<<": ";
        while(!(cin>>golf[i])){
            cout<<"Invalid input. Please enter a number: ";
            cin.clear();
            while(cin.get()!='\n'){
                continue;
            }
        }
    }
}