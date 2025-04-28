#include<iostream>
using namespace std;
int main(){
    string word;
    getline(cin,word);
    cout<<sizeof(word)<<endl;
    for (long long i=word.size()-1;i>=0;i--){
        cout<<word[i];
    }
    return 0;
}