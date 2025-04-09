#include <iostream>
using namespace std;

int main() {
    class Dynarray {
        int *m_storage;
        std::size_t m_length;
        public:
        Dynarray(std::size_t n) : m_storage(new int[n]{}), m_length(n) {}
    };
    Dynarray arr(10);
}
        