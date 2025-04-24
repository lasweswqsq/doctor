#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

int main(){
    std::string str;
    std::cin >> str;
    int lower_cnt = 0;
    for (char c : str){
        if (std::islower(c)){
            ++lower_cnt;
        }
    }
    for (char &c : str)
    c = std::toupper(c);

    std::cout << "There are " << lower_cnt << " lowercase letters in total.\n";
    std::cout << "The modified string is: " << str << std::endl;

    double x;
    std::cin >> x;
    double y = std::sqrt(x);
    double z = std::pow(x, 2);
    std::cout << "The square root of " << x << " is " << y << std::endl;
    std::cout<<z<<std::endl;

    return 0;
}