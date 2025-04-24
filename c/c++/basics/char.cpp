#include <iostream>
using namespace std;

int main() {
    long long population;
    long long country_population;
    cout<<"Enter population: ";
    cin>>population;
    cout<<"Enter country population: ";
    cin>>country_population;
    double percentage = 1.0 * country_population / population;
    cout<<percentage;
    return 0;
}