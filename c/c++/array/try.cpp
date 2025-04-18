#include <iostream>
using namespace std;
int main() {
    class Dynarray {
        int *m_storage;
        std::size_t m_length;
        public:
        Dynarray(const Dynarray &other) // copy constructor
        : m_storage(new int[other.m_length]), m_length(other.m_length) {
        for (std::size_t i = 0; i != m_length; ++i)
        m_storage[i] = other.m_storage[i];
        }
        Dynarray(Dynarray &&other) noexcept // move constructor
        : m_storage(other.m_storage), m_length(other.m_length) {
        other.m_storage = nullptr;
        other.m_length = 0;
        }
        };
    Dynarray a(10);
    Dynarray b(std::move(a)); // move constructor called here
    return 0;
        
}
