#include<iostream>
using namespace std;
int main(){
    int up = 89;
    int *up_ptr = &up;
    cout<<"The value of up is "<<up<<endl;
    cout<<"The address of up is "<<&up<<endl;
    cout<<"The value of up_ptr is "<<up_ptr<<endl;
    cout<<"The address of up_ptr is "<<&up_ptr<<endl;
    *up_ptr = *up_ptr - 1;
    cout<<"The value of up after decrement is "<<up<<endl;
    *up_ptr = 100;
    cout<<"The value of up after assignment is "<<up<<endl;

    int nights = 1000;
    int *ed_ptr = new int;
    *ed_ptr = nights + 1;
    cout<<"The value of nights is "<<nights<<endl;
    cout<<"The address of ed_ptr is "<<ed_ptr<<endl;
    cout<<"The address of ed_ptr is "<<&ed_ptr<<endl;
    cout<<"The value of ed_ptr is "<<*ed_ptr<<endl;
    free(ed_ptr);

    short djfh = new short[100];
    delete [] djfh;
    return 0;
}