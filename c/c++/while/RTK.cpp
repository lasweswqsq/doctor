#include<iostream>
using namespace std;
int main(){
    double donation[10];
    int num;
    cout<<"Enter the number of donations: ";
    cin>>num;
    cout<<"Enter the donations: "<<endl;
    double total = 0;
    for(int i=0;i<num;i++){
        cin>>donation[i];
        total += donation[i];
    }int big = 0;
    for(int i=0;i<num;i++){
        if(donation[i]>total/num){
            big++;  
        }
    }
    cout<<"The number of donations that are greater than the average is: "<<big<<endl;
    return 0;
    
}