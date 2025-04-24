#include<iostream>
#include<string>

using namespace std;
int main()
{
    char first[] = "jdwhfjwefh jeiei//e'd;e";
    string second = "jdfhwefwewwiehf";
    cout<<first[5]<<endl;
    cout<<second[5]<<endl;
    cout<<sizeof(first)<<endl;
    cout<<sizeof(second)<<endl;
    for (string::size_type i = 0; i < second.length(); i++){
        cout<<second[i];
    }
    return 0;
}
