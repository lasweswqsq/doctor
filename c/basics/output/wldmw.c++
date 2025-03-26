#include<iostream>
int main(){
    std::string str = "Hello world";
// equivalent: std::string str("Hello world");
// equivalent: std::string str{"Hello world"}; (modern)
std::cout << str << std::endl;
std::string s1(7, 'a');
std::cout << s1 << std::endl; // aaaaaaa
std::string s2 = s1; // s2 is a copy of s1
std::cout << s2 << std::endl; // aaaaaaa
std::string s; // "" (empty string)
//std::string str = "Hello world";
std::cout << str.size() << std::endl;
}