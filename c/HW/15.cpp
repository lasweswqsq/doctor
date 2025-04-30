#include <iostream>
#include <stdexcept>
#include <algorithm>

class Dynarray;

std::ostream& operator<<(std::ostream& stream, const Dynarray& arr) noexcept;

class Dynarray {
public:
    using size_type = std::size_t;
    using value_type = int;
    using pointer = int*;
    using reference = int&;
    using const_pointer = const int*;
    using const_reference = const int&;
private:
    size_type m_length;
    value_type *m_storage;
public:
    Dynarray() noexcept : m_length(0), m_storage(nullptr) {}
    explicit Dynarray(size_type size) : m_length(size), m_storage(new value_type[size]) {
        std::fill_n(m_storage, m_length, 0);
    }
    Dynarray(size_type size, const_reference init) : m_length(size), m_storage(new value_type[size]) {
        std::fill_n(m_storage, m_length, init);
    }
    Dynarray(const_pointer begin, const_pointer end) : m_length(end - begin), m_storage(new value_type[m_length]) {
        std::copy(begin, end, m_storage);
    }
    Dynarray(const Dynarray& other) : m_length(other.m_length), m_storage(new value_type[m_length]) {
        std::copy(other.m_storage, other.m_storage + m_length, m_storage);
    }
    Dynarray(Dynarray&& other) noexcept : m_length(other.m_length), m_storage(other.m_storage) {
        other.m_length = 0;
        other.m_storage = nullptr;
    }
    Dynarray& operator=(const Dynarray& other) {
        if (this == &other){
            return *this;
        } 
        delete[] m_storage;
        m_length = other.m_length;
        m_storage = new value_type[m_length];
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
    ~Dynarray() noexcept {
        delete[] m_storage;
    }
    size_type size() const noexcept {
        return m_length;
    }
    bool empty() const noexcept {
        return m_length == 0;
    }
    reference at(size_type pos) {
        if (pos >= m_length) {
            throw std::out_of_range("Dynarray index out of range");
        }
        return m_storage[pos];
    }
    const_reference at(size_type pos) const {
        if (pos >= m_length) {
            throw std::out_of_range("Dynarray index out of range");
        }
        return m_storage[pos];
    }
    reference operator[](size_type pos) noexcept {
        return m_storage[pos];
    }
    const_reference operator[](size_type pos) const noexcept {
        return m_storage[pos];
    }
    bool operator<(const Dynarray& other) const noexcept {
        return std::lexicographical_compare(m_storage, m_storage + m_length, other.m_storage, other.m_storage + other.m_length);
    }
    bool operator==(const Dynarray& other) const noexcept {
        return std::equal(m_storage, m_storage + m_length, other.m_storage, other.m_storage + other.m_length);
    }
    bool operator!=(const Dynarray& other) const noexcept {
        return !(*this == other);
    }
    bool operator>(const Dynarray& other) const noexcept {
        return other < *this;
    }
    bool operator<=(const Dynarray& other) const noexcept {
        return !(other < *this);
    }
    bool operator>=(const Dynarray& other) const noexcept {
        return !(*this < other);
    }
    friend std::ostream& operator<<(std::ostream& stream, const Dynarray& arr) noexcept;
};

std::ostream& operator<<(std::ostream& stream, const Dynarray& arr) noexcept {
    stream << "[";
    if (!arr.empty()) {
        stream << arr[0];
        for (Dynarray::size_type i = 1; i < arr.size(); ++i) {
            stream << ", " << arr[i];
        }
    }
    return stream << "]";
}



//     Dynarray() noexcept : length(0), values(nullptr) {}
//     explicit Dynarray(size_type size) : length(size), values(allocate(size)) {
//         std::fill_n(values, length, 0);  
//     }
//     Dynarray(size_type size, const_reference init) : length(size), values(allocate(size)) {
//         std::fill_n(values, length, init);
//     }

//     // 区间构造函数
//     Dynarray(const_pointer begin, const_pointer end) : length(end - begin), values(allocate(length)) {
//         std::copy(begin, end, values);
//     }

//     // 拷贝构造函数
//     Dynarray(const Dynarray& other) : length(other.length), values(allocate(length)) {
//         std::copy(other.values, other.values + length, values);
//     }

//     // 移动构造函数
//     Dynarray(Dynarray&& other) noexcept : length(other.length), values(other.values) {
//         other.length = 0;
//         other.values = nullptr;
//     }

//     // 拷贝赋值运算符
//     Dynarray& operator=(const Dynarray& other) {
//         if (this != &other) {
//             Dynarray temp(other);  // 异常安全实现
//             swap(temp);
//         }
//         return *this;
//     }

//     // 移动赋值运算符
//     Dynarray& operator=(Dynarray&& other) noexcept {
//         if (this != &other) {
//             delete[] values;       // 释放原有资源
//             length = other.length;
//             values = other.values;
//             other.length = 0;
//             other.values = nullptr;
//         }
//         return *this;
//     }

//     // 析构函数
//     ~Dynarray() noexcept { 
//         delete[] values;          // 使用 delete[] 释放数组
//         values = nullptr;
//         length = 0;
//     }

//     // 交换操作
//     void swap(Dynarray& other) noexcept {
//         std::swap(length, other.length);
//         std::swap(values, other.values);
//     }

//     // 容量查询
//     size_type size() const noexcept { return length; }
//     bool empty() const noexcept { return length == 0; }

//     // 元素访问
//     reference at(size_type pos) {
//         if (pos >= length) throw std::out_of_range("Dynarray index out of range");
//         return values[pos];
//     }

//     const_reference at(size_type pos) const {
//         if (pos >= length) throw std::out_of_range("Dynarray index out of range");
//         return values[pos];
//     }

//     reference operator[](size_type pos) noexcept { return values[pos]; }
//     const_reference operator[](size_type pos) const noexcept { return values[pos]; }

//     // 比较运算符
//     bool operator<(const Dynarray& other) const noexcept {
//         return std::lexicographical_compare(values, values + length, 
//                                          other.values, other.values + other.length);
//     }

//     bool operator==(const Dynarray& other) const noexcept {
//         return length == other.length && 
//                std::equal(values, values + length, other.values);
//     }

//     bool operator!=(const Dynarray& other) const noexcept { return !(*this == other); }
//     bool operator>(const Dynarray& other) const noexcept { return other < *this; }
//     bool operator<=(const Dynarray& other) const noexcept { return !(other < *this); }
//     bool operator>=(const Dynarray& other) const noexcept { return !(*this < other); }

//     friend std::ostream& operator<<(std::ostream& stream, const Dynarray& arr) noexcept;
// };

// // 输出运算符
// std::ostream& operator<<(std::ostream& stream, const Dynarray& arr) noexcept {
//     stream << "[";
//     if (!arr.empty()) {
//         stream << arr[0];
//         for (Dynarray::size_type i = 1; i < arr.size(); ++i) {
//             stream << ", " << arr[i];
//         }
//     }
//     return stream << "]";
// }
