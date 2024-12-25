#include <iostream>

class University {
public:
    void setName(std::string name) {
        this->name = name;
    }

    std::string getName() {
        return name;
    }

private:
    std::string name;
};

class Department {
public:
    void setUniversity(University university) {
        this->university = university;
    }

    University getUniversity() {
        return university;
    }

private:
    University university;
};

int main() {
    University university;
    university.setName("Harvard");

    Department department;
    department.setUniversity(university);

    std::cout << "Department is part of " << department.getUniversity().getName() << " University." << std::endl;

    return 0;
}
