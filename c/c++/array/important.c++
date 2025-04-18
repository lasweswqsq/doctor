#include <iostream>
using namespace std;
class DynArray {
    private:
        int* arr;
        int size;
    public:
        DynArray(int n) {
            size = n;
            arr = new int[size];
        }
        ~DynArray() {
            delete[] arr;
        }
        int& at(int i) {
            return arr[i];
        }
        DynArray &operator=(const DynArray &other) {
            int *new_data = new int[other.size()];
            for (std::size_t i = 0; i != other.size(); ++i)
            new_data[i] = other.at(i);
            delete[] arr;
            arr = new_data;
            size = other.size();
            return *this;
        }
            
};

int main() {
    // int n; std::cin >> n;
    // DynArray arr(n); // `n` is runtime determined
    //                 // `arr` should have allocated memory for `n` `int`s now.
    // for (int i = 0; i != n; ++i) {
    //     int x; std::cin >> x;
    //     arr.at(i) = x * x; // subscript, looks as if `arr[i] = x * x`
    // }
    // cout << "Array elements: ";
    // for (int i = 0; i != n; ++i) {
    //     cout << arr.at(i) << " ";
    // }
    cout << endl;
    DynArray a(3);
    a.at(0) = 1;
    a.at(1) = 2;
    a.at(2) = 3;
    DynArray b = *a;
    a.at(0) = 4;
    cout << a.at(0) << " " << a.at(1) << " " << a.at(2) << endl;
    cout << b.at(0) << " " << b.at(1) << " " << b.at(2) << endl;


    // `arr` should have deallocated memory now.
    return 0;
}