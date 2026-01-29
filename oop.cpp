#include <iostream>
#include <string>
#include <vector>

class Person{
    protected:
    std::string first;
    std::string last;
    
    
    public:
    Person(std::string first, std::string last): first(first), last(last) {}
    Person() = default;
    
    void setFirstName(std::string first){
        this -> first = first;
    }

    void setLastName(std::string last){
        this -> last = last;
    }

    std::string getName(){
        return first + " " + last;
    }

    void printFullName(){
        std::cout << first + " " + last << "\n";
    }

    virtual void printInfo(){
        std::cout << "First Name: " << first << "\n" << "Last Name: " << last << "\n";
    }

    static void PrintPeople(std::vector<Person*> people){
        for(auto person : people){
            person->printInfo();
        }
    }
};

class Employee: public Person{

    std::string department;

    public:
    Employee(std::string first, std::string last, std::string department): Person(first, last), department(department) {}
    Employee() = default;

    void setDepartment(std::string department){
        this -> department = department;
    }
    std::string getDepartment(){
        return department;
    }
    void printInfo() override {
        std::cout << "First Name: " << first << "\n" << "Last Name: " << last << "\n" << "Department: " << department << "\n";
    }
    
};

int main(){
    
    std::vector<Person*> people;

    Person p("Alice", "Smith");
    Employee e("John", "Doe", "Engineering");

    people.push_back(&p);
    people.push_back(&e);
    
    Person::PrintPeople(people);
}