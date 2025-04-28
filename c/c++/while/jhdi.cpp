#include<iostream>
using namespace std;
int main(){
    char ch;
    cin.get(ch);
    int count = 0;
    while(cin.fail() == false){
        cout<<ch;
        ++count;
        cin.get(ch);
    }
    cout<<"Total characters read: "<<count<<endl;
    return 0;
}