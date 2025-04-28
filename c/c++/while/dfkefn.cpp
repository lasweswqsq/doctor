#include<iostream>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main(){
    struct Car{
        string name;
        int year;
    };
    int num;
    cout<<"Please enter num: ";
    cin>>num;
    vector <Car> cars(num);
    for(int i=0;i<num;i++){
        cout<<"Please enter the name of the car"<<i+1<<": ";
        getline(cin,cars[i].name);
        cout<<"Please enter the year of the car"<<i+1<<": ";
        cin>>cars[i].year;
    }
    for(int i=0;i<num;i++){
        cout<<"Name of the car"<<i+1<<" is "<<cars[i].name<<endl;
        cout<<"Year of the car"<<i+1<<" is "<<cars[i].year<<endl;
    }
    return 0;
}