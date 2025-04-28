#include<iostream>

using namespace std;    
int main(){
    int sell[3][12];
    for(int i=0;i<3;i++){
        for(int j=0;j<12;j++){
            cout<<"Enter the selling price for month "<<j+1<<" of year "<<i+1<<": ";
            cin>>sell[i][j];
        }
    }
    for (int i =0;i<3;i++){
        int total =0;
        for(int j=0;j<12;j++){
            total+=sell[i][j];
        }
        cout<<"Total selling price for year is "<<total<<endl;
    }
}