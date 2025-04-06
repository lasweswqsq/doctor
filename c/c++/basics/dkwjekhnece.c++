#include<iostream>
//using namespace std;
int main(){
    std::cout<<"Hello World\n";
    int ival = 42;
    int x = ival; // `x` is another variable.
    ++x; // This has nothing to do with `ival`.
    std::cout << ival << '\n'; // 42
    int &ri = ival; // `ri` is a reference that refers to `ival`.
    ++ri; // This modification is performed on `ival`.
    std::cout << ival << '\n'; // 43
    //ival = 42;
    double dval = 3.146567567565;
    std::string s = std::to_string(ival) + std::to_string(dval);
    std::cout << s << '\n'; // Possible output: 423.140000
    int sw = std::stoi(s); // Possible output: 42
    std::cout << sw << '\n'; // Possible output: 42
    std::string str = "Hello";
    std::cout << str << '\n'; // Possible output: Hello
    int *pr = &ival; // `pr` is a pointer that points to `ival`.
    std::cout << *pr << '\n'; // Possible output: 43
    int *jd =&ri; // `jd` is another pointer that points to `ival`.
    ival++;
    std::cout << *jd << '\n'; // Possible output: 43
    int *ptr = nullptr; // `ptr` is a null pointer.
    std::cout << ptr << '\n'; // Possible output: 
    return 0;
}