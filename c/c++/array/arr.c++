#include <iostream>
using namespace std;

int main(){
    int yams[3];
    yams[0] = 7;
    short int beans[2] = {4, 5};
    cout<<"Total yams: "<<yams[0]<<endl;
    cout<<"Total beans: "<<beans[0]+beans[1]<<endl;
    cout<<"\nSize of yams array: "<<sizeof yams;
    cout<<"\nSize of beans array: "<<sizeof beans;
    short thins[] = {1, 2, 3, 4, 5};
    cout<<"\nSize of thins array: "<<sizeof thins<<endl;
    char letters[] = "Hello World";
    cout<<"\nSize of letters array: "<<sizeof letters<<endl;
    for (int i = 0; i < sizeof letters; i++) {
        cout<<letters[i];
    }
    cout<<"\n";
    return 0;
}