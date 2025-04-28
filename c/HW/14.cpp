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


// This problem is based on the Dynarray you wrote in Homework 4 Problem 3. Before adding anything new to it, your Dynarray should meet all the requirements in that problem first.

// In this task, your Dynarray should support the following new things.

// Type alias members
// The standard library containers have many type alias members for the purpose of supporting generic types. For example, std::vector<T>::value_type is T, std::vector<T>::size_type is std::size_t, std::vector<T>::pointer is T *.

// As an exercise, do the same thing in your Dynarray. You need to define the following type alias members, all of which should be public:

// type alias member	definition
// Dynarray::size_type	std::size_t
// Dynarray::value_type	int
// Dynarray::pointer	int *
// Dynarray::reference	int &
// Dynarray::const_pointer	const int *
// Dynarray::const_reference	const int &
// Moreover, we will eventually make this Dynarray a class template Dynarray<T> that can store any types of data, not only ints. This will be in Homework 7 or 8, depending on the lecture schedule. To make your work easier by then, you'd better make full use of the type alias members you have defined. For example, change new int[n] to new value_type[n], change int & to reference, and change (const int *begin, const int *end) to (const_pointer begin, const_pointer end), etc. By the time we make this a class template, you will just have to modify very few things.

// Subscript operator
// The Dynarray should support the subscript operator, so that we can use a[i] instead of a.at(i) to access the i-th element.

// Let a be an object of type Dynarray or const Dynarray. The behavior of a[i] should be exactly the same as a.at(i), except that the subscript operator does not perform bounds checking. That is, no exception should be thrown if i >= a.size().

// Relational operators
// The Dynarray should support the six relational operators: <, <=, >, >=, == and !=. These operators perform lexicographical comparison of two Dynarrays.

// Lexicographical comparison is an operation with the following properties:

// Two ranges are compared element by element.
// The first mismatching element defines which range is lexicographically less or greater than the other.
// If one range is a prefix of another, the shorter range is lexicographically less than the other.
// If two ranges have equivalent elements and are of the same length, then the ranges are lexicographically equal.
// An empty range is lexicographically less than any non-empty range.
// Two empty ranges are lexicographically equal.
// Since we use C++17, you still have to define all six of them. It is often good practice to implement operator< and operator== first, and define the rest in terms of them. Moreover, you are not allowed to write loops or recursions in these six functions. Go through this page and find the appropriate standard library algorithms.

// Note that in homework 7 or 8, we will make this Dynarray a class template Dynarray<T>, and we should always minimize the requirements on unknown types when we do generic programming. Since C++17 does not have compiler-generated comparison operators, we suggest you making your implementation depend only upon the operator< and operator== of the element type.

// You are free to choose to define them as either members or non-members. If you choose to define them as non-members, you should make them static functions. If you choose to define them as members, you should make them private and provide public non-member functions that call them.