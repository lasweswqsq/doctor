#include<iostream>
using namespace std;
class Student {
    private:
        string name;
        string id;
        int entranceYear;
    public:
        Student(const string &name, const string &id) :
        name(name), id(id), entranceYear(stoi(id.substr(0,4))) {}
            
        void setName(const string &newName) {
        name = newName;
        }   
        void printInfo(Student s) const {
        cout << "I am " << this->name << ", id " << this->id << ", entrance year: " << this->entranceYear << std::endl;
        cout << "You are " << s.name << ", id " << s.id << ", entrance year: " << s.entranceYear << std::endl;
        }
        bool graduated(int year) const {
        return year - entranceYear >= 4;
        }
        // void foo() const {
        //     name += 'a'; // Error: `name` is `const std::string` in a const member
        //     // function. It cannot be modified.
        // }
        bool valid() const {
            return id.substr(0,4) == to_string(entranceYear).substr(0,4);
        } // verifies whether the leading four digits in `id`
        // are// is equal to `entranceYear`.

    };
int main() {
    Student s1 = {"John", "20101010"};
    Student s2 = {"Mary", "20111212"};
    s1.printInfo(s2);
    s1.setName("Jane");
    s1.printInfo(s2);
    if (s1.graduated(2014)) {
    std::cout << "Congratulations, you have graduated!" << std::endl;
    }
    if (s1.valid()){
        std::cout << "Valid ID" << std::endl;
    }
    else{
        std::cout << "Invalid ID" << std::endl;
    }
    if (s2.valid()){
        std::cout << "Valid ID" << std::endl;
    }
    else{
        std::cout << "Invalid ID" << std::endl;
    }
    //s1.foo(); // Error: `foo` is not defined
    return 0;
}