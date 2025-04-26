#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    struct Candybar{
        string label = "Monach Bar";
        double weight = 2.3;
        int calories = 350;
    } ;
    int n;
    cout<<"Please enter the number of candybars you want to add: ";
    cin>>n;
    vector<Candybar> candybars(n);
    for(int i=0;i<n;i++){
        cout<<"Enter the label of candybar "<<i+1<<": ";
        getline(cin,candybars[i].label);
        cout<<"Enter the weight of candybar "<<i+1<<": ";
        cin>>candybars[i].weight;
        cout<<"Enter the calories of candybar "<<i+1<<": ";
        cin>>candybars[i].calories;
    }
    cout<<"The candybars are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Label: "<<candybars[i].label<<", Weight: "<<candybars[i].weight<<" lbs, Calories: "<<candybars[i].calories<<" cal"<<endl;
    }
    

    return 0;
}