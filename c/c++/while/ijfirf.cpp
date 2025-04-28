#include<iostream>
#include<cctype>
using namespace std;
int main(){
    char ch;
    cin.get(ch);
    while(cin.fail() == false){
        if(ch!='@'){
            if(isupper(ch)){
                cout<<char(ch+32);
            }
            else if(islower(ch)){
                cout<<char(ch-32);
            }
            else{
                cout<<ch;
            }
        }
        else{
            break;
        }
        cin.get(ch);
    }
}