#include<iostream>
#include<vector>
using namespace std;
int count_lowercase(const std::string &str) { // `str` is a reference-to-`const`.
    int cnt = 0;
    for (char c : str)
    if (std::islower(c))
    ++cnt;
    return cnt;
    }
int main(){
    std::string a = "rkjehtnue34DSFC", b = "kdjctvhenuerUNFREUC";
    int res1 = count_lowercase(a); // OK.
    int res2 = count_lowercase(a + b); // OK.
    int res3 = count_lowercase("hello"); // OK.
    cout << "res1 = " << res1 << endl;
    cout << "res2 = " << res2 << endl;
    cout << "res3 = " << res3 << endl;
    std::vector<int> v{2, 3, 5, 7}; // A vector of `int`s,
    // whose elements are {2, 3, 5, 7}.
    std::vector<int> v2 = {2, 3, 5, 7}; // Equivalent to ↑
    std::vector<std::string> vs{"hello", "world"}; // A vector of strings,
    // whose elements are {"hello", "world"}.
    std::vector<std::string> vs2 = {"hello", "world"}; // Equivalent to ↑
    std::vector<int> v3(10); // A vector of ten `int`s, all initialized to 0.
    std::vector<int> v4(10, 42); // A vector of ten `int`s, all initialized to 42.
    vector<double> v56{2.3,4,5,6.7};

    return 0;

        
}