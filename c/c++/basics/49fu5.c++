#include <iostream>
#include <string>
#include <cctype>

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
    return 0;
}