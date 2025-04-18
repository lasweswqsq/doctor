#include<iostream>

class Dynarray{
    private:
        int *m_storage;
        std::size_t m_length;
    public:
        Dynarray(): m_storage(nullptr), m_length(0) {}
        explicit Dynarray(std::size_t n): m_storage(new int[n]), m_length(n) {
            std::fill(m_storage, m_storage + m_length, 0);
        }
        Dynarray(std::size_t n, int x): m_storage(new int[n]), m_length(n) {
            std::fill(m_storage, m_storage + m_length, x);
        }
        Dynarray(const int *begin, const int *end): m_storage(new int[end - begin]), m_length(end - begin) {
            std::copy(begin, end, m_storage);
        }
        Dynarray(const Dynarray& other): m_storage(new int[other.m_length]), m_length(other.m_length) {
            std::copy(other.m_storage, other.m_storage + m_length, m_storage);
        }
        Dynarray(Dynarray&& other) noexcept: m_storage(other.m_storage), m_length(other.m_length) {
            other.m_storage = nullptr;
            other.m_length = 0;
        }
        Dynarray& operator=(const Dynarray& other) {
            if (this == &other){
                return *this;
            } 
            delete[] m_storage;
            m_length = other.m_length;
            m_storage = new int[m_length];
            std::copy(other.m_storage, other.m_storage + m_length, m_storage);
            return *this;
        }
        Dynarray& operator=(Dynarray&& other) noexcept {
            if (this == &other){
                return *this;
            } 
            delete[] m_storage;
            m_storage = other.m_storage;
            m_length = other.m_length;
            other.m_storage = nullptr;
            other.m_length = 0;
            return *this;
        }
        int& operator[](std::size_t i) {
            return m_storage[i];
        }
        const int& operator[](std::size_t i) const {
            return m_storage[i];
        }
        size_t size() const {
            return m_length;
        }
        bool empty() const {
            if (m_length == 0){
                return true;
            } 
            else {
                return false;
            } 
        }
        int& at(std::size_t n) {
            if (n >= m_length){
                throw std::out_of_range{"Dynarray index out of range!"};
            } 
            return m_storage[n];
        }
        const int& at(std::size_t n) const {
            if (n >= m_length){
                throw std::out_of_range{"Dynarray index out of range!"};
            } 
            return m_storage[n];
        }
        ~Dynarray() {
            delete[] m_storage;
        }
    
};


// Basic information
// Let a be an object of type const Dynarray. The following operations should be supported:

// a.size()
// Returns the length of the "array", that is, the number of elements in a. It should be of type std::size_t, which is defined in <cstddef>.

// a.empty()
// Returns a bool value indicating whether the Dynarray is empty or not. A Dynarray is said to be empty if its length is zero.

// Element access
// Let a be an object of type Dynarray and ca be an object of type const Dynarray. Let n be a non-negative integer. The following operations should be supported:

// a.at(n)
// Returns a reference to the element indexed n in a. It is both readable and modifiable since a is not const. For example:

// a.at(n) = 42;
// std::cout << a.at(n) << std::endl;
// ca.at(n)
// Returns a reference-to-const to the element indexed n in ca. It should be read-only, since ca is const. For example:

// std::cout << ca.at(n) << std::endl; // OK
// ca.at(n) = 42; // This should lead to a compile-error.
// Moreover, to keep in consistent with the behaviors of the standard library containers, Dynarray::at should do bounds-checking. If n is not in the range [0, a.size()), you need to throw an exception std::out_of_range. To throw this exception, write

// throw std::out_of_range{"Dynarray index out of range!"};
// The exception class std::out_of_range is defined in the standard library file <stdexcept>.