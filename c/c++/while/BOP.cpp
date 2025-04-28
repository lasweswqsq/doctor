#include<iostream>
using namespace std;
//#define strsize 50
#include<vector>
struct bop{
    string fullname;
    string title;
    string bopname;
    int preference;
};
int main(){
    vector<bop> bops;
    bop b1;
    b1.fullname="John Doe";
    b1.title="Doctor";
    b1.bopname="BOP1";
    b1.preference=1;
    bops.push_back(b1);
    bop b2;
    b2.fullname="Jane Doe";
    b2.title="Doctor";
    b2.bopname="BOP2";
    b2.preference=2;
    bops.push_back(b2);
    bop b3;
    b3.fullname="Bob Smith";
    b3.title="Nurse";
    b3.bopname="BOP3";
    b3.preference=3;
    bops.push_back(b3);
    cout<<"a: Display by name.\n b: Display by title.\n c: Display by BOP name.\n d: Display by preference.\n q:quit";
    char choice = 'a';
    do{
        cin>>choice;
        switch(choice){
            case 'a' : cout<<bops[0].fullname<<"\n"<<bops[1].fullname<<"\n"<<bops[2].fullname<<"\n";break;
            case 'b' : cout<<bops[0].title<<"\n"<<bops[1].title<<"\n"<<bops[2].title<<"\n";break;
            case 'c' : cout<<bops[0].bopname<<"\n"<<bops[1].bopname<<"\n"<<bops[2].bopname<<"\n";break;
            case 'd' : cout<<bops[0].preference<<"\n"<<bops[1].preference<<"\n"<<bops[2].preference<<"\n";break;
            case 'q' : break;
            default : cout<<"Invalid choice.\n";
        }
    }while(choice!='q');

}