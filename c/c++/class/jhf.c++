#include<iostream>
using namespace std;
int main(){
    struct A {
        A() {
        std::cout << 'c';
        }
        ~A() {
        std::cout << 'd';
        }
        };
    A a;
    return 0;
        
        

        
}