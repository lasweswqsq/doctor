#include<iostream>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
int main(){
    struct donate{
        string name;
        double money;
    };
    donate *don=new donate[100];
    int n;
    cout<<"Enter the number of donors: ";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Enter the name of donor "<<i+1<<": ";
        getline(cin,don[i].name);
        cout<<"Enter the amount donated by "<<don[i].name<<": ";
        cin>>don[i].money;
        cin.ignore();
    }
    double total=0;
    for(int i=0;i<n;i++){
        total+=don[i].money;
    }
    cout<<"Total amount donated: "<<total<<endl;
    delete[] don;
    return 0;
    
}