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
};

int main() {
    int n; std::cin >> n;
    DynArray arr(n); // `n` is runtime determined
                    // `arr` should have allocated memory for `n` `int`s now.
    for (int i = 0; i != n; ++i) {
        int x; std::cin >> x;
        arr.at(i) = x * x; // subscript, looks as if `arr[i] = x * x`
    }
    cout << "Array elements: ";
    for (int i = 0; i != n; ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;
    // `arr` should have deallocated memory now.
    return 0;
}